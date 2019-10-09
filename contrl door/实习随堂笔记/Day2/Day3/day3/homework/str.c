#include <stdio.h>

int main()
{
	char str[] = "how are you?";
	char *p = str;
	while(*p)
	{
		putchar(*p);
		p++;
	}
	putchar('\n');
	return 0;
}
