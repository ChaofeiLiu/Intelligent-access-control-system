#include <stdio.h>
#include "mystring.h"
#include <string.h>

int main()
{
	char s1[20] = {0};
	char s2[] = "farsight";
	char *p = mystrcpy(s1, s2);
	puts(p);
	int len = mystrlen(s2);
	printf("%d\n",len); 
	//p = mystrtok(s2, 'i');
	//puts(p);
	memset(s1, 0, 20);
	mystrcpy(s1, "hello ");
	mystrcat(s1, s2);
	puts(s1);
	char s[] = "521";
	int ret = myatoi(s);
	printf("ret:%d\n",ret);
	return 0;
}
