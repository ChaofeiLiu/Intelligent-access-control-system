#include <stdio.h>
#include <arpa/inet.h>
#include "../include/mynet.h"
#include <unistd.h>
#include <string.h>
int main()
{
	int sckfd = init_net();
	if(sckfd < 0)
	{
		puts("init net error.");
		return -1;
	}
	//accept
	int ret = -1;
	int len = sizeof(struct sockaddr);
	struct sockaddr_in client;
	int connfd = -1;
	connfd = accept(sckfd, (struct sockaddr *)&client, &len);
	if(connfd < 0)
	{
		puts("accept client error.");
		close(sckfd);
		return -1;
	}
	puts("accept client success.");
	//send and recv
	while(1)
	{
		do_myservice(connfd);
	}
	close(sckfd);
	return 0;
}
