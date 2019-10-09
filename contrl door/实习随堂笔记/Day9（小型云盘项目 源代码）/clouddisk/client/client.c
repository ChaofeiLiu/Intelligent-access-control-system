#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
	//socket
	int sock_client = -1;
	sock_client = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_client < 0)
	{
		puts("create socket error.");
		return -1;
	}
	puts("create socket success.");
	//connect
	struct sockaddr_in ser;
	memset(&ser, 0, sizeof(struct sockaddr_in));
	ser.sin_family = AF_INET;
	ser.sin_port = htons(8888);
	ser.sin_addr.s_addr = inet_addr("127.0.0.1");
	int ret = connect(sock_client, (struct sockaddr *)&ser, sizeof(struct sockaddr));
	if(ret != 0)
	{
		puts("connect error.");
		close(sock_client);
		return -1;
	}
	puts("connect success.");
	//send and recv
	char buf[50];
	while(1)
	{
		//send
		memset(buf, 0, 50);
		gets(buf);
		send(sock_client, buf, strlen(buf), 0);
		//recv
		memset(buf, 0, 50);
		ret = recv(sock_client, buf, 50, 0);
		if(ret > 0)
		{
			puts(buf);
		}
	}
	//close
	close(sock_client);
	return 0;
}
