#ifndef __RFID_H__
#define __RFID_H__
	void rfid_init(void);
	int rfid_state(void);
	int rfid_read(unsigned char *rbuf);
	int rfid_write(unsigned char *wbuf);
#endif
