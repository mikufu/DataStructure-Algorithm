#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SLTest1()
{
	SLTNode* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 3);
	SLTPushBack(&Phead, 4);
	SLTPushBack(&Phead, 5);
	SLTPrint(Phead);
	SLTPushFront(&Phead, 1);
	SLTPushFront(&Phead, 2);
	SLTPushFront(&Phead, 3);
	SLTPushFront(&Phead, 4);
	SLTPushFront(&Phead, 5);
	SLTPrint(Phead);
}

void SLTest2()
{
	SLTNode* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 3);
	SLTPushBack(&Phead, 4);
	SLTPushBack(&Phead, 5);
	SLTPrint(Phead);
	SLTPopBack(&Phead);
	//SLTPopBack(&Phead);
	//SLTPopBack(&Phead);
	//SLTPopBack(&Phead);
	//SLTPopBack(&Phead);
	//SLTPopBack(&Phead);
	SLTPopFront(&Phead);
	SLTPopFront(&Phead);
	//SLTPopFront(&Phead);
	//SLTPopFront(&Phead);
	//SLTPopFront(&Phead);
	SLTPrint(Phead);
}

void SLTest3()
{
	SLTNode* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 3);
	SLTPushBack(&Phead, 4);
	SLTPushBack(&Phead, 5);
	SLTPrint(Phead);
	SLTNode* pos = SLTFind(Phead, 2);
	if (pos)
	{
		pos->Data = 20;
	}
	SLTPrint(Phead);
	pos = SLTFind(Phead, 0);
	if (pos)
	{
		pos->Data = 20;
	}
	SLTPrint(Phead);
}

void SLTest4()
{
	SLTNode* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 3);
	SLTPushBack(&Phead, 4);
	SLTPushBack(&Phead, 5);
	SLTPrint(Phead);
	SLTNode* pos = SLTFind(Phead, 3);
	if (pos)
	{
		SLTInsertFront(&Phead, pos, 30);
	}
	SLTPrint(Phead);
	pos = SLTFind(Phead, 1);
	if (pos)
	{
		SLTInsertBack(pos, 10);
	}
	SLTPrint(Phead);
	pos = SLTFind(Phead, 1);
	if (pos)
	{
		SLTEraseAfter(pos);
	}
	SLTPrint(Phead);
	pos = SLTFind(Phead, 1);
	if (pos)
	{
		SLTErase(&Phead, &pos);
	}
	SLTPrint(Phead);
	SLTDestroy(&Phead);
}

void SLTest5()
{
	SLTNode* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 3);
	SLTPushBack(&Phead, 4);
	SLTPushBack(&Phead, 5);
	SLTPushBack(&Phead, 5);
	SLTPushBack(&Phead, 3);
	SLTPushBack(&Phead, 5);
	SLTPushBack(&Phead, 3);
	SLTPrint(Phead);
	Phead = RemoveElements(Phead, 3);
	SLTPrint(Phead);
	Phead = RemoveElements(Phead, 5);
	SLTPrint(Phead);
	Phead = RemoveElements(Phead, 1);
	SLTPrint(Phead);
	SLTDestroy(&Phead);
}

void SLTest6()
{
	SLTNode* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 3);
	SLTPushBack(&Phead, 4);
	SLTPushBack(&Phead, 5);
	SLTPrint(Phead);
	Phead = SLTReverse2(Phead);
	SLTPrint(Phead);
	Phead = SLTReverse1(Phead);
	SLTPrint(Phead);
	SLTDestroy(&Phead);
}

void SLTest7()
{
	SLTNode* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 3);
	SLTPushBack(&Phead, 4);
	SLTPushBack(&Phead, 5);
	SLTPushBack(&Phead, 6);
	SLTPrint(Phead);
	SLTNode* middle = MiddleNode(Phead);
	SLTPrint(middle);
	int k = 0;
	SLTNode* KthtoTail = FindKthtoTail(Phead, k);
	SLTPrint(KthtoTail);
	SLTDestroy(&Phead);
	SLTDestroy(&KthtoTail);
}

SLTest8()
{
	SLTNode* Phead1 = NULL;
	SLTPushBack(&Phead1, 1);
	SLTPushBack(&Phead1, 2);
	SLTPushBack(&Phead1, 3);
	SLTPushBack(&Phead1, 4);
	SLTPushBack(&Phead1, 5);
	SLTPushBack(&Phead1, 6);
	SLTPrint(Phead1);
	SLTNode* Phead2 = NULL;
	SLTPushBack(&Phead2, 2);
	SLTPushBack(&Phead2, 3);
	SLTPushBack(&Phead2, 4);
	SLTPrint(Phead2);
	SLTNode* NewHead = MergeTwoList1(Phead1, Phead2);
	SLTPrint(NewHead);
	SLTDestroy(&NewHead);
}

void SLTest9()
{
	SLTNode* Phead1 = NULL;
	SLTPushBack(&Phead1, 1);
	SLTPushBack(&Phead1, 2);
	SLTPushBack(&Phead1, 2);
	SLTPushBack(&Phead1, 5);
	SLTPushBack(&Phead1, 7);
	SLTPrint(Phead1);
	SLTNode* Phead2 = NULL;
	SLTPushBack(&Phead2, 1);
	SLTPushBack(&Phead2, 3);
	SLTPushBack(&Phead2, 4);
	SLTPushBack(&Phead2, 6);
	SLTPrint(Phead2);
	SLTNode* NewHead = MergeTwoList2(Phead1, Phead2);
	SLTPrint(NewHead);
	SLTDestroy(&NewHead);
}

