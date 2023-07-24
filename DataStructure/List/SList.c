#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SLTPrint(SLTNode* Phead)
{
	SLTNode* cur = Phead;
	while (cur != NULL)
	{
		printf("%d->", cur->Data);
		cur = cur->Next;
	}
	printf("NULL\n");
}

SLTNode* BuildListNode(SLTDataType x)
{
	SLTNode* NewNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (NewNode == NULL)
	{
		perror("SLTPushFront");
		exit(-1);
	}
	NewNode->Data = x;
	NewNode->Next = NULL;
	return NewNode;
}

void SLTPushBack(SLTNode** PPhead, SLTDataType x)
{
	assert(PPhead);				//防止传一级指针，便于分析错误
	SLTNode* NewNode = BuildListNode(x);
	if ((*PPhead) == NULL)
	{
		*PPhead = NewNode;
	}
	else
	{
		SLTNode* tail = *PPhead;
		while (tail->Next != NULL)
		{
			tail = tail->Next;
		}
		tail->Next = NewNode;
	}
}

void SLTPushFront(SLTNode** PPhead, SLTDataType x)
{
	SLTNode* NewNode = BuildListNode(x);
	NewNode->Next = *PPhead;
	*PPhead = NewNode;
}

void SLTPopBack(SLTNode** PPhead)
{
	assert(*PPhead);
	if ((*PPhead)->Next)
	{
		SLTNode* tail = *PPhead;
		while (tail->Next->Next)
		{
			tail = tail->Next;
		}
		free(tail->Next);
		tail->Next = NULL;
	}
	else
	{
		free(*PPhead);
		*PPhead = NULL;
	}
}

void SLTPopFront(SLTNode** PPhead)
{
	assert(*PPhead);
	SLTNode* p = *PPhead;
	(*PPhead) = (*PPhead)->Next;
	free(p);
	p = NULL;
}

SLTNode* SLTFind(SLTNode* Phead, SLTDataType x)
{
	assert(Phead);
	while (Phead)
	{
		if ((Phead->Data) == x)
			return Phead;
		else
			Phead = Phead->Next;
	}
	return NULL;
}

void SLTInsertFront(SLTNode** PPhead, SLTNode* pos, SLTDataType x)
{
	assert(*PPhead);
	assert(pos);
	SLTNode* NewNode = BuildListNode(x);
	SLTNode* posPrev = *PPhead;
	if (pos == *PPhead)
	{
		NewNode->Next = *PPhead;
		*PPhead = NewNode;
	}
	else
	{
		while ((posPrev->Next) != pos)
		{
			posPrev = posPrev->Next;
		}
		posPrev->Next = NewNode;
		NewNode->Next = pos;
	}
}

void SLTInsertBack(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* NewNode = BuildListNode(x);
	NewNode->Next = pos->Next;
	pos->Next = NewNode;
}

void SLTErase(SLTNode** PPhead, SLTNode** pos)
{
	assert(*PPhead);
	assert(*pos);
	SLTNode* posPrev = *PPhead;
	if (posPrev == (*pos))
	{
		*PPhead = (*pos)->Next;
	}
	else
	{
		while (posPrev->Next != (*pos))
		{
			posPrev = posPrev->Next;
		}
		posPrev->Next = (*pos)->Next;
	}
	free(*pos);
	(*pos) = NULL;
}

void SLTDestroy(SLTNode** PPhead)
{
	assert(*PPhead);
	SLTNode* p = (*PPhead)->Next;
	while ((*PPhead)->Next)
	{
		free(*PPhead);
		*PPhead = p;
		p = p->Next;
	}
	free(*PPhead);
	*PPhead = NULL;
}

