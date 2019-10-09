#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include "../include/myopt.h"
int init_net()
{
	//socket
	int sock_ser = -1;
	sock_ser = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_ser < 0)
	{
		puts("create socket error.");
		return -1;
	}
	puts("create socket success.");
	//bind
	struct sockaddr_in myser;
	memset(&myser, 0, sizeof(struct sockaddr_in));
	myser.sin_family = AF_INET;
	myser.sin_port = htons(8888);
	myser.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(sock_ser, (struct sockaddr *)&myser, sizeof(struct sockaddr));
	if(ret < 0)
	{
		puts("bind error.");
		close(sock_ser);
		return -1;
	}
	puts("bind success.");
	//listen
	ret = listen(sock_ser, 5);
	if(ret != 0)
	{
		puts("listen error.");
		close(sock_ser);
		return -1;
	}
	puts("listen ok");
	return sock_ser;
}

int do_myservice(int connfd)
{
	if(connfd < 0)
	{
		puts("connfd < 0");
		return -1;
	}
	char buf[50] = {0};
	int ret = recv(connfd, buf, 50, 0);
	if(ret > 0)
	{
		//reg service
		if(strstr(buf, "reg"))
		{
			ret = save_user_info(buf+4);
			if(ret == 0)
			{
				memset(buf, 0, 50);
				strcpy(buf, "reg success.");
				send(connfd, buf, 50, 0);
			}
		}
	}
	return 0;
}
