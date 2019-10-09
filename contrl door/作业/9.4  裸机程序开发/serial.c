#include <LPC11xx.h>

void ser_init(void)
{
	LPC_IOCON->PIO1_6 = (LPC_IOCON->PIO1_6 & ~0x7) | 0x1;
	LPC_IOCON->PIO1_7 = (LPC_IOCON->PIO1_7 & ~0x7) | 0x1;
	LPC_SYSCON->SYSAHBCLKCTRL |= 1 << 12;
	LPC_SYSCON->UARTCLKDIV = 1;
	
	LPC_UART->LCR = 0x83;
	LPC_UART->DLL = 16;
	LPC_UART->DLM = 0;
	LPC_UART->FDR = 0x85;
	LPC_UART->LCR = 0x03;
	
	LPC_UART->TER |= 1 << 7;	
}

void ser_putc(char c)
{
	while (!(LPC_UART->LSR & (1 << 5)));
	LPC_UART->THR = c;
}

int ser_getc(void)
{
#if 0
	if (LPC_UART->LSR & (1 << 0))
		return LPC_UART->RBR;
	else
		return -1;
#endif
	while(!(LPC_UART->LSR & (1 << 0)));
	return LPC_UART->RBR;
}
