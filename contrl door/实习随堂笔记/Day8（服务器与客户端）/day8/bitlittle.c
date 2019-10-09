#include <stdio.h>

int main()
{
	int n = 0x12345678;
	char *p = (char *)&n;
	printf("p:%p\t*p:%x\n",p,*p);
	printf("p+1:%p\t*(p+1):%x\n",p+1,*(p+1));
	printf("p+2:%p\t*(p+1):%x\n",p+2,*(p+2));
	printf("p+3:%p\t*(p+3):%x\n",p+3,*(p+3));
	return 0;
}
