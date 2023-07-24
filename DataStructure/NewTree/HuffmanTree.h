#pragma once
#include <iostream>
using namespace std;

typedef struct HuffmanTreeNode	//��������
{
	char ch;
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;

typedef struct HuffmanCode		//����������
{
	char ch;
	char* s;	//ʹ��string���ܻᵼ�¿ռ䲻���ã�����std::bad_alloc
}HuffmanCode;

void InitHTree(HTNode* &H, int n);		//��ʼ����

void select(HTNode* H, pair<int, int>& p, int n);	//��ȡȨ����С����������

void CreatHuffmanTree(HTNode* &H, int n);	//������������

void CreatHuffmanCode(HTNode* &H, HuffmanCode*& HC, int n);	//��������������