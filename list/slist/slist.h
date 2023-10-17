#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
    SLTDateType data;
    struct SListNode* next;
} SListNode;

// 动态申请一个节点
SListNode* CreateSListNode(SLTDateType x);
// 单链表打印
void SListPrint(SListNode* plist);
// 单链表的尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);
// 单链表的头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
// 单链表在pos位置前插入一个节点
void SListInsertBefore(SListNode** pphead, SListNode* pos, SLTDateType x);
// 单链表在pos位置之后插入一个节点
void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的一个节点
void SListEraseAfter(SListNode* pos);
// 单链表删除pos结点
void SListErese(SListNode** pphead, SListNode* pos);
// 单链表的销毁
void SListDestroy(SListNode** pplist);

