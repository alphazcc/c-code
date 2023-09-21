/**
 * Copyright (c) 2022-2023，HelloAlpha
 * 
 * Change Logs:
 * Date           Author       Notes
 */
#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>
#define kprintf printf

/* 自定义 */
#ifdef USING_ULOG
/* 使用调试日志 */
#define ULOG(...)                   \
    do                              \
    {                               \
        kprintf(__VA_ARGS__);       \
    } while(0)
    
/* 不使用调试日志 */
#else
#define ULOG(...) NULL
#endif

#endif
