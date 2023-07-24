#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

LTNode* ListInti()
{
	LTNode* Phead = (LTNode*)malloc(sizeof(LTNode));
	if (!Phead)
		exit(-1);
	Phead->Next = Phead;
	Phead->Prev = Phead;
	return Phead;
}

void ListPrint(LTNode* Phead)
{
	assert(Phead);
	LTNode* cur = Phead->Next;
	while (cur != Phead)
	{
		printf("%d ", cur->Data);
		cur = cur->Next;
	}
	printf("\n");
}

LTNode* BuildNewNode(LTDataType x)
{
	LTNode* NewNode = (LTNode*)malloc(sizeof(LTNode));
	if (!NewNode)
		exit(-1);
	NewNode->Data = x;
	NewNode->Next = NULL;
	NewNode->Prev = NULL;
	return NewNode;
}

void ListPushBack(LTNode* Phead, LTDataType x)
{
	/*assert(Phead);
	LTNode* NewNode = BuildNewNode(x);
	NewNode->Data = x;
	LTNode* tail = Phead->Prev;
	tail->Next = NewNode;
	NewNode->Prev = tail;
	NewNode->Next = Phead;
	Phead->Prev = NewNode;*/
	ListInsertFront(Phead, x);
}

void ListPopBack(LTNode* Phead)
{
	assert(Phead);
	assert(Phead != (Phead->Next));
	////if ((Phead->Next) == (Phead))
	//	//return;
	//LTNode* tail = Phead->Prev;
	//tail = tail->Prev;
	//free(tail->Next);
	//tail->Next = Phead;
	//Phead->Prev = tail;
	ListErase(Phead->Prev);
}

void ListPushFront(LTNode* Phead, LTDataType x)
{
	/*assert(Phead);
	LTNode* NewNode = BuildNewNode(x);
	NewNode->Data = x;
	LTNode* FirstNode = Phead->Next;
	Phead->Next = NewNode;
	NewNode->Prev = Phead;
	NewNode->Next = FirstNode;
	FirstNode->Prev = NewNode;*/
	ListInsertBack(Phead, x);
}

void ListPopFront(LTNode* Phead)
{
	assert(Phead);
	assert(Phead != (Phead->Prev));
	//if ((Phead->Next) == (Phead))
		//return;
	/*LTNode* FirstNode = Phead->Next;
	Phead->Next = FirstNode->Next;
	FirstNode->Next->Prev = Phead;
	free(FirstNode);
	FirstNode = NULL;*/
	ListErase(Phead->Next);
}

LTNode* FindListPos(LTNode* Phead, LTDataType x)
{
	LTNode* pos = Phead->Next;
	while (pos != Phead)
	{
		if ((pos->Data) == x)
			return pos;
		pos = pos->Next;
	}
	return NULL;
}

void ListInsertFront(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* front = pos->Prev;
	LTNode* NewNode = BuildNewNode(x);
	front->Next = NewNode;
	NewNode->Prev = front;
	NewNode->Next = pos;
	pos->Prev = NewNode;
}

void ListInsertBack(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* back = pos->Next;
	LTNode* NewNode = BuildNewNode(x);
	back->Prev = NewNode;
	NewNode->Next = back;
	NewNode->Prev = pos;
	pos->Next = NewNode;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	pos->Prev->Next = pos->Next;
	pos->Next->Prev = pos->Prev;
	free(pos);
	pos = NULL;
}

void ListDestroy(LTNode* Phead)
{
	assert(Phead);
	LTNode* cur = Phead->Next;
	while (cur != Phead)
	{
		LTNode* curNext = cur->Next;
		free(cur);
		cur = curNext;
	}
	free(Phead);
	Phead = NULL;
}