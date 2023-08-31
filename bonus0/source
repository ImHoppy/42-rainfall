
//original name of readLine was p
void readLine(char *dst,char *prefix)
{
	char *line;
	char buf[4104];

	puts(prefix);
	read(0, buf, 4096);
	line = strchr(buf, 10);
	*line = '\0';
	strncpy(dst, buf, 20);
	return;
}

void pp(char *buffer)
{
	unsigned int n;
	char buffer1[20];
	char buffer2[20];

	readLine(buffer1, " - ");
	readLine(buffer2, " - ");
	strcpy(buffer, buffer1);
	n = strlen(buffer);
	buffer[n] = 32;
	strcat(buffer, buffer2);
	return;
}


int main(void)
{
	char buffer [54];

	pp(buffer);
	puts(buffer);
	return 0;
}
