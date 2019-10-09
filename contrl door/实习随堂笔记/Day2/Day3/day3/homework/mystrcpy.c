#include <stdio.h>
#include <string.h>

char *mystrcpy(char *dest, char *src, int size);
int main()
{
	char dest[20] = {0};
	char src[] = "hello world";
	char *p = mystrcpy(dest, src, sizeof(dest));
	if(NULL == p)
	{
		return -1;
	}
	puts(p);
	return 0;
}

char *mystrcpy(char *dest, char *src, int size)
{
	if(NULL == dest || NULL == src)
	{
		puts("NULL pointer error.");
		return NULL;
	}
	if(strlen(src) + 1 > size)
	{
		puts("memory size smaller");
		return NULL;
	}
	char *p = dest;
	while(*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = 0;
	return dest;
}
