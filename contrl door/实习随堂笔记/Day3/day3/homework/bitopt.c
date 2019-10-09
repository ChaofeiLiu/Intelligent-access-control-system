#include <stdio.h>

int main()
{
	char a = 7;
	int i = 0;
	for(i = 7; i >= 0; i--)
	{
		/*
		if((a & 1 << i) > 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}*/

		printf("%d",a >> i & 1);
	}
	puts("");

	a |= 1 << 7;
	for(i = 7; i >= 0; i--)
	{
		printf("%d", a >> i & 1);
	}
	puts("");
	a &= ~(1 << 1);
	for(i = 7; i >= 0; i--)
	{
		printf("%d", a >> i & 1);
	}
	puts("");
	return 0;
}
