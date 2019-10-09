#include <stdio.h>

int main()
{
	int i= 0,max;
	int arr[]= {1,2,3,4,5};
        max=arr[0];
	for(i = 0; i < 5; i++)
	{
	      	if(arr[i]>max)
                   max=arr[i];
        }
        printf("%d ",max);
	puts("");
	return 0;
}

