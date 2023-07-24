#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqlistTest1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPrint(&s1);
	SeqListDestroy(&s1);
}

void SeqlistTest2()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPrint(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);
	SeqListDestroy(&s1);
}

void SeqlistTest3()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPrint(&s1);
	SeqListFind(&s1, 10);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);
	SeqListFind(&s1, 10);
	SeqListDestroy(&s1);
}

void SeqlistTest4()
{

	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	SeqListInsert(&s1, 22, 2);
	SeqListInsert(&s1, 28, 3);
	SeqListInsert(&s1, 24, 1);
	SeqListInsert(&s1, 10, 4);
	SeqListPrint(&s1);
	SeqListDestroy(&s1);
}

void SeqlistTest5()
{

	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	SeqListErase(&s1, 2);
	SeqListErase(&s1, 1);
	SeqListPrint(&s1);
	SeqListDestroy(&s1);
}

void SeqlistTest6()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPrint(&s1);
	int pos = SeqListFind(&s1, 0);
	if (pos != -1)
	{
		printf("删除下标%d位置的数字\n", pos);
		SeqListErase(&s1, pos);
	}
	SeqListPrint(&s1);
	pos = SeqListFind(&s1, 10);
	if (pos != -1)
	{
		printf("删除%d位置的数字\n", pos);
		SeqListErase(&s1, pos);
	}
	SeqListPrint(&s1);
	SeqListDestroy(&s1);
}

int main()
{
	//SeqlistTest1();
	//SeqlistTest2();
	//SeqlistTest3();
	//SeqlistTest4();
	//SeqlistTest5();
	SeqlistTest6();
	return 0;
 }