#include "stack.h"

int main(void) 
{
    Stack_t st;
    StackInit(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    StackPush(&st, 4);
    StackPush(&st, 5);

    printf("stack size: %d \n", StackSize(&st));
    while (!StackEmpty(&st))
    {
        printf("%d ", StackTop(&st));
        StackPop(&st);
    }
    printf("\n");
    StackDestory(&st);

    system("Pause");
    return 0;
}