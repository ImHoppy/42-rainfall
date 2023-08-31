#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int ac,char **av)
{
	int ret;
	int i;
	char buffer[64];
	char buffer2[66];
	FILE *file_pass;

	file_pass = fopen("/home/user/end/.pass","r");
	bzero(buffer, 33);
	if ((file_pass == (FILE *)0x0) || (ac != 2)) {
		ret = -1;
	}
	else {
		fread(buffer,1,66,file_pass);
		i = atoi(av[1]);
		buffer[i] = '\0';
		fread(buffer2,1,65,file_pass);
		fclose(file_pass);
		i = strcmp(buffer,av[1]);
		if (i == 0) {
			execl("/bin/sh", "sh", 0);
		}
		else {
			puts(buffer2);
		}
		ret = 0;
	}
	return ret;
}
