/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 */

 /*
  * In your C/C++ file, include this header file.
  *
  * #define DBG_TAG           "MOD_TAG"
  * #define DBG_LVL           DBG_INFO
  * #include "dbg_log.h"      // must after of DBG_LVL, DBG_TAG or other options
  *
  * Then in your C/C++ file, you can use LOG_X macro to print out logs:
  * LOG_D("this is a debug log!");
  * LOG_E("this is a error log!");
  */

#ifndef __DBG_LOG_H__
#define __DBG_LOG_H__

#include <stdio.h>
#define kprintf printf

#ifdef __cplusplus
extern "C" {
#endif

#define DBG_ENABLE
#define DBG_COLOR

#ifdef DBG_ENABLE

/* DEBUG level */
#define DBG_SILENT          0
#define DBG_ERROR           1
#define DBG_WARNING         2
#define DBG_INFO            3
#define DBG_DEBUG           4

#ifdef DBG_TAG
#ifndef DBG_SECTION_NAME
#define DBG_SECTION_NAME    DBG_TAG
#endif
#endif /* DBG_TAG */

#ifdef DBG_LVL
#ifndef DBG_LEVEL
#define DBG_LEVEL           DBG_LVL
#endif
#endif /* DBG_LVL */

/*
 * The color for terminal (foreground)
 * BLACK    30
 * RED      31
 * GREEN    32
 * YELLOW   33
 * BLUE     34
 * PURPLE   35
 * CYAN     36
 * WHITE    37
 */
#ifdef DBG_COLOR
#define _DBG_COLOR(n)       kprintf("\033["#n"m")
#define _DBG_LOG_HDR(lvl_name, color_n)                     \
    kprintf("\033["#color_n"m[" lvl_name "/" DBG_SECTION_NAME "] ")
#define _DBG_LOG_X_END                                      \
    kprintf("\033[0m\n")
#else
#define _DBG_COLOR(n)
#define _DBG_LOG_HDR(lvl_name, color_n)                     \
    kprintf("[" lvl_name "/" DBG_SECTION_NAME "] ")
#define _DBG_LOG_X_END                                      \
    kprintf("\n")
#endif /* DBG_COLOR */

#define dbg_log(level, fmt, ...)                            \
    if ((level) <= DBG_LEVEL)                               \
    {                                                       \
        _DBG_COLOR(1);                                      \
        switch(level)                                       \
        {                                                   \
            case DBG_ERROR:   _DBG_LOG_HDR("E", 31); break; \
            case DBG_WARNING: _DBG_LOG_HDR("W", 33); break; \
            case DBG_INFO:    _DBG_LOG_HDR("I", 32); break; \
            case DBG_DEBUG:   _DBG_LOG_HDR("D", 0); break;  \
            default: break;                                 \
        }                                                   \
        kprintf(fmt, ##__VA_ARGS__);                        \
        _DBG_COLOR(0);                                      \
    }

#define dbg_here                                            \
    if ((DBG_LEVEL) <= DBG_DEBUG){                          \
        kprintf("[" DBG_SECTION_NAME "] "                   \
            "File: %s Func: %s Line: %d\n",                 \
            __FILE__, __FUNCTION__, __LINE__);              \
    }

#define dbg_log_line(lvl, color_n, fmt, ...)                \
    do                                                      \
    {                                                       \
        _DBG_COLOR(1);                                      \
        _DBG_LOG_HDR(lvl, color_n);                         \
        kprintf(fmt, ##__VA_ARGS__);                        \
        _DBG_COLOR(0);                                      \
    }                                                       \
    while (0)

#define dbg_raw(...)        kprintf(__VA_ARGS__);

#else
#define dbg_log(level, fmt, ...)
#define dbg_here
#define dbg_log_line(lvl, color_n, fmt, ...)
#define dbg_raw(...)
#endif /* DBG_ENABLE */

#if (DBG_LEVEL >= DBG_DEBUG)
#define LOG_D(fmt, ...)     dbg_log_line("D", 0, fmt, ##__VA_ARGS__)
#else
#define LOG_D(...)
#endif

#if (DBG_LEVEL >= DBG_INFO)
#define LOG_I(fmt, ...)     dbg_log_line("I", 32, fmt, ##__VA_ARGS__)
#else
#define LOG_I(...)
#endif

#if (DBG_LEVEL >= DBG_WARNING)
#define LOG_W(fmt, ...)     dbg_log_line("W", 33, fmt, ##__VA_ARGS__)
#else
#define LOG_W(...)
#endif

#if (DBG_LEVEL >= DBG_ERROR)
#define LOG_E(fmt, ...)     dbg_log_line("E", 31, fmt, ##__VA_ARGS__)
#else
#define LOG_E(...)
#endif

#define DBG_LOG(level, fmt, ...)   dbg_log(level, fmt, __VA_ARGS__) 

#define DBG_HERE            dbg_here

#define LOG_RAW(...)        dbg_raw(__VA_ARGS__)

#define LOG_HEX(name, width, buf, size)

#ifdef __cplusplus
}
#endif

#endif /* __DBG_LOG_H__ */