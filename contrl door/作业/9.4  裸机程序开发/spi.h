#ifndef __SPI_H__
#define __SPI_H__

#define OLED		0
#define FLASH		1
#define	RFID		2
#define	UART		3

void spi_init(int ch, int rate, int mode);
void spi_write_read(int ch, int slave, unsigned char *wbuf, unsigned char *rbuf, unsigned int len);
unsigned char spi_send(int ch, int slave, unsigned char dat);

#endif
