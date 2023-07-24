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
	if (T == nullptr)			//�սڵ�ֱ�����
	{
		T = new TreeNode;
		T->BalanceFlag = EH;
		T->key = x;
		T->left = T->right = nullptr;
		this->GrowthFlag = true;
	}
	else if (x == T->key)		//����ͬ��Ԫ���򷵻�Ϊ�㣬����Ӹ�Ԫ��
	{
		this->GrowthFlag = false;
		return 0;
	}
	else if (T->key > x)		//T->key > x����ӵ���������
	{
		if (!insertAVL(T->left, x))	//�ж��Ƿ���ӳɹ�
			return 0;				//���ʧ��ֱ�ӷ���0
		if (this->GrowthFlag)		//��ӳɹ����ж����Ƿ񳤸�
		{
			switch (T->BalanceFlag)	//�ж��Ƿ�ʧ��
			{
			case LH:
				leftBalance(T);		//������ʧ�⣬���е���
				break;
			case EH:
				T->BalanceFlag = LH;//ԭ��ƽ�⣬����������
				break;
			case RH:
				T->BalanceFlag = EH;//ԭ���������ߣ���ƽ��
				this->GrowthFlag = false;//�����߶ȣ���ȣ�������
				break;
			}
		}
	}
	else						//T->key < x����ӵ���������
	{
		if (!insertAVL(T->right, x))	//�ж��Ƿ���ӳɹ�
			return 0;				//���ʧ��ֱ�ӷ���0
		if (this->GrowthFlag)		//��ӳɹ����ж����Ƿ񳤸�
		{
			switch (T->BalanceFlag)	//�ж��Ƿ�ʧ��
			{
			case LH:
				T->BalanceFlag = EH;//ԭ���������ߣ���ƽ��
				this->GrowthFlag = false;//�����߶ȣ���ȣ�������
				break;
			case EH:
				T->BalanceFlag = RH;//ԭ��ƽ�⣬����������
				break;
			case RH:
				rightBalance(T);	//������ʧ�⣬���е���
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

void Balance_BinTree::leftBalance(TreeNode*& T)//����������ƽ��
{
	TreeNode* lc = T->left;		
	switch (lc->BalanceFlag)	//�ж�T�����ӵ�ƽ��
	{
	case LH:					//LL��ֱ����TΪ���ڵ��������
		T->BalanceFlag = lc->BalanceFlag = EH;
		R_Rotate(T);
		break;
	case RH:					//LR��
		TreeNode* rd = lc->right;//rd�ڵ�ΪT�����ӵ��Һ���
		switch (rd->BalanceFlag)
		{
		case LH:				//�������rd�ڵ����������
			T->BalanceFlag = RH;//��ת��T�ڵ��Ҹ�
			lc->BalanceFlag = EH;//��ת��ԭT������ƽ��
			break;
		case EH:				//�����Ϊrd
			T->BalanceFlag = EH;//��ת��T�ڵ�ƽ��
			lc->BalanceFlag = EH;//��ת��ԭT������ƽ��
			break;
		case RH:				//�������rd�ڵ����������
			T->BalanceFlag = EH;//��ת��T�ڵ�ƽ��
			lc->BalanceFlag = LH;//��ת��ԭT���������
			break;
		}
		rd->BalanceFlag = EH;//rd�ڵ㾭��ת��ƽ��
		L_Rotate(T->left);
		R_Rotate(T);
		break;
	}
	this->GrowthFlag = false;//����ת�����������߶�
}

void Balance_BinTree::rightBalance(TreeNode*& T)//����������ƽ��
{												//ͬ��ƽ�����
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