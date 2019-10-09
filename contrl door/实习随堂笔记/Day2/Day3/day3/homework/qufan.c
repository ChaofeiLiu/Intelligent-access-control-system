#include <stdio.h>

int main()
{
	char c = 7;
	c = ~c;
	c = 4 ^ 2;
	int i = 0;
	for(i = 7; i >= 0; i--)
	{
		printf("%d", c >> i & 1);
	}
	puts("");
	return 0;
}
