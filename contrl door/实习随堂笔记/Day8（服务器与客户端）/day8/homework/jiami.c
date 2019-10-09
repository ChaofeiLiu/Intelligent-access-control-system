#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		puts("Usage:./a.out picfilename");
		return -1;
	}
	int fd = -1;
	fd = open(argv[1], O_RDWR);
	if(fd < 0)
	{
		puts("jiami error.");
		return -1;
	}

	char buf[20];
	memset(buf, 0, 20);
	int ret = read(fd, buf, 20);
	int i = 0;
	if(ret == 20)
	{
		for(i = 0; i < 20/2; i++)
		{
			char temp = buf[i];
			buf[i] = buf[19-i];
			buf[19-i] = temp;
		}

		lseek(fd, 0, SEEK_SET);
		write(fd, buf, 20);
	}
	close(fd);
	return 0;
}
