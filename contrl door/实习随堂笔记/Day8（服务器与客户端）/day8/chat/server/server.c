#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

int main()
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
	//accept
	int len = sizeof(struct sockaddr);
	struct sockaddr_in client;
	int connfd = -1;
	connfd = accept(sock_ser, (struct sockaddr *)&client, &len);
	if(connfd < 0)
	{
		puts("accept client error.");
		close(sock_ser);
		return -1;
	}
	puts("accept client success.");
	//send and recv
	char buf[50] = {0};
	while(1)
	{
		memset(buf, 0, 50);
		//send
		gets(buf);
		send(connfd, buf, strlen(buf), 0);
		//recv
		memset(buf, 0, 50);
		ret = recv(connfd, buf, 50, 0);
		if(ret > 0)
		{
			puts(buf);
			if(strcmp(buf,"quit") == 0)
			{
				break;
			}
		}
	}
	//close
	close(sock_ser);
	return 0;
}