SLTNode* RemoveElements(SLTNode* Phead, SLTDataType x)
{
	assert(Phead);
	SLTNode* cur = Phead;
	SLTNode* prev = Phead;
	while (cur)
	{
		if (cur->Data == x)
		{
			if (cur == Phead)
			{
				Phead = Phead->Next;
				free(cur);
				cur = Phead;
			}
			else
			{
				prev->Next = cur->Next;
				free(cur);
				cur = prev->Next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->Next;
		}
	}
	return Phead;
}

void SLTEraseAfter(SLTNode* pos)
{
	SLTNode* p = pos->Next;
	assert(p);
	pos->Next = pos->Next->Next;
	free(p);
	p = NULL;
}

SLTNode* SLTReverse1(SLTNode* Phead)
{
	if (Phead)
	{
		SLTNode* n1 = NULL;
		SLTNode* n2 = Phead;
		SLTNode* n3 = Phead->Next;
		while (n2)
		{
			n2->Next = n1;
			n1 = n2;
			n2 = n3;
			if (n3)
				n3 = n3->Next;
		}
		return n1;
	}
	else
		return Phead;
}

SLTNode* SLTReverse2(SLTNode* Phead)
{
	SLTNode* cur = Phead;
	SLTNode* curNext = cur;
	SLTNode* NewHead = NULL;
	while (cur)
	{
		curNext = cur->Next;
		cur->Next = NewHead;
		NewHead = cur;
		cur = curNext;
	}
	return NewHead;
}

SLTNode* MiddleNode(SLTNode* Phead)
{
	SLTNode* fast = Phead;
	SLTNode* slow = Phead;
	while (fast && fast->Next)
	{
		fast = fast->Next->Next;
		slow = slow->Next;
	}
	return slow;
}

SLTNode* FindKthtoTail(SLTNode* Phead, size_t K)
{
	if (!Phead)
	{
		return Phead;
	}
	else
	{
		SLTNode* fast = Phead;
		SLTNode* slow = Phead;
		while (fast && (K--))
		{
			fast = fast->Next;
		}
		while (fast)
		{
			fast = fast->Next;
			slow = slow->Next;
		}
		return slow;
	}
}

SLTNode* MergeTwoList1(SLTNode* L1, SLTNode* L2)
{
	SLTNode* head = NULL;
	SLTNode* tail = NULL;
	if (!L1)
		return L2;
	else if (!L2)
		return L1;
	else
	{
		if ((L1->Data) >= (L2->Data))
		{
			head = tail = L2;
			L2 = L2->Next;
		}
		else
		{
			head = tail = L1;
			L1 = L1->Next;
		}
		while (L1 && L2)
		{
			if ((L1->Data) >= (L2->Data))
			{
				tail->Next = L2;
				tail = tail->Next;
				L2 = L2->Next;
			}
			else
			{
					tail->Next = L1;
					tail = tail->Next;
					L1 = L1->Next;
			}
		}
		if (L1)
			tail->Next = L1;
		else
			tail->Next = L2;
	}
	return head;
}

SLTNode* MergeTwoList2(SLTNode* L1, SLTNode* L2)	//带哨兵位
{

	SLTNode* head = NULL;
	SLTNode* tail = NULL;
	SLTNode* list = NULL;
	if (!L1)
		return L2;
	else if (!L2)
		return L1;
	else
	{
		head = tail = (SLTNode*)malloc(sizeof(SLTNode));	//创建新的头节点
		if (!head && !tail)
		{
			perror(" MergeTwoList2");
		}
		else 
		{
			while (L1 && L2)
			{
				if ((L1->Data) >= (L2->Data))
				{
					tail->Next = L2;
					tail = tail->Next;
					L2 = L2->Next;
				}
				else
				{
					tail->Next = L1;
					tail = tail->Next;
					L1 = L1->Next;
				}
			}
			if (L1)
				tail->Next = L1;
			else
				tail->Next = L2;
			list = head->Next;
			free(head);
			head = NULL;
		}
	}
	return list;
}

SLTNode* Partition1(SLTNode* Phead, int K)
{
	SLTNode* LessHead = NULL; SLTNode* LessTail = NULL;
	SLTNode* GreaterHead = NULL; SLTNode* GreaterTail = NULL;
	SLTNode* cur = Phead;

	while (cur)
	{
		if ((cur->Data) > K)
		{
			if (GreaterHead == NULL)
				GreaterHead = GreaterTail = cur;
			else
			{
				GreaterTail->Next = cur;
				GreaterTail = GreaterTail->Next;
			}
		}
		else
		{
			if (LessHead == NULL)
				LessHead = LessTail = cur;
			else
			{
				LessTail->Next = cur;
				LessTail = LessTail->Next;
			}
		}
		cur = cur->Next;
	}
	if (LessHead)
	{
		LessTail->Next = GreaterHead;
		if (GreaterHead)
			GreaterTail->Next = NULL;
		return LessHead;
	}
	return GreaterHead;
}

SLTNode* Partition2(SLTNode* Phead, int K)
{
	SLTNode* LessHead = (SLTNode*)malloc(sizeof(SLTNode));		//标兵位
	SLTNode* GreaterHead = (SLTNode*)malloc(sizeof(SLTNode));
	if (!LessHead || !GreaterHead)
	{
		perror("Partition2");
		exit(-1);
	}
	SLTNode* LessTail = LessHead;
	SLTNode* GreaterTail = GreaterHead;
	LessTail->Next = NULL;
	GreaterTail->Next = NULL;
	SLTNode* cur = Phead;
	if (cur)
	{
		while (cur)
		{
			if ((cur->Data) > K)
			{
				GreaterTail->Next = cur;
				GreaterTail = cur;
			}
			else
			{
				LessTail->Next = cur;
				LessTail = cur;
			}
			cur = cur->Next;
		}
		LessTail->Next = GreaterHead->Next;
		GreaterTail->Next = NULL;
		SLTNode* Newhead = LessHead->Next;
		free(LessHead);
		LessHead = NULL;
		free(GreaterHead);
		GreaterHead = NULL;
		return Newhead;
	}
	else
	{
		return Phead;
	}
}

_Bool chkPalindrom(SLTNode* Phead)
{
	SLTNode* middle = MiddleNode(Phead);
	middle = SLTReverse2(Phead);
	while (Phead && middle)
	{
		if ((Phead->Data) == (middle->Data))
		{
			Phead = Phead->Next;
			middle = middle->Next;
		}
		else
			return FALSE;
	}
		return TURE;
}

SLTNode* getIntersectionNode(SLTNode* HeadA, SLTNode* HeadB)
{
	assert(HeadA && HeadB);
	SLTNode* tailA = HeadA;
	SLTNode* tailB = HeadB;
	int lenA = 1; int lenB = 1;
	while (tailA->Next)
	{
		lenA++;
		tailA = tailA->Next;
	}
	while (tailB->Next)
	{
		lenB++;
		tailB = tailB->Next;
	}
	if (tailA != tailB)
		return NULL;

	int gap = abs(lenA - lenB);
	SLTNode* longerList = HeadA;
	SLTNode* shorterList = HeadB;
	if (lenA < lenB)
	{
		longerList = HeadB;
		shorterList = HeadA;
	}
	while (gap--)
		longerList = longerList->Next;
	while (shorterList != longerList)
	{
		if (longerList && shorterList)
		{
			longerList = longerList->Next;
			shorterList = shorterList->Next;
		}
	}
	return shorterList;

}

SLTNode* detectCycle(SLTNode* Phead)
{
	SLTNode* fast = Phead;
	SLTNode* slow = Phead;
	while (fast && fast->Next)
	{
		fast = fast->Next->Next;
		slow = slow->Next;
		if (fast == slow)
		{
			SLTNode* head = Phead;
			SLTNode* meetnode = fast;
			while (head != meetnode)
			{
				head = head->Next;
				meetnode = meetnode->Next;
			}
			return head;
		}
	}
	return NULL;
}

RL* CopyRandomList(RL* Phead)
{
	if (!Phead)
	{
		return NULL;
	}

	RL* head = Phead;
	RL* headnext = Phead->next;
	//得到新链表
	while (headnext)
	{
		//将数值拷贝进新节点
		RL* newhead = (RL*)malloc(sizeof(RL));
		if (newhead == NULL)
		{
			perror("CopyRandomList");
			exit(-1);
		}
		newhead->data = head->data;
		//将新节点连接进旧链表
		head->next = newhead;
		newhead->next = headnext;
		//迭代
		if (headnext)
		{
			head = headnext;
			headnext = headnext->next;
		}
	}
	//拷贝最后一个节点
	RL* newhead = (RL*)malloc(sizeof(RL));
	if (newhead == NULL)
	{
		perror("CopyRandomList");
		exit(-1);
	}
	newhead->data = head->data;
	head->next = newhead;
	newhead->next = NULL;
	//拷贝random指针
	head = Phead;
	headnext = Phead->next;
	while (head)
	{
		//拷贝
		if (head->random)
			headnext->random = head->random->next;
		else
			headnext->random = NULL;
		//迭代
		head = head->next->next;
		if (headnext->next)
			headnext = headnext->next->next;
	}
	//分离新链表和恢复旧链表
	head = Phead;
	headnext = Phead->next;
	newhead = Phead->next;
	while (headnext->next)
	{
		head->next = headnext->next;
		headnext->next = headnext->next->next;
		head = head->next;
		headnext = headnext->next;
	}
	head->next = NULL;
	return newhead;
}