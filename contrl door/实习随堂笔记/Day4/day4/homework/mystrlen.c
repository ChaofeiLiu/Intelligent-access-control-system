#include <stdio.h>
/*
 *函数名：mystrlen
 *函数功能：求字符串长度
 *函数参数：
 *	const char *str：被求长度的字符串的首地址
 *函数返回值：返回字符串的长度
 */
int mystrlen(const char *str);
int main()
{
	char str[] = "hello world";
	/*函数调用*/
	int len = mystrlen(str);
	printf("%s len is %d\n",str, len);
	return 0;
}

/*函数的定义*/
int mystrlen(const char *str)
{
	if(NULL == str)
	{
		return -1;
	}
	int len = 0;
	while(*str)
	{
		len++;
		str++;
	}
	return len;
}
