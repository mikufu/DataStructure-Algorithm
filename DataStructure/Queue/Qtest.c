#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void Queuetest1()
{
	Queue que;
	QueueInit(&que);
	QueuePush(&que, 1);
	QueuePush(&que, 2);
	QueuePush(&que, 3);
	QueuePush(&que, 4);
	QueuePush(&que, 5);
	QueuePush(&que, 6);
	while (que.Head)
	{
		printf("%d ", que.Head->Data);
		QueuePop(&que);
	}
	//QueueDestroy(&que);
}

Queuetest2()
{
	Queue que;
	QueueInit(&que);
	QueuePush(&que, 1);
	QueuePush(&que, 2);
	QueuePush(&que, 3);
	QueuePush(&que, 4);
	QueuePush(&que, 5);
	QueuePush(&que, 6);
	QDataType front = QueueFront(&que);
	printf("%d\n", front);
	QDataType back = QueueBack(&que);
	printf("%d\n", back);
	if (QueueEmpty(&que))
	{
		printf("队列为空\n");
	}
	else
	{
		printf("队列大小为%d\n", QueueSize(&que));
	}
	QueueDestroy(&que);
}

int main()
{
	//Queuetest1();
	Queuetest2();
	return 0;
}