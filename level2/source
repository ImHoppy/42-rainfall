#include <stdio.h>
#include <string.h>

void p(void)
{
	unsigned int unaff_retaddr;
	char buf[76];

	fflush(stdout);
	gets(buf);
	if ((unaff_retaddr & 0xb0000000) == 0xb0000000) {
		printf("(%p)\n", unaff_retaddr);
		_exit(1);
	}
	puts(buf);
	strdup(buf);
	return;
}

void main(void)
{
	p();
	return;
}
