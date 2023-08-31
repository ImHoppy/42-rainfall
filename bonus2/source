void greetuser(void)

{
  uchar uStack_4c [19];

  if (language == 1) {
    uStack_4c[0] = 'H';
    uStack_4c[1] = 'y';
    uStack_4c[2] = 'v';
    uStack_4c[3] = 0xc3;
    uStack_4c[4] = 0xa4;
    uStack_4c[5] = 0xc3;
    uStack_4c[6] = 0xa4;
    uStack_4c[7] = ' ';
    uStack_4c[8] = 'p';
    uStack_4c[9] = 0xc3;
    uStack_4c[10] = 0xa4;
    uStack_4c[11] = 'i';
    uStack_4c[12] = 'v';
    uStack_4c[13] = 0xc3;
    uStack_4c[14] = 0xa4;
    uStack_4c[15] = 0xc3;
    uStack_4c[16] = 0xa4;
    uStack_4c[17] = ' ';
    uStack_4c[18] = '\0';
  }
  else if (language == 2) {
    uStack_4c[0] = 'G';
    uStack_4c[1] = 'o';
    uStack_4c[2] = 'e';
    uStack_4c[3] = 'd';
    uStack_4c[4] = 'e';
    uStack_4c[5] = 'm';
    uStack_4c[6] = 'i';
    uStack_4c[7] = 'd';
    uStack_4c[8] = 'd';
    uStack_4c[9] = 'a';
    uStack_4c[10] = 'g';
    uStack_4c[11] = '!';
    uStack_4c[12] = ' ';
    uStack_4c[13] = '\0';
  }
  else if (language == 0) {
    uStack_4c[0] = 'H';
    uStack_4c[1] = 'e';
    uStack_4c[2] = 'l';
    uStack_4c[3] = 'l';
    uStack_4c[4] = 'o';
    uStack_4c[5] = ' ';
    uStack_4c[6] = '\0';
  }
  strcat((char *)uStack_4c,&stack0x00000004);
  puts((char *)uStack_4c);
  return;
}

int main(int ac,char **av)

{
  int r_memcmp;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  char buffer_1 [40];
  char buffer_2 [36];
  char *current_lang;

  bVar4 = 0;
  if (ac == 3) {
    puVar2 = (undefined4 *)buffer_1;
    for (r_memcmp = 0x13; r_memcmp != 0; r_memcmp = r_memcmp + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    strncpy(buffer_1,av[1],40);
    strncpy(buffer_2,av[2],32);
    current_lang = getenv("LANG");
    if (current_lang != (char *)0x0) {
                    /* fi */
      r_memcmp = memcmp(current_lang,&DAT_0804873d,2);
      if (r_memcmp == 0) {
        language = 1;
      }
      else {
                    /* nl */
        r_memcmp = memcmp(current_lang,&DAT_08048740,2);
        if (r_memcmp == 0) {
          language = 2;
        }
      }
    }
    puVar2 = (undefined4 *)buffer_1;
    puVar3 = (undefined4 *)&stack0xffffff50;
    for (r_memcmp = 19; r_memcmp != 0; r_memcmp = r_memcmp + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + (uint)bVar4 * -2 + 1;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
    r_memcmp = greetuser();
  }
  else {
    r_memcmp = 1;
  }
  return r_memcmp;
}
