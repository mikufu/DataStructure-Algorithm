#pragma once
#include <iostream>
#include <stack>

typedef int DataType;

enum BalanceStatus
{
	RH = -1,EH, LH
};

typedef struct TreeNode
{
	DataType key;
	int BalanceFlag;
	TreeNode* left;
	TreeNode* right;
}TNode;

class Balance_BinTree	//Æ½ºâ¶þ²æÊ÷AVL
{
public:
	TreeNode* root;
	bool GrowthFlag;
public:
	Balance_BinTree();

	void creatBTree(DataType* a, int n);

	bool insert(DataType x);

	bool insertAVL(TreeNode* &T, DataType x);

	void InOrderprint();

	TreeNode* find(DataType x);

	void L_Rotate(TreeNode*& T);

	void R_Rotate(TreeNode*& T);

	void leftBalance(TreeNode*& T);

	void rightBalance(TreeNode*& T);
};