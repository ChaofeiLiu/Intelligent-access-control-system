#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		puts("Usage:./a.out file1 file2");
		return -1;
	}

	int fdsrc = -1;
	int fddest = -1;

	fdsrc = open(argv[1], O_RDONLY);
	fddest = open(argv[2], O_WRONLY | O_CREAT, 0664);

	if(fdsrc < 0 && fddest < 0)
	{
		return -1;
	}

	if(fdsrc < 0 && fddest > 0)
	{
		close(fddest);
		return -1;
	}

	if(fdsrc > 0 && fddest < 0)
	{
		close(fdsrc);
		return -1;
	}

	char buf[101] = {0};
	int ret = 0;
	while(1)
	{
		memset(buf, 0, 101);
		ret = read(fdsrc, buf, 100);
		if(ret > 0)
		{
			write(fddest, buf, ret);
		}
		else if(ret == 0)
		{
			break;
		}
	}
	close(fdsrc);
	close(fddest);
	return 0;
}
