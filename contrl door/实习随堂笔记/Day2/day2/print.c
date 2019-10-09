#include <stdio.h>

int main()
{
	printf("hello world!\n");
	int a = 9;
	printf("a = %d\n", a);
	char c = 'w';
	printf("c = %c\n", c);
	float f = 3.14;
	printf("f = %f\n",f);
	int *p = &a;
	double d = 3.22;
	printf("p = %p\nd = %f\n *p = %d\n", p, d, *p);
	char str[] = "tekljsdklf";
	printf("%s\n",str);
	return 0;
}
