#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void Stest1()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPrint(&st);
	int size = StackSize(&st);
	printf("%d\n", size);
	int top = StackTop(&st);
	printf("%d\n", top);
	StackDestroy(&st);
}

void Stack2()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	while (!StackEmpty(&st))
	{
		printf("%d ", st.a[st.top - 1]);
		StackPop(&st);
	}
	StackDestroy(&st);
}

//int main()
//{
//	//Stest1();
//	//Stack2();
//	return 0;
//}