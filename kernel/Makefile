HOST?=i686-pc-elf
HOSTARCH:=i386

AS=$(HOST)-as
CC=$(HOST)-gcc
LD=$(HOST)-ld

CFLAGS?=-O0 -g -ggdb
CPPFLAGS?=
LDFLAGS?=
LIBS?=

DESTDIR?=
PREFIX?=../
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include

CFLAGS:=$(CFLAGS) -ffreestanding -fno-builtin -Wall -Wextra -pedantic
CPPFLAGS:=$(CPPFLAGS) -D__is_picardos_kernel -I../include
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -nostdinc

ARCHDIR:=arch/$(HOSTARCH)

include $(ARCHDIR)/config.mk

CFLAGS:=$(CFLAGS) $(KERNEL_ARCH_CFLAGS)
CPFLAGS:=$(CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)

OBJS:=\
$(KERNEL_ARCH_OBJS) \
kernel.o \

ALL_OUR_OBJS:=\
$(OBJS) \

OBJ_LINK_LIST:=\
$(OBJS) \

all: kernel.bin

.PHONY: all clean install install-headers install-kernel

kernel.bin: $(OBJ_LINK_LIST) $(ARCHDIR)/link.ld
	$(CC) -T $(ARCHDIR)/link.ld -o $@ $(CFLAGS) $(OBJ_LINK_LIST) ../lib/libk.a $(LDFLAGS) $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

%.o: %.S
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

clean:
	rm -f kernel.bin $(OBJS) $(ALL_OUR_OBJS) *.o */*.o */*/*.o
