#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void m(void)
{
	puts("Nope");
	return;
}

void n(void)
{
	system("/bin/cat /home/user/level7/.pass");
	return;
}

void main(int ac,char **av)

{
	char *dest;
	void (**fun_ptr)();

	dest = (char *)malloc(64);
	fun_ptr = malloc(sizeof(*fun_ptr) * 4);
	*fun_ptr = m;
	strcpy(dest, av[1]);
	(**fun_ptr)();
	return;
}
