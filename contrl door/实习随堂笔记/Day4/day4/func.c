#include <stdio.h>

int myswp(int *pnum1, int *pnum2);
int main()
{
	int num1 = 9, num2 = -2;
	printf("num1:%d\tnum2:%d\n",num1,num2);
	myswp(&num1, &num2);
	printf("num1:%d\tnum2:%d\n",num1,num2);
	return 0;
}

int myswp(int *pnum1, int *pnum2)
{
	int temp = 0;
	temp = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = temp;
	return 0;
}
