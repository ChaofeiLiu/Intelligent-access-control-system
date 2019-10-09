#include <stdio.h>

#define MIN(x,y) x > y ? y : x

int main()
{
	int min = MIN(33, 2);
	printf("min:%d\n", min);
	return 0;
}
