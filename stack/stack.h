#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int STDateType;
typedef struct Stack
{
    STDateType* a;
    int top;
    int capacity;
} Stack_t;

void StackInit(Stack_t* ps);
void StackDestory(Stack_t* ps);
void StackPush(Stack_t* ps, STDateType value);
void StackPop(Stack_t* ps);
STDateType StackTop(Stack_t* ps);
bool StackEmpty(Stack_t* ps);
int StackSize(Stack_t* ps);
