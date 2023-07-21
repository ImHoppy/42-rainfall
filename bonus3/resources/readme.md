# Bonus 3

Ici le programme ouvre le fichier .pass sur le dernier utilisateur "end"
Il nous est donc impossible de l'afficher avec gdb a cause de l'UID et des droits sur ce fichier.
On remarque qu'un atoi est utilise sur notre parametre av[1] et son retour est utilise pour positionner un '\0'
sur le enieme charactere du buffer utilise rempli par fread pour lire le fichier .pass (la enieme position etant la valeur du retour d'atoi.
Si cette comparaison (strcmp) nous renvoi 0, execl("/bin/sh","sh",0); sera executer en tant que l'utilisateur end.

On comprend donc qu'il faut passer une chaine vide en parametre.

```
bonus3@RainFall:~$ ./bonus3 ""
$ id
uid=2013(bonus3) gid=2013(bonus3) euid=2014(end) egid=100(users) groups=2014(end),100(users),2013(bonus3)
```
