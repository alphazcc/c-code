/**
 * Copyright (c) 2022-2023，HelloAlpha
 * 
 * Change Logs:
 * Date           Author       Notes
 */

#ifndef __ASSERT_H__
#define __ASSERT_H__

#include <stdio.h>
#define kprintf printf

/* 自定义断言 */
#ifdef USING_ASSERT
/* 处理函数原型，此处未使用 */
//void Assert(char * filename, unsigned int lineno);
/* 使用断言 */
#define ASSERT(condition)   \
    do                      \
    {                       \
        if(condition)       \
            NULL;           \
        else                \
            kprintf("Assert Failed: %s, line %u\n", __FILE__, __LINE__);  \
    } while(0)
/* 不使用断言 */
#else
#define ASSERT(condition) NULL
#endif

#endif
