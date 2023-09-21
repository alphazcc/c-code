#include "stack.h"

void StackInit(Stack_t* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

void StackDestory(Stack_t* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}

void StackPush(Stack_t* ps, STDateType value)
{
    assert(ps);
    if (ps->capacity == ps->top)
    {
        int NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDateType* temp = (STDateType *)realloc(ps->a, sizeof(STDateType) * NewCapacity);
        if (temp == NULL)
        {
            printf("realloc failed");
            exit(-1);
        }
        ps->a = temp;
        ps->capacity = NewCapacity;
    }
    ps->a[ps->top] = value;
    ps->top++;
}

void StackPop(Stack_t* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    ps->top--;
}

STDateType StackTop(Stack_t* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}

bool StackEmpty(Stack_t* ps)
{
    assert(ps);
    return ps->top == 0;
}

int StackSize(Stack_t* ps)
{
    assert(ps);
    return ps->top;
}
