#pragma once

#define FALSE 0;
#define TURE 1;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType Data;
	struct SListNode* Next;
}SLTNode;

typedef struct RandomList
{
	SLTDataType data;
	struct RandomList* next;
	struct RandomList* random;
}RL;

void SLTPrint(SLTNode* Phead);
void SLTPushBack(SLTNode** PPhead, SLTDataType x);
void SLTPushFront(SLTNode** PPhead, SLTDataType x);
SLTNode* BuildListNode(SLTDataType x);
void SLTPopBack(SLTNode** PPhead);
void SLTPopFront(SLTNode** PPhead);
SLTNode* SLTFind(SLTNode* Phead, SLTDataType x);
void SLTInsertFront(SLTNode** PPhead, SLTNode* pos, SLTDataType x);
void SLTInsertBack(SLTNode* pos, SLTDataType x);
void SLTErase(SLTNode** PPhead, SLTNode** pos);
void SLTDestroy(SLTNode** PPhead);
SLTNode* RemoveElements(SLTNode* Phead, SLTDataType x);
void SLTEraseAfter(SLTNode* pos);
SLTNode* SLTReverse1(SLTNode* Phead);
SLTNode* SLTReverse2(SLTNode* Phead);
SLTNode* MiddleNode(SLTNode* Phead);
SLTNode* FindKthtoTail(SLTNode* Phead, size_t k);
SLTNode* MergeTwoList1(SLTNode* L1, SLTNode* L2);
SLTNode* MergeTwoList2(SLTNode* L1, SLTNode* L2);
SLTNode* Partition1(SLTNode* Phead, int K);
SLTNode* Partition2(SLTNode* Phead, int K);
_Bool chkPalindrom(SLTNode* Phead);
SLTNode* getIntersectionNode(SLTNode* HeadA, SLTNode* HeadB);
SLTNode* detectCycle(SLTNode* Phead);
RL* CopyRandomList(RL* Phead);