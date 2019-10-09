#include <stdio.h>

int main()
{
	char a = 4;
	char arr[] = {1,2,3,4,5,6};
	char str[] = "hello bwl";
	char *p = &a;
	//p = arr;
	p = str;
	puts(p);
	return 0;
}
