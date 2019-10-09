#include <stdio.h>

int main()
{
	printf("%d\n", 1 << 34);
	char i = 1;
	printf("%d\n", i << 34);
	i = 34;
	printf("%d\n", 1 << i);	
	char n = 1;
	printf("%d\n", n << i);
	return 0;
}
