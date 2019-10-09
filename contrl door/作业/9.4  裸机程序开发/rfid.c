#include "spi.h"
#include "serial.h"
#include "bzz.h"
#include <string.h>
#include <LPC11xx.h>



const unsigned char RFID_READ_DATA_BLOCK_21[10]  = {0x0a, 0x21, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
const unsigned char RFID_WRITE_DATA_BLOCK_22[10] = {0x1a, 0x22, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; 

void rfid_init(void)
{
	spi_init(0, 100000, 0);
//	LPC_GPIO2->DIR &= ~(1 << 8);	//
}
#if 0
int rfid_state(void)
{
	static unsigned int pre = 1, cur = 1;
	
	cur = (LPC_GPIO2->DATA >> 8) & 1;
	if (cur != pre && pre == 1) {
		pre = cur;
		return 1;
	} else {
		pre = cur;
		return 0;
	}
}
#endif

unsigned char rfid_checksum(const unsigned char *buf)
{
	int i;
	unsigned char chksum = 0;
	
	for (i = 0; i < buf[0]; i++)
		chksum += buf[i];
	
	return chksum;
}

int rfid_read(unsigned char *rbuf)
{
	int i;
	unsigned char buf[32];
	unsigned char chksum = rfid_checksum(RFID_READ_DATA_BLOCK_21);

	spi_send(0, RFID, 0xAA);
	delay(10);
	spi_send(0, RFID, 0xBB);
	delay(10);
	for (i = 0; i < RFID_READ_DATA_BLOCK_21[0]; i++) {
		spi_send(0, RFID, RFID_READ_DATA_BLOCK_21[i]);
		delay(10);
	}
	spi_send(0, RFID, chksum);
	
	delay(500);
	
	spi_send(0, RFID, 0xAA);
	delay(10);
	spi_send(0, RFID, 0xBB);
	delay(10);
	
	for (i = 0; i < 19; i++) {
		buf[i] = spi_send(0, RFID, 0);
		delay(10);
	}
	if(buf[0] != 18 || buf[1] != 0x21)
		return -1;
	else
	{
		memcpy(rbuf, buf + 2, 16);
		return 0;
	}

	#if 0		
	chksum = rfid_checksum(buf);
	if (chksum != buf[buf[0]])
		return -1;
	else {
		memcpy(rbuf, buf + 2, 16);
		return 0;
	}
#endif
	
}

int rfid_write(unsigned char *wbuf)
{
	int i;
	unsigned char chksum;
	unsigned char buf[32];

	memcpy(buf, RFID_WRITE_DATA_BLOCK_22, 10);
	memcpy(buf + 10, wbuf, 16);
	chksum = rfid_checksum(buf);

	spi_send(0, RFID, 0xAA);
	delay(10);
	spi_send(0, RFID, 0xBB);
	delay(10);
	for (i = 0; i < buf[0]; i++) {
		spi_send(0, RFID, buf[i]);
		delay(10);
	}
	spi_send(0, RFID, chksum);
	
	delay(500);
	
	spi_send(0, RFID, 0xAA);
	delay(10);
	spi_send(0, RFID, 0xBB);
	delay(10);
	
	for (i = 0; i < 3; i++) {
		buf[i] = spi_send(0, RFID, 0);
		delay(10);
	}
	
	if (buf[0] != 2 || buf[1] != 0x22)
		return -1;
	else
		return 0;
}
