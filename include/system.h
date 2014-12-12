#ifndef __SYSTEM_H
#define __SYSTEM_H
#include <types.h>

/* main.c */
extern uint8 inportb(uint16 _port);
extern void outportb(uint16 _port, uint8 _data);

/* scrn.c */
extern void cls(void);
extern void putch(uint8 c);
extern void puts(char *str);
extern void settextcolor(uint8 forecolor, uint8 backcolor);
extern void init_video();

/* gdt.c */
extern void gdt_set_gate(int num, uint32 base, uint32 limit, uint8 access, uint8 gran);
extern void gdt_install(void);

/* idt.c */
void idt_set_gate(uint8 num, unsigned long base, uint16 sel, uint8 flags);
void idt_install(void);

/* isr.c */
void isr_install(void);
/* This defines what the stack looks like after an ISR was running */
struct isr_regs_t
{
	uint32 gs, fs, es, ds;                          /* pushed the segs last */
	uint32 edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
	uint32 int_no, err_code;                        /* our 'push byte #' and ecodes do this */
	uint32 eip, cs, eflags, useresp, ss;            /* pushed by the processor automatically */ 
};

#endif
