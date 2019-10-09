#include <stdio.h>

int main()
{
	printf("szieof(char):%d\n",sizeof(char));
	printf("szieof(short):%d\n",sizeof(short));
	printf("szieof(int):%d\n",sizeof(int));
	printf("szieof(long):%d\n",sizeof(long));
	printf("szieof(long long):%d\n",sizeof(long long));
	printf("szieof(void):%d\n",sizeof(void));
	printf("szieof(int [5]):%d\n",sizeof(int [5]));
	printf("szieof(int [10]):%d\n",sizeof(int [10]));
	printf("szieof(char *):%d\n",sizeof(char *));
	printf("szieof(double *):%d\n",sizeof(double *));
	return 0;
}
