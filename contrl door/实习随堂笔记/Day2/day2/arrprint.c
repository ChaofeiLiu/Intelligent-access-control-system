#include <stdio.h>

int main()
{
	//define a char array
	char arr[] = {1,2,3,45,55};
	//print arr
	int i = 0;
	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%d ",arr[i]);
	}
	puts("");
	return 0;
}
