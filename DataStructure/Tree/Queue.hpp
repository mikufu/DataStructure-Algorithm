#pragma once
#include <iostream>
#define MAXSIZE 50

using namespace std;

template<class DataType>
class Queue
{
private:
	DataType* queue;
	size_t front;
	size_t rear;

public:
	Queue()
	{
		queue = new DataType[MAXSIZE];
		front = 0;
		rear = 0;
	}

	void enQueue(const DataType& qu)
	{
		if (rear == MAXSIZE)
			return;
		else
			queue[rear++] = qu;
	}

	DataType dequeue()
	{
		if (rear != front)
		{
			return queue[front++];
		}
		return NULL;
	}

	bool QueueEmpty()
	{
		if (rear == front)
		{
			return true;
		}
		else
			return false;
	}

};