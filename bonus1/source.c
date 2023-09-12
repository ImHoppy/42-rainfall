
int main(int ac,char **av)

{
  int return_value;
  char buf;
  int av1;

  av1 = atoi(av[1]);
  if (av1 < 10) {
    memcpy(&buf,av[2],av1 * 4);
    if (av1 == 0x574f4c46) {
      execl("/bin/sh","sh",0);
    }
    return_value = 0;
  }
  else {
    return_value = 1;
  }
  return return_value;
}
