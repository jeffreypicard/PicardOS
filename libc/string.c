/*
 * string.c
 *
 * String manipulation functions.
 */
#include <types.h>

uint8 *memcpy(uint8 *dest, const uint8 *src, uint32 n)
{
	uint32 i;	
	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return dest;
}

uint8 *memset(uint8 *dest, uint8 val, uint32 n)
{
	uint32 i;	
	for (i = 0; i < n; i++)
		dest[i] = val;
	return dest;
}

uint16 *memsetw(uint16 *dest, uint16 val, uint32 n)
{
	uint32 i;	
	for (i = 0; i < n; i++)
		dest[i] = val;
	return dest;
}

uint32 strlen(const char *str)
{
	uint32 n = 0;
	while(*str++) n++;
	return n;
}
