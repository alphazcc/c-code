#include "SList.h"

int main()
{
    SListNode* list = CreateSListNode(2);
    SListPrint(list);

    SListPushBack(&list, 3);
    SListPushBack(&list, 5);
    SListPushBack(&list, 6);
    SListPrint(list);

    SListPopBack(&list);
    SListPrint(list);

    SListPushFront(&list, 1);
    SListPushFront(&list, 0);
    SListPrint(list);

    SListPopFront(&list);
    SListPrint(list);

    SListInsertBefore(&list, SListFind(list, 5), 4);
    SListPrint(list);

    SListInsertAfter(SListFind(list, 5), 88);
    SListPrint(list);

    SListEraseAfter(SListFind(list, 5));
    SListPrint(list);

    SListErese(&list, SListFind(list, 5));
    SListPrint(list);

    SListDestroy(&list);

    return 0;
}
