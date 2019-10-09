#include <stdio.h>

int main()
{
	char a[] = {1,2,3,4,5};
	printf("a:%p\t*a:%d\n",a,*a);
	char *p = a;
	printf("p:%p\t*p:%d\n",p,*p);
	char s[5] = {0};
	return 0;	
}
