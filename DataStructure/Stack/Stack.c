#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if ((ps->top) == (ps->capacity))
	{
		int Newcapacity = (ps->capacity == 0) ? 4 : (ps->capacity) * 2;
		ST* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * Newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail!\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = Newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	return (ps->top == 0);
}

void StackPrint(ST* ps)
{
	assert(ps);
	int i = 0;
	for (i = (ps->top - 1); i >= 0; i--)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}