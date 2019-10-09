#include <stdio.h>
/*
 *int argc:参数个数包含命令本身
 *char *argv[]:是一个char *的数组，每一个元素代表
 *的是参数的首地址，每一个参数都是一个字符串，每一个
 *参数之间用空格隔开。
 */
int main(int argc, char *argv[])
{
	/*打印参数个数*/
	printf("argc:%d\n",argc);
	int i = 0;
	/*打印每一个参数*/
	for(i = 0; i < argc; i++)
	{
		puts(argv[i]);
	}
	return 0;
}
