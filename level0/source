#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int ac,char **av)
{
	int ret;
	char *str;
	__uid_t uid;
	__gid_t gid;

	ret = atoi(av[1]);
	if (ret == 423) {
		str = strdup("/bin/sh");
		gid = getegid();
		uid = geteuid();
		setresgid(gid,gid,gid);
		setresuid(uid,uid,uid);
		execv("/bin/sh",&str);
	}
	else {
		fwrite("No !\n", 1, 5, (FILE *)stderr);
	}
	return 0;
}
