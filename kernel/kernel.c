/*
 * kernel.c
 *
 * kernel main and startup routines
 */
#include <system.h>
#include <types.h>
#include <string.h>

/* We will use this later on for reading from the I/O ports to get data
*  from devices such as the keyboard. We are using what is called
*  'inline assembly' in these routines to actually do the work */
uint8 inportb (uint16 _port)
{
	uint8 rv;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}

/* We will use this to write to I/O ports to send bytes to devices. This
*  will be used in the next tutorial for changing the textmode cursor
*  position. Again, we use some inline assembly for the stuff that simply
*  cannot be done in C */
void outportb (uint16 _port, uint8 _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void kernel_main(void)
{
	gdt_install();
	idt_install();
	isr_install();
	init_video();
	/*putch(1 / 0);*/
	puts("Hello, world!");
	void (*f)(void) = 0;
	f();

	for (;;);
}
