#include "ioUtiles.h"

// fgets without reading newline character
static char *read_line(char *str, int n, FILE *stream)
{
	char *ans = fgets(str, n, stream);
	if (ans == NULL)
		return NULL;
	int newlineIndex = strcspn(str, "\n");
	str[newlineIndex] = 0;
	return str;
}


static int read_int(int *num)
{
	scanf("%d", num);
	char c = getchar(); // remove newline from stdin
	return *num;
}