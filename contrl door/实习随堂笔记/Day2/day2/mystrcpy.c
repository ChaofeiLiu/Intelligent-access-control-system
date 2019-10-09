#include <stdio.h>
#include <string.h>

int main()
{
	char dest[20] = {0};
	/*
	int i = 0;
	for(i = 0; i < sizeof(dest)/sizeof(dest[0]); i++)
	{
		printf("dest[%d]:%d\n",i,dest[i]);
	}
	*/
	char str[] = "yan xi gong lue";
	char *p = NULL;
	puts("hhhhhhhhhh");
	*p = 3;
	//printf("%c\n",*p);
	//puts(p);
	puts("===========");
	p = strcpy(dest, str);
	puts(p);
	return 0;
}
