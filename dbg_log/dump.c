/**
 * Copyright (c) 2022-2023，HelloAlpha
 * 
 * Change Logs:
 * Date           Author       Notes
 */
#include <stdio.h>
#define kprintf printf

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

#define __is_print(ch) ((unsigned int)((ch) - ' ') < 127u - ' ')
extern void dump_hex(const uint8_t* ptr, uint32_t buflen)
{
    unsigned char* buf = (unsigned char*)ptr;
    int i, j;

    for (i = 0; i < buflen; i += 16)
    {
        kprintf("%08X: ", ptr + i);

        for (j = 0; j < 16; j++)
            if (i + j < buflen)
                kprintf("%02X ", buf[i + j]);
            else
                kprintf("   ");
        kprintf(" ");

        for (j = 0; j < 16; j++)
            if (i + j < buflen)
                kprintf("%c", __is_print(buf[i + j]) ? buf[i + j] : '.');
        kprintf("\r\n");
    }
}
