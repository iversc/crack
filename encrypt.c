#include <stdio.h>

#define _XOPEN_SOURCE
#include <unistd.h>

char *crypt(const char *key, const char *salt);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("**Error: Invalid number of arguments entered.\n");
		printf("\tPlease enter only one argument.\n");
		return 1;
	}

	printf("%s\n", crypt(argv[1], "50"));

	return 0;
}
