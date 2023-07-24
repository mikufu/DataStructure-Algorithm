#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* Next;
	QDataType Data;
}QueueNode;

typedef struct Queue
{
	QueueNode* Head;
	QueueNode* Tail;
}Queue;

void QueueInit(Queue* PQ);
void QueueDestroy(Queue* PQ);
void QueuePush(Queue* PQ, QDataType x);
void QueuePop(Queue* PQ);
QDataType QueueFront(Queue* PQ);
QDataType QueueBack(Queue* PQ);
int QueueSize(Queue* PQ);
bool QueueEmpty(Queue* PQ);