#include <stdio.h>
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MUL(x,y) ((x)*(y))
int main()
{
	int x = 8;
	int y = 9;
	int max = MAX(8+3,y);
	int mul = MUL(8+3,y);
	printf("max:%d\n",max);
	printf("mul:%d\n",mul);
	return 0;
}
