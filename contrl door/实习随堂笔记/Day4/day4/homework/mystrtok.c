#include <stdio.h>
/*
 *函数名：mystrtok
 *函数功能：分割字符串并输出子串
 *函数参数：
 *	char *src：被分割的字符串的首地址
 *	char c：分割符
 *函数返回值：成功返回0，失败返回-1
 */
int mystrtok(char *src, char c);
int main()
{
	char str[] = "192.168.12.111";
	mystrtok(str, '.');
	return 0;
}

int mystrtok(char *src, char c)
{
	if(NULL == src)
	{
		puts("src is null.");
		return -1;
	}

	int count = 1;
	char *p = src;
	while(*p)
	{
		if(*p == c)
		{
			count++;
		}
		p++;
	}
	if(count == 1)
	{
		puts(src);
	}
	else
	{
		char *arr[10] = {0};
		//保存子串的首地址
		//将分割符换为0
		int i = 0;
		arr[i] = src;
		p = src;
		while(*p)
		{
			if(*p == c)
			{
				*p = 0;
				p++;
				i++;
				arr[i] = p;
				continue;
			}
			p++;
		}

		int k = 0;
		for(k = 0; k < count; k++)
		{
			puts(arr[k]);
		}
		//输出
	}
	return 0;
}
