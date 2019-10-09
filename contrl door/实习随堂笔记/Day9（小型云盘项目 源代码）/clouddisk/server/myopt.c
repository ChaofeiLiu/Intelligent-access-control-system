#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int save_user_info(char *user_info)
{
	//open file (userinfo)
	int fd = -1;
	fd = open("userinfo", O_WRONLY);
	if(fd < 0)
	{
		puts("save_user_info error.");
		return -1;
	}
	
	//write user_info to userinfo
	char buf[100];
	memset(buf, 0, 100);
	sprintf(buf, "%s\n", user_info);
	write(fd, buf, strlen(buf));
	//close
	close(fd);
	return 0;
}
