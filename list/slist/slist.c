#include "SList.h"

// 无头单向非循环链表

// 动态申请一个节点
SListNode* CreateSListNode(SLTDateType x)
{
    SListNode* node = (SListNode*)malloc(sizeof(SListNode));
    if (node == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    SListNode* Phead = node;
    Phead->data = x;
    Phead->next = NULL;
    return Phead;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
    SListNode* tail = plist;
    while (tail)
    {
        printf("%d->", tail->data);
        tail = tail->next;

    }
    printf("NULL\n");
}

// 单链表的尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
    SListNode* newnode = CreateSListNode(x);
    if (*pplist == NULL)
    {
        *pplist = newnode;
    }
    else
    {
        SListNode* tail = *pplist;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
    assert(*pplist);
    if ((*pplist)->next == NULL)
    {
        free(*pplist);
        *pplist = NULL;
    }
    else
    {
        SListNode* tail = *pplist;
        while (tail->next->next)
        {
            tail = tail->next;
        }
        free(tail->next);
        tail->next = NULL;
    }
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
    SListNode* newnode = CreateSListNode(x);
    if (*pplist == NULL)
    {
        *pplist = newnode;
    }
    else
    {
        newnode->next = *pplist;
        *pplist = newnode;
    }
}

// 单链表的头删
void SListPopFront(SListNode** pplist)
{
    assert(*pplist);

    if ((*pplist)->next == NULL)
    {
        free(*pplist);
        *pplist = NULL;
    }
    else
    {
        SListNode* head = (*pplist)->next;
        free(*pplist);
        *pplist = head;
    }
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
    assert(plist);
    SListNode* list = plist;
    while (list)
    {
        if (list->data == x)
        {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

//单链表在pos位置前插入一个节点
void SListInsertBefore(SListNode** pphead, SListNode* pos, SLTDateType x)
{
    //pos在第一个节点，相当与头插
    if (*pphead == pos)
    {
        SListPushFront(pphead, x);
    }
    else
    {
        SListNode* list = *pphead;
        while (list->next != pos)
        {
            list = list->next;
        }
        list->next = CreateSListNode(x);
        list->next->next = pos;
    }
}

// 单链表在pos位置之后插入一个节点
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
    assert(pos);
    SListNode* newnode = CreateSListNode(x);
    newnode->next = pos->next;
    pos->next = newnode;
}

// 单链表删除pos位置之后的一个节点
void SListEraseAfter(SListNode* pos)
{
    assert(pos);
    if (pos->next == NULL)
    {
        return;
    }
    SListNode* list = pos->next;
    pos->next = list->next;
    free(list);
}

// 单链表删除pos结点
void SListErese(SListNode** pphead, SListNode* pos)
{
    if (*pphead == pos)
    {
        SListPopFront(pphead);
    }
    else
    {
        SListNode* list = *pphead;
        while (list->next != pos)
        {
            list = list->next;
        }
        list->next = pos->next;
        free(pos);
    }
}

// 单链表的销毁
void SListDestroy(SListNode** pplist)
{
    assert(*pplist);

    while (*pplist)
    {
        SListNode* list = (*pplist)->next;
        free(*pplist);
        *pplist = list;
    }
    *pplist = NULL;
}
