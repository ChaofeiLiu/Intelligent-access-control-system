#ifndef __SERIAL_H__
#define __SERIAL_H__
	/*设置串口参数*/
	int uart_set(int fd, int speed, int flow_ctrl, int databits, int stopbits, int parity);
	/*初始化串口*/
	int init_uart();
	/*给串口发指令*/
	int writecmd(int fd, const char *str);
	int myrecvmsg(int fd, unsigned char *buf, int data_len);
#endif
