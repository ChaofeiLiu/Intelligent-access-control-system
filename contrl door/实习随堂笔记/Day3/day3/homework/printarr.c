#include <stdio.h>

int print_arr(int arr[5], int size);
int main()
{
	int arr[5] = {1,2,3};
	printf("sizeof(arr):%d\n",sizeof(arr));
	printf("sizeof(int *):%d\n",sizeof(int *));
	
	print_arr(arr,sizeof(arr)/sizeof(arr[0]));
	printf("arr:%p\n",arr);
	printf("arr+1:%p\n",arr+1);
	puts("====================");
	int i = 0;
	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	puts("");
	puts("*******************");
	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%d ", *(arr+i));
	}
	puts("");
	return 0;
}

int print_arr(int arr[5], int size)
{
	if(NULL == arr)
	{
		puts("NULL pointer error.");
		return -1;
	}
	int i = 0; 
	for(i = 0; i < size; i++)
	{
		printf("%d  ", arr[i]);
	}
	puts("");
	return 0;
}
