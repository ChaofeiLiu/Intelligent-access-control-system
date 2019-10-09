#include <stdio.h>

	int main()

	{
		char c = 0 ;
		
	        int i = 0 ;
	
		c |=1<<2;

                printf("%d\n",c);
	
		for(i=7;i>=0;i--)

		{

			printf("%d",(c>>i)&1);
		}	
             		printf("\n");
   			return 0 ;
	}
