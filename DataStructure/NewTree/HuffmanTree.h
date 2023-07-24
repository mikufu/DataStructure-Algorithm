#pragma once
#include <iostream>
using namespace std;

typedef struct HuffmanTreeNode	//哈夫曼树
{
	char ch;
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;

typedef struct HuffmanCode		//哈夫曼编码
{
	char ch;
	char* s;	//使用string可能会导致空间不够用，错误：std::bad_alloc
}HuffmanCode;

void InitHTree(HTNode* &H, int n);		//初始化树

void select(HTNode* H, pair<int, int>& p, int n);	//获取权重做小的两颗子树

void CreatHuffmanTree(HTNode* &H, int n);	//创建哈夫曼树

void CreatHuffmanCode(HTNode* &H, HuffmanCode*& HC, int n);	//创建哈夫曼编码