#include "Balance_BinTree.h"

Balance_BinTree::Balance_BinTree() { this->root = nullptr; this->GrowthFlag = 0; }

void Balance_BinTree::creatBTree(DataType* a, int n)
{
	for (int i = 0; i < n; i++)
		this->insert(a[i]);
}

bool Balance_BinTree::insert(DataType x)
{
	return insertAVL(this->root, x);
}

bool Balance_BinTree::insertAVL(TreeNode* &T, DataType x)
{
	if (T == nullptr)			//空节点直接添加
	{
		T = new TreeNode;
		T->BalanceFlag = EH;
		T->key = x;
		T->left = T->right = nullptr;
		this->GrowthFlag = true;
	}
	else if (x == T->key)		//有相同的元素则返回为零，不填加该元素
	{
		this->GrowthFlag = false;
		return 0;
	}
	else if (T->key > x)		//T->key > x则添加到左子树上
	{
		if (!insertAVL(T->left, x))	//判断是否添加成功
			return 0;				//添加失败直接返回0
		if (this->GrowthFlag)		//添加成功则判断树是否长高
		{
			switch (T->BalanceFlag)	//判断是否失衡
			{
			case LH:
				leftBalance(T);		//左子树失衡，进行调整
				break;
			case EH:
				T->BalanceFlag = LH;//原本平衡，现左子树高
				break;
			case RH:
				T->BalanceFlag = EH;//原本右子树高，现平衡
				this->GrowthFlag = false;//子树高度（深度）不增加
				break;
			}
		}
	}
	else						//T->key < x则添加到右子树上
	{
		if (!insertAVL(T->right, x))	//判断是否添加成功
			return 0;				//添加失败直接返回0
		if (this->GrowthFlag)		//添加成功则判断树是否长高
		{
			switch (T->BalanceFlag)	//判断是否失衡
			{
			case LH:
				T->BalanceFlag = EH;//原本左子树高，现平衡
				this->GrowthFlag = false;//子树高度（深度）不增加
				break;
			case EH:
				T->BalanceFlag = RH;//原本平衡，现右子树高
				break;
			case RH:
				rightBalance(T);	//右子树失衡，进行调整
				break;
			}
		}
	}
	return 1;
}

void Balance_BinTree::InOrderprint()
{
	std::stack<TreeNode*> s;
	TreeNode* p = this->root;
	while (p || !s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			std::cout << p->key << ' ';
			s.pop();
			p = p->right;
		}
	}
}

TreeNode* Balance_BinTree::find(DataType x)
{
	TreeNode* pos = this->root;
	while (pos)
	{
		if (pos->key == x)
			return pos;
		else if (pos->key > x)
			pos = pos->left;
		else
			pos = pos->right;
	}
	return nullptr;
}

void Balance_BinTree::L_Rotate(TreeNode*& T)
{
	TreeNode* r = T->right;
	T->right = r->left;
	r->left = T;
	T = r;
}

void Balance_BinTree::R_Rotate(TreeNode*& T)
{
	TreeNode* l = T->left;
	T->left = l->right;
	l->right = T;
	T = l;
}

void Balance_BinTree::leftBalance(TreeNode*& T)//调整左子树平衡
{
	TreeNode* lc = T->left;		
	switch (lc->BalanceFlag)	//判断T的左孩子的平衡
	{
	case LH:					//LL型直接以T为根节点进行右旋
		T->BalanceFlag = lc->BalanceFlag = EH;
		R_Rotate(T);
		break;
	case RH:					//LR型
		TreeNode* rd = lc->right;//rd节点为T的左孩子的右孩子
		switch (rd->BalanceFlag)
		{
		case LH:				//插入点在rd节点的左子树上
			T->BalanceFlag = RH;//旋转后T节点右高
			lc->BalanceFlag = EH;//旋转后原T的左孩子平衡
			break;
		case EH:				//插入点为rd
			T->BalanceFlag = EH;//旋转后T节点平衡
			lc->BalanceFlag = EH;//旋转后原T的左孩子平衡
			break;
		case RH:				//插入点在rd节点的右子树上
			T->BalanceFlag = EH;//旋转后T节点平衡
			lc->BalanceFlag = LH;//旋转后原T的左孩子左高
			break;
		}
		rd->BalanceFlag = EH;//rd节点经旋转后平衡
		L_Rotate(T->left);
		R_Rotate(T);
		break;
	}
	this->GrowthFlag = false;//经旋转调整不增长高度
}

void Balance_BinTree::rightBalance(TreeNode*& T)//调整右子树平衡
{												//同左平衡调整
	TreeNode* rc = T->right;
	switch (rc->BalanceFlag)
	{
	case RH:
		T->BalanceFlag = rc->BalanceFlag = EH;
		L_Rotate(T);
		break;
	case LH:
		TreeNode* ld = rc->left;
		switch (ld->BalanceFlag)
		{
		case LH:
			T->BalanceFlag = EH;
			rc->BalanceFlag = RH;
			break;
		case EH:
			T->BalanceFlag = rc->BalanceFlag = EH;
			break;
		case RH:
			T->BalanceFlag = LH;
			rc->BalanceFlag = EH;
			break;
		}
		ld->BalanceFlag = EH;
		R_Rotate(T->right);
		L_Rotate(T);
		break;
	}
	this->GrowthFlag = false;
}