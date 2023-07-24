#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void Ltest1()
{
	LTNode* Phead = ListInti();
	ListPushBack(Phead, 1);
	ListPushBack(Phead, 2);
	ListPushBack(Phead, 3);
	ListPushBack(Phead, 4);
	ListPushBack(Phead, 5);
	ListPushBack(Phead, 6);
	ListPrint(Phead);
	ListPopBack(Phead);
	ListPopBack(Phead);
	ListPopBack(Phead);
	ListPrint(Phead);
	ListPopFront(Phead);
	ListPopFront(Phead);
	ListPrint(Phead);
	ListPushFront(Phead, 4);
	ListPushFront(Phead, 5);
	ListPushFront(Phead, 6);
	ListPrint(Phead);
}

void Ltest2()
{
	LTNode* Phead = ListInti();
	ListPushBack(Phead, 1);
	ListPushBack(Phead, 2);
	ListPushBack(Phead, 3);
	ListPushBack(Phead, 4);
	ListPushBack(Phead, 5);
	ListPushBack(Phead, 6);
	ListPrint(Phead);
	LTNode* pos = FindListPos(Phead, 3);
	if (pos)
	{
		ListInsertBack(pos, 30);
		ListInsertFront(pos, 20);
	}
	ListPrint(Phead);
	ListErase(pos);
	ListPrint(Phead);
	ListDestroy(Phead);
	Phead = NULL;
}

int main()
{
	//Ltest1();
	Ltest2();
	return 0;
}