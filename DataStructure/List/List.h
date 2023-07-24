#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType Data;
	struct ListNode* Next;
	struct ListNode* Prev;
}LTNode;

LTNode* ListInti();
void ListPushBack(LTNode* Phead, LTDataType x);
void ListPrint(LTNode* Phead);
void ListPushBack(LTNode* Phead, LTDataType x);
void ListPopBack(LTNode* Phead);
void ListPushFront(LTNode* Phead, LTDataType x);
void ListPopFront(LTNode* Phead);
LTNode* BuildNewNode(LTDataType x);
LTNode* FindListPos(LTNode* Phead, LTDataType x);
void ListInsertFront(LTNode* pos, LTDataType x);
void ListInsertBack(LTNode* pos, LTDataType x);
void ListErase(LTNode* pos);
void ListDestroy(LTNode* Phead);