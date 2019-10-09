#include <LPC11xx.h>
#include "rfid.h"
#include "serial.h"
#include "led.h"
#include "bzz.h"

int main()
{
	int i;
	unsigned char rbuf[16];
	unsigned char wbuf[16];
	
	LPC_SYSCON->SYSAHBCLKCTRL |= 1 << 16;
	
	LPC_GPIO3->DIR |= (1 << 0);
	LPC_GPIO3->DIR |= (1 << 1);
	LPC_SYSCON->SYSAHBCLKCTRL |= 1 << 16;
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);
	
	ser_init();
	rfid_init();
	led_init();
	spk_init();

	
	while(1)
	{
		int c;
		c = ser_getc();
		ser_putc(c);
		
		switch(c)
		{
			case 'r':
				//	led_open();
					rfid_read(rbuf);
					for(i = 0; i < 16; i++)
					{
						ser_putc(rbuf[i]);
					}
					break;
			case 'w':
					for(i = 0; i < 16; i++)
					{
						wbuf[i] = ser_getc();
					}
					rfid_write(wbuf);
					break;
			case 'a':
					led_open();
					break;
			case 'b':
					led_close();
				break;
			case 'c':
				spk_on();
				break;
			case 'd':
				spk_off();
				break;
						
		}
	}
}
