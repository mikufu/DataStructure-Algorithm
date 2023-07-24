#pragma once
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef char DataType;

struct BinTree
{
	DataType Data;
	BinTree* LChild;
	BinTree* RChild;
};
//���ʽڵ�
void visit(BinTree* T)
{
	cout << T->Data << ' ';
}
//ǰ�򴴽�������
bool CreatTree(BinTree* &T)
{
	DataType ch = 0;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = new BinTree;
		T->Data = ch;
		CreatTree(T->LChild);
		CreatTree(T->RChild);
	}
	return true;
}
//ǰ����ʶ�����
bool PreOrderTraverse(BinTree* T)
{
	if (T)
	{
		visit(T);
		PreOrderTraverse(T->LChild);
		PreOrderTraverse(T->RChild);
	}
	return true;
}
//������ʶ�����
bool InOrderTraverse(BinTree* T)
{
	if (T)
	{
		InOrderTraverse(T->LChild);
		visit(T);
		InOrderTraverse(T->RChild);
	}
	return true;
}
//������ʶ�����
bool PostOrderTraverse(BinTree* T)
{
	if (T)
	{
		PostOrderTraverse(T->LChild);
		PostOrderTraverse(T->RChild);
		visit(T);
	}
	return true;
}
//��ջ������ʶ�����
void InOrderTraverseByStack(BinTree* T)
{
	stack<BinTree*> S;
	BinTree* p = T;
	while (p || !S.empty())
	{
		if (p)
		{
			S.push(p);
			p = p->LChild;
		}
		else
		{
			p = S.top();
			visit(p);
			S.pop();
			p = p->RChild;
		}
	}
}
//�ö��в�η��ʶ�����
void LevelTraverse(BinTree* T)
{
	queue<BinTree*> qu;
	BinTree* p = T;
	qu.push(p);
	while (!qu.empty())
	{
		BinTree* q = qu.front();
		visit(q);
		if (q->LChild)
			qu.push(q->LChild);
		if (q->RChild)
			qu.push(q->RChild);
		qu.pop();
	}
}
//�ݹ鿽��������
void Copy(BinTree* T, BinTree*& NewT)
{
	if (T)
	{
		NewT = new BinTree;
		NewT->Data = T->Data;
		Copy(T->LChild, NewT->LChild);
		Copy(T->RChild, NewT->RChild);
	}
	else
		NewT = NULL;
}
//�ݹ������������
int Depth(BinTree* T)
{
	if (T)
	{
		int m = Depth(T->LChild);
		int n = Depth(T->RChild);
		if (m > n) return (m + 1);
		else return (n + 1);
	}
	else
		return 0;
}
//�ݹ����������Ľڵ����
int NodeCount(BinTree* T)
{
	if (T)
	{
		return (NodeCount(T->LChild) 
				+ NodeCount(T->RChild) + 1);
	}
	else
		return 0;
}
//�ݹ���������Ҷ�ӽڵ����
int LeafCount(BinTree* T)
{
	if (T)
	{
		if (T->LChild || T->RChild)
		{
			return LeafCount(T->LChild) + LeafCount(T->RChild);
		}
		else
			return 1;
	}
	else
		return 0;
}