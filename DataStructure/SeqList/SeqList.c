#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int NewCapacity = (ps->capacity ? 2 * (ps->capacity) : 4);
		SLDataType* tmp = (SLDataType*)realloc(ps->a, NewCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("扩容失败!\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = NewCapacity;
	}
}

void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	SeqListInsert(ps, x, ps->size);
}

void SeqListPopBack(SL* ps)
{
	SeqListErase(ps, (ps->size - 1));
}
void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	SeqListInsert(ps, x, 0);
}

void SeqListPopFront(SL* ps)
{
	SeqListErase(ps, 0);
}

int SeqListFind(SL* ps, SLDataType x)
{
	int i = 0;
	int flag = -1;
	printf("要寻找的数字为:>%d\n", x);
	for (i = 0; i < ps->size; i++)
	{
		if (x == ps->a[i])
			flag = 1;
		if (flag == 1)
		{
			printf("找到了,下标为:>%d\n", i);
			return i;
		}
	}
	printf("没有找到!\n");
	return -1;
}

void SeqListInsert(SL* ps, SLDataType x, size_t pos)
{
	assert(pos >= 0 && pos <= (ps->size));
	SeqListCheckCapacity(ps);
	memmove(ps->a + pos + 1, ps->a + pos, ((ps->size) - pos) * sizeof(SLDataType));
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, size_t pos)
{
	assert((ps->size) > pos && pos >= 0);
	memmove((ps->a + pos), (ps->a + pos + 1), ((ps->size) - pos) * sizeof(SLDataType));
	ps->size--;
}