#include <LPC11xx.h>

void led_init()
{
	LPC_GPIO3->DIR |= (1 << 0);
}

void led_open()
{
	LPC_GPIO3->DATA &= ~(1 << 0);
}

void led_close()
{
	LPC_GPIO3->DATA |= (1 << 0);
}
