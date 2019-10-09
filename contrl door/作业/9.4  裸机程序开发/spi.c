#include <LPC11xx.h>

#include "spi.h"

void spi_init(int ch, int rate, int mode)
{
	if (ch == 0) {
		LPC_SYSCON->PRESETCTRL    |= (0x1<<0);		//??reset
		LPC_SYSCON->SYSAHBCLKCTRL |= (0x1<<11);		//ssp0 clk
		LPC_SYSCON->SSP0CLKDIV     = 24;				/* Divided by 24 */
		LPC_IOCON->PIO0_8         &= ~0x07;			/* SSP I/O config */
		LPC_IOCON->PIO0_8         |= 0x01;			/* SSP MISO */
		LPC_IOCON->PIO0_9         &= ~0x07;	
		LPC_IOCON->PIO0_9         |= 0x01;			/* SSP MOSI */

		LPC_IOCON->SCK_LOC = 0x02;
		LPC_IOCON->PIO0_6 = 0x02;								/* P0.6 function 2 is SSP clock, need to 
																							combined with IOCONSCKLOC register setting */  

		LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);		//gpio clk
		LPC_IOCON->PIO2_4 &= ~0x07;							/* SSP SSEL0 is a GPIO pin, for OLED */
		LPC_GPIO2->DIR |= 1 << 4;
		LPC_GPIO2->DATA |= 1 << 4;

		LPC_IOCON->PIO2_6 &= ~0x07;							/* SSP SSEL1 is a GPIO pin, for FLASH */
		LPC_GPIO2->DIR |= 1 << 6;
		LPC_GPIO2->DATA |= 1 << 6;

		LPC_IOCON->PIO2_7 &= ~0x07;							/* SSP SSEL2 is a GPIO pin, for RFID */
		LPC_GPIO2->DIR |= 1 << 7;
		LPC_GPIO2->DATA |= 1 << 7;
	} else {
		LPC_SYSCON->PRESETCTRL    |= (0x1<<2);
		LPC_SYSCON->SYSAHBCLKCTRL |= (1<<18);
		LPC_SYSCON->SSP1CLKDIV     = 24;			/* Divided by 24 */
		LPC_IOCON->PIO2_2         &= ~0x07;		/* SSP I/O config */
		LPC_IOCON->PIO2_2         |= 0x02;		/* SSP MISO */
		LPC_IOCON->PIO2_3         &= ~0x07;	
		LPC_IOCON->PIO2_3         |= 0x02;		/* SSP MOSI */
		LPC_IOCON->PIO2_1         &= ~0x07;
		LPC_IOCON->PIO2_1         |= 0x02;		/* SSP CLK */
	 
		LPC_IOCON->PIO2_0 &= ~0x07;						/* SSP SSEL is a GPIO pin */
		LPC_GPIO2->DIR |= 1 << 0;
		LPC_GPIO2->DATA |= 1 << 0;
	}
	
	if (ch == 0) {
		LPC_SSP0->CPSR = 2;										/* Divided by 2 */
		LPC_SSP0->CR0 = ((1000000 / rate - 1) << 8) | \
										((mode & 1) << 7) | (((mode & 2) >> 1) << 6) | \
						(7 << 0);					//8 bit   spi ??     		//????     //??
		LPC_SSP0->IMSC = 0;										/* disable all interrupts */
		LPC_SSP0->ICR = 3;										/* clears interrupts */
		LPC_SSP0->CR1 = 1 << 1;								/* Master, SPI Enable */
	} else {
		LPC_SSP1->CPSR = 2;										/* Divided by 2 */
		LPC_SSP1->CR0 = ((1000000 / rate - 1) << 8) | \
										((mode & 1) << 7) | (((mode & 2) >> 1) << 6) | \
										(7 << 0);
		LPC_SSP1->IMSC = 0;										/* disable all interrupts */
		LPC_SSP1->ICR = 3;										/* clears interrupts */
		LPC_SSP1->CR1 = 1 << 1;								/* Master, SPI Enable */
	}
}

static void spi_set_cs(int slave)
{
	switch (slave) {
		case OLED:
			LPC_GPIO2->DATA |= 1 << 4;
			break;
		case FLASH:
			LPC_GPIO2->DATA |= 1 << 6;
			break;
		case RFID:
			LPC_GPIO2->DATA |= 1 << 7;
			break;
		case UART:
			LPC_GPIO2->DATA |= 1 << 0;
			break;
	}
}

static void spi_clr_cs(int slave)
{
	switch (slave) {
		case OLED:
			LPC_GPIO2->DATA &= ~(1 << 4);
			break;
		case FLASH:
			LPC_GPIO2->DATA &= ~(1 << 6);
			break;
		case RFID:
			LPC_GPIO2->DATA &= ~(1 << 7);
			break;
		case UART:
			LPC_GPIO2->DATA &= ~(1 << 0);
			break;
	}
}

static void spi_write_read(int ch, int slave, unsigned char *wbuf, unsigned char *rbuf, unsigned int len)
{
	int i = 0;
  if(ch == 0)
  {
		while (i < len) {
			spi_clr_cs(slave);
			while((LPC_SSP0->SR & ((1 << 1) | (1 << 4))) != (1 << 1));	//transmitt ??, ??idle
			LPC_SSP0->DR = wbuf[i];
			while(LPC_SSP0->SR & (1 << 4));			//????

			while((LPC_SSP0->SR & ((1 << 2) | (1 << 4))) != (1 << 2));	//receive ??, ??idle
			rbuf[i] = LPC_SSP0->DR;
			spi_set_cs(slave);
			i++;
		}
  } else {
		while (i < len) {
			spi_clr_cs(slave);
			while((LPC_SSP1->SR & ((1 << 1) | (1 << 4))) != (1 << 1));
			LPC_SSP1->DR = wbuf[i];
			while(LPC_SSP1->SR & (1 << 4));

			while((LPC_SSP1->SR & ((1 << 2) | (1 << 4))) != (1 << 2));
			rbuf[i] = LPC_SSP1->DR;
			spi_set_cs(slave);
			i++;
		}
  }
}

unsigned char spi_send(int ch, int slave, unsigned char dat)
{
	unsigned char c;
	
	spi_write_read(ch, slave, &dat, &c, 1);
	return c;
}
