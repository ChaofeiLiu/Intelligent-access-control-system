#ifndef __MYNET_H__
#define __MYNET_H__
	/*
	 *函数名：init_net
	 *函数功能：初始化网络：socket/bind/listen
	 *函数参数：void
	 *函数返回值：创建的socket的文件描述符，失败返回-1
	 */
	int init_net();
	/*
         *函数名：do_myservice
         *函数功能：为客户端提供服务
         *函数参数：int connfd:通信套节字
         *函数返回值：int成功返回0，失败返回-1
         */
	int do_myservice(int connfd);
#endif
