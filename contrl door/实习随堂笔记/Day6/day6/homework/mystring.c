#include <stdio.h>
#include <string.h>

char *mystrcpy(char *dest, char *src)
{
	if(NULL == dest || NULL == src)
	{
		puts("NULL pointer error.");
		return NULL;
	}

	char *p = dest;
	while(*src)
	{
		*p = *src;
		src++;
		p++;
	}
	*p = 0;
	return dest;
}

int mystrlen(const char *src)
{
	if(NULL == src)
	{
		puts("src is null.");
		return -1;
	}
	
	int len = 0;
	while(*src)
	{
		len++;
		src++;
	}
	return len;
}

char *mystrtok(char *src, char c)
{
	if(NULL == src)
	{
		return NULL;
	}
	char *p = src;
	while(*p)
	{
		if(*p == c)
		{
			*p = 0;
			break;
		}
		p++;
	}
	return src;
}

char *mystrcat(char *s1, const char *s2)
{
	if(NULL == s1 && NULL != s2)
	{
		return s2;
	}

	if(NULL != s1 && NULL == s2)
	{
		return s1;
	}

	if(NULL == s1 && NULL == s2)
	{
		return NULL;
	}

	char *p = s1 + strlen(s1);
	while(*s2)
	{
		*p = *s2;
		s2++;
		p++;
	}
	*p = 0;
	return s1;
}

int myatoi(char *nptr)
{
	if(NULL == nptr)
	{
		puts("nptr is null.");
		return -1;
	}

	int sum = 0;
	while(*nptr)
	{
		sum = sum * 10 + (*nptr - '0');
		nptr++;
	}
	return sum;
}