void SLTest10()
{
	SLTNode* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 5);
	SLTPushBack(&Phead, 7);
	SLTPushBack(&Phead, 8);
	SLTPushBack(&Phead, 6);
	SLTPushBack(&Phead, 4);
	SLTPrint(Phead);
	SLTNode* partition = Partition1(Phead, 4);
	SLTPrint(partition);
	SLTDestroy(&partition);
}

void SLTest11()
{
	SLTNode* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 5);
	SLTPushBack(&Phead, 7);
	SLTPushBack(&Phead, 8);
	SLTPushBack(&Phead, 6);
	SLTPushBack(&Phead, 4);
	SLTPrint(Phead);
	SLTNode* partition = Partition2(Phead, 4);
	SLTPrint(partition);
	SLTDestroy(&partition);
}

void SLTest12()
{
	SLTNode* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 5);
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 5);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 1);
	SLTPrint(Phead);
	if (chkPalindrom(Phead))
	{
		printf("是回文链表\n");
	}
	else
	{
		printf("不是回文链表\n");
	}
	SLTDestroy(&Phead);
}

void SLTest13()
{
	SLTNode* Phead1 = NULL;
	SLTPushBack(&Phead1, 1);
	SLTPushBack(&Phead1, 2);
	SLTPushBack(&Phead1, 2);
	SLTPushBack(&Phead1, 5);
	SLTPushBack(&Phead1, 7);
	SLTPrint(Phead1);
	SLTNode* Phead2 = NULL;
	SLTPushBack(&Phead2, 1);
	SLTPushBack(&Phead2, 3);
	SLTPushBack(&Phead2, 4);
	SLTPrint(Phead2);

	SLTNode* tail1 = Phead1;
	SLTNode* tail2 = Phead2;

	while (tail1->Next)
		tail1 = tail1->Next;

	while (tail2->Next)
		tail2 = tail2->Next;

	SLTNode* Phead3 = NULL;
	SLTPushBack(&Phead3, 0);
	SLTPushBack(&Phead3, 4);
	SLTPushBack(&Phead3, 6);
	
	tail1->Next = Phead3;
	tail2->Next = Phead3;

	SLTPrint(Phead1);
	SLTPrint(Phead2);

	SLTNode* p = getIntersectionNode(Phead1, Phead2);
	if (p)
	{
		printf("链表相交部分:>");
		SLTPrint(p);
		printf("是相交链表\n");
	}
	else
		printf("不是相交链表\n");
}

void SLTest14()
{
	SLTNode* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 3);
	SLTPushBack(&Phead, 4);
	SLTPushBack(&Phead, 5);
	SLTPushBack(&Phead, 6);
	SLTPushBack(&Phead, 7);
	SLTPushBack(&Phead, 8);
	SLTPushBack(&Phead, 9);
	SLTPrint(Phead);

	SLTNode* tail = SLTFind(Phead, 9);
	SLTNode* node = SLTFind(Phead, 5);
	tail->Next = node;
	
	SLTNode* IsCycle = detectCycle(Phead);
	if (IsCycle)
	{
		printf("链表中有环\n");
		printf("环入口的值为%d\n", IsCycle->Data);
	}
	else
		printf("链表无环\n");
}

void SLTest15()
{
	RL* Phead = NULL;
	SLTPushBack(&Phead, 1);
	SLTPushBack(&Phead, 2);
	SLTPushBack(&Phead, 3);
	SLTPushBack(&Phead, 4);
	SLTPushBack(&Phead, 5);
	SLTPushBack(&Phead, 6);
	SLTPushBack(&Phead, 7);
	SLTPushBack(&Phead, 8);
	SLTPushBack(&Phead, 9);
	SLTPrint(Phead);
	RL* pos1 = SLTFind(Phead, 2);
	RL* pos2 = SLTFind(Phead, 3);
	RL* pos3 = SLTFind(Phead, 4);
	RL* pos4 = SLTFind(Phead, 5);
	RL* pos5 = SLTFind(Phead, 6);
	RL* pos6 = SLTFind(Phead, 7);
	RL* pos7 = SLTFind(Phead, 8);
	RL* pos8 = SLTFind(Phead, 9);
	Phead->random = NULL;
	pos1->random = pos3;
	pos2->random = Phead;
	pos3->random = pos2;
	pos4->random = pos4;
	pos5->random = pos8;
	pos6->random = pos5;
	pos7->random = pos1;
	pos8->random = pos6;
	RL* newhead = CopyRandomList(Phead);
	SLTPrint(newhead);
}

//int main()
//{
//	//SLTest1();
//	//SLTest2();
//	//SLTest3();
//	//SLTest4();
//	//SLTest5();
//	//SLTest6();
//	//SLTest7();
//	//SLTest8();
//	//SLTest9();
//	//SLTest10();
//	//SLTest11();
//	//SLTest12();
//	//SLTest13();
//	//SLTest14();
//	//SLTest15();
//	return 0;
//}
