#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void QueueInit(Queue* PQ)
{
	assert(PQ);
	PQ->Head = NULL;
	PQ->Tail = NULL;
}

void QueueDestroy(Queue* PQ)
{
	assert(PQ);
	assert(PQ->Head);
	while (PQ->Head)
	{
		QueueNode* head = PQ->Head;
		PQ->Head = PQ->Head->Next;
		free(head);
		head = NULL;
	}
	PQ->Tail = NULL;
}

void QueuePush(Queue* PQ, QDataType x)
{
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	if (PQ->Head == NULL)
	{
		PQ->Head = PQ->Tail = tmp;
		PQ->Tail->Data = x;
		PQ->Tail->Next = NULL;
		return;
	}
	PQ->Tail->Next = tmp;
	PQ->Tail = PQ->Tail->Next;
	PQ->Tail->Data = x;
	PQ->Tail->Next = NULL;
}

void QueuePop(Queue* PQ)
{
	assert(PQ);
	QueueNode* head = PQ->Head;
	PQ->Head = PQ->Head->Next;
	free(head);
	head = NULL;
	if (PQ->Head == NULL)
		PQ->Tail = NULL;
}

QDataType QueueFront(Queue* PQ)
{
	assert(PQ);
	assert(PQ->Head);
	return (PQ->Head->Data);
}

QDataType QueueBack(Queue* PQ)
{
	assert(PQ);
	assert(PQ->Tail);
	return (PQ->Tail->Data);
}

int QueueSize(Queue* PQ)
{
	assert(PQ);
	QueueNode* cur = PQ->Head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->Next;
	}
	return count;
}

bool QueueEmpty(Queue* PQ)
{
	assert(PQ);
	return (!PQ->Head);
}