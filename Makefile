.PHONY: all clean libc kernel

all: libc kernel iso

libc:
	$(MAKE) -C libc
	$(MAKE) install -C libc

kernel:
	$(MAKE) -C kernel

iso:
	./iso.sh

clean:
	rm -f PicardOS.iso
	make clean -C libc
	make clean -C kernel
	rm -rf lib isodir
