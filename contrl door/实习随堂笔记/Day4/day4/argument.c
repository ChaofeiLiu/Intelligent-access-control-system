#include <stdio.h>

int num = 4,num2 = 8;
int *p;
int main()
{
	/*
	char *pp;
	printf("%d\tp:%p\tpp:%p\n",num,p,pp);
	myadd();
	printf("%d\tp:%p\tpp:%p\n",num,p,pp);
	*/
	printf("num:%d\tnum2:%d\n",num, num2);
	myswp();
	printf("num:%d\tnum2:%d\n",num, num2);
}

int myadd()
{
	num += 5;
	return 0;
}

int myswp()
{
	int temp = num;
	num = num2;
	num2 = temp;
}
