#pragma once
#include <iostream>

using namespace std;

template<class DataType>
class Stack
{
private:
	DataType* arr;
	size_t capacity;
	size_t top;
public:
	Stack()
	{
		arr = NULL;
		capacity = 0;
		top = 0;
	}

	Stack(Stack<DataType>& S)
	{
		this->capacity = S.capacity;
		this->arr = new DataType[capacity];
		for (int i = 0; i < S.top; i++)
		{
			this->arr[this->top++] = S.arr[i];
		}
	}

	void Push_Back(DataType data)
	{
		if (this->top == this->capacity)
		{
			this->capacity = this->capacity ? 2 * this->capacity : 4;
			this->arr = new DataType[this->capacity];
		}
		this->arr[top++] = data;
	}

	DataType Pop_Back()
	{
		if (this->top)
		{
			this->top--;
			return arr[top];
		}
		return 0;
	}

	bool StackEmpty()
	{
		if (top)
			return false;
		else
			return true;
	}

};