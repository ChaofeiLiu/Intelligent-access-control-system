#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/*入参判断，如果参数个数不等与5，就报错返回*/
	if(argc != 5)
	{
		puts("Usage:./a.out num1 opt num2 =");
		return -1;
	}
	/*获取操作数*/
	/*如何将字符串转换为整数*/
	int num1, num2;
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	printf("num1:%d\nnum2:%d\n",num1, num2);
	/*获取操作符*/
	char opt = argv[2][0];
	/*计算并输出*/
	switch (opt)
	{
		case '+':
			printf("%d + %d = %d\n", num1, num2, num1 + num2);
			break;
		case '-':
			printf("%d - %d = %d\n", num1, num2, num1 - num2);
			break;
		case '*':
			printf("%d * %d = %d\n", num1, num2, num1 * num2);
			break;
		case '/':
			if(num2 == 0)
			{
				puts("num2 is 0");
				return -1;
			}
			printf("%d / %d = %d\n", num1, num2, num1 / num2);
			break;
		case '%':
			if(num2 == 0)
			{
				printf("%d %% %d = %d\n",num1,num2,num1);
				return 0;
			}
			printf("%d %% %d = %d\n", num1, num2, num1 % num2);
			break;
		default:
			puts("cannot support this option.");
	}
	return 0;
}
