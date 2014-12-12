#ifndef __STRING_H__
#define __STRING_H__

uint8 *memcpy(uint8 *dest, const uint8 *src, uint32 n);
uint8 *memset(uint8 *dest, uint8 val, uint32 n);
uint16 *memsetw(uint16 *dest, uint16 val, uint32 n);
uint32 strlen(const char *str);

#endif
