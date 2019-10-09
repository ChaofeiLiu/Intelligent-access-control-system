#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "serial.h"

extern char env[100];
extern char devstat[50];
extern int t,h;
extern unsigned long l;

int writecmd(int fd, const char *str)
{
	//int fd = init_uart();
	char buf[36];
	if(strstr(str, "led_open"))
	{
		puts("---writecmd---openled---");
		strcpy(buf,"aaaa");
	}
	else if(strstr(str, "led_close"))
	{
		puts("---writecmd---closeled---");
		strcpy(buf,"bbbb");
	}
	else if(strstr(str, "bzz_open"))
	{
		puts("---writecmd---openbzz---");
		strcpy(buf,"eeee");
	}
	else if(strstr(str, "bzz_close"))
	{
		puts("---writecmd---closebzz---");
		strcpy(buf,"ffff");
	}
	else if(strstr(str, "read_rfid"))
	{
		puts("---writecmd---readrfid---");
		strcpy(buf,"rrrr");
	}
	else if(strstr(str, "write_rfid"))
	{
		puts("---writecmd---writerfid---");
		sprintf(buf,"w%s",str+11);
		write(fd, buf, 17);
		char cmd[100] = {0};
		sprintf(cmd,"echo \"%s\" >> rfid_num",str+11);
		system(cmd);
		return 0;
	}
	int ret = write(fd, buf, 2);
}

int init_uart()
{
	//serial_init
	//open ttyUSB0
	int fd_ser = -1;
	fd_ser = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
	if(fd_ser < 0)
	{
		perror("open serial");
		return -1;
	}
	
	int ret_s = uart_set(fd_ser, 115200, 0, 8, 1, 'N');
	printf("ret_s:%d\n",ret_s);
	printf("serial->init:init serial success.\n");
	
	return fd_ser;
}

int uart_set(int fd, int speed, int flow_ctrl, int databits, int stopbits, int parity)
{
	int i;
	int status;
	int speed_arr[] = {B115200, B19200, B9600, B4800, B2400, B1200, B300};
	int name_arr[] = {115200, 19200, 9600, 4800, 2400, 1200, 300};
	
	struct termios options;
	if(tcgetattr(fd, &options) != 0)
	{
		perror("SetupSerial 1");
		return 0;
	}

	//set baud
	for(i = 0; i < sizeof(speed_arr) / sizeof(int); i++)
	{
		if(speed == name_arr[i])
		{
			cfsetispeed(&options, speed_arr[i]);
			cfsetospeed(&options, speed_arr[i]);
		}
	}
	
	options.c_cflag |= CLOCAL;
	options.c_cflag |= CREAD;
	
	switch(flow_ctrl)
	{
		case 0:
			options.c_cflag &= ~CRTSCTS;
			break;
		case 1:
			options.c_cflag &= CRTSCTS;
			break;
		case 2:
			options.c_cflag |= IXON | IXOFF | IXANY;
			break;
	}

	options.c_cflag &= ~CSIZE;
	switch(databits)
	{
		case 5:
			options.c_cflag |= CS5;
			break;
		case 6:
			options.c_cflag |= CS6;
			break;
		case 7:
			options.c_cflag |= CS7;
			break;
		case 8:
			options.c_cflag |= CS8;
			break;
		default:
			puts("Unsupported data size");
			return 0;
	}

	switch(parity)
	{
		case 'n':
		case 'N':
			options.c_cflag &= ~PARENB;
			options.c_iflag &= ~INPCK;
			break;
		case 'o':
		case 'O':
			options.c_cflag |= (PARODD | PARENB);
			options.c_iflag |= INPCK;
			break;
		case 'e':
		case 'E':
			options.c_cflag |= PARENB;
			options.c_cflag |= ~PARODD;
			options.c_iflag |= INPCK;
			break;
		case 's':
		case 'S':
			options.c_cflag &= ~PARENB;
			options.c_cflag &= ~CSTOPB;
			break;
		default:
			puts("Unsupport parity");
			return 0;
	}

	switch (stopbits)
	{
		case 1:
			options.c_cflag &= ~CSTOPB;
			break;
		case 2:
			options.c_cflag |= CSTOPB;
			break;
		default:
			puts("Unsupported stop bits");
			return 0;
	}

	options.c_oflag &= ~OPOST;
	//options.c_oflag = 0;
	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
	//options.c_lflag &= ~ICANON;
	
	options.c_cc[VTIME] = 1;
	options.c_cc[VMIN] = 1;

	tcflush(fd, TCIFLUSH);
	
	if(tcsetattr(fd, TCSANOW, &options) != 0)
	{
		perror("com set error");
		return 0;
	}
	return 1;
}

int myrecvmsg(int fd, unsigned char *buf, int data_len)
{
	if(fd < 0)
	{
		puts("fd < 0");
		return -1;
	}

	if(NULL == buf)
	{
		puts("buf is null.");
		return -1;
	}
	
	puts("enter recvmsg:");
	//select serial port
	int len, fs_sel;
	fd_set fs_read;
	
	struct timeval time;
	
	FD_ZERO(&fs_read);
	FD_SET(fd, &fs_read);

	time.tv_sec = 10;
	time.tv_usec = 0;

	fs_sel = select(fd+1, &fs_read, NULL, NULL, &time);
	if(fs_sel)
	{
		len = read(fd, buf, data_len);
		printf("read serial len: %d\n", len);
		puts(buf);
		return len;
	}
	else
	{
		puts("select timeout.");
		return -1;
	}
}

