#pragma once
#include <iostream>

using namespace std;

//template<class DataType>
//class BinTree
//{
//private:
//	DataType Data;
//	BinTree* Lchild;
//	BinTree* Rchild;
//
//public:
//	BinTree()
//	{
//		this->Data = 0;
//		this->Lchild = NULL;
//		this->Rchild = NULL;
//	}
//
//	BinTree(DataType data)
//	{
//		this->Data = data;
//		this->Lchild = NULL;
//		this->Rchild = NULL;
//	}
//
//	/*void operator= (BinTree<DataType>* T)
//	{
//		this->Data = T->Data;
//		this->Lchild = T->Lchild;
//		this->Rchild = T->Rchild;
//	}*/
//
//	BinTree(BinTree<DataType> *NewNode)
//	{
//		this->Data = NewNode->Data;
//		this->Lchild = NewNode->Lchild;
//		this->Rchild = NewNode->Rchild;
//	}
//
//	DataType GetData()
//	{
//		return this->Data;
//	}
//
//	BinTree<DataType>* GetLchild()
//	{
//		return this->Lchild;
//	}
//
//	BinTree<DataType>* GetRchild()
//	{
//		return this->Rchild;
//	}
//
//	void Push_Left(DataType data)
//	{
//		this->Lchild = new BinTree<DataType>(data);
//	}
//
//	void Push_Right(DataType data)
//	{
//		this->Rchild = new BinTree<DataType>(data);
//	}
//
//	void PreOrderTraverse()
//	{
//		if (this)
//		{
//			cout << this->Data << endl;
//			this->Lchild->PreOrderTraverse();
//			this->Rchild->PreOrderTraverse();
//		}
//	}
//
//	void InOrderTraverse(BinTree<DataType>* T)
//	{
//		if (T)
//		{
//			InOrderTraverse(T->Lchild);
//			cout << T->Data << endl;
//			InOrderTraverse(T->Rchild);
//		}
//	}
//
//	void PostOrderTraverse(BinTree<DataType>* T)
//	{
//		if (T)
//		{
//			PostOrderTraverse(T->Lchild);
//			PostOrderTraverse(T->Rchild);
//			cout << T->Data << endl;
//		}
//	}
//
//	void ClearBinTere(BinTree<DataType>* T)
//	{
//		if (T)
//		{
//			ClearBinTere(T->Lchild);
//			ClearBinTere(T->Rchild);
//			delete T;
//			T = NULL;
//		}
//	}
//
//	void CreatBinTree()
//	{
//		DataType ch{};
//		cin >> ch;
//		if (ch != '#')
//		{
//			this->Lchild->CreatBinTree();
//			this->Rchild->CreatBinTree();
//			this->Lchild = new BinTree;
//			this->Rchild = new BinTree;
//			this->Data = ch;
//		}
//		else
//		{
//			delete this;
//		}
//	}
//
//	~BinTree()
//	{
//		ClearBinTere(this);
//	}
//};

//template<class DataType>
//class TreeNode
//{
//private:
//	DataType Data;
//	TreeNode* Lchild;
//	TreeNode* Rchild;
//public:
//
//	TreeNode(const DataType& data)
//	{
//		this->Data = data;
//		this->Lchild = NULL;
//		this->Rchild = NULL;
//	}
//};
//
//template<class DataType>
//class BinTree
//{
//private:
//	TreeNode<DataType>* parent;
//
//public:
//		
//	BinTree(const DataType& data)
//	{
//		this->parent->Data = new TreeNode(data);
//	}
//		
//	BinTree(BinTree<DataType>* NewTree)
//	{
//		this->parent->Data = NewTree->parent->Data;
//		this->parent->Lchild = NewTree->parent->Lchild;
//		this->parent->Rchild = NewTree->parent->Rchild;
//	}
//		
//	DataType GetData(TreeNode<DataType>* T)
//	{
//		return T->Data;
//	}
//		
//	TreeNode<DataType>* GetLchild(TreeNode<DataType>* T)
//	{
//		return T->Lchild;
//	}
//		
//	TreeNode<DataType>* GetRchild(TreeNode<DataType>* T)
//	{
//		return T->Rchild;
//	}
//		
//	/*void Push_Left(TreeNode<DataType>* T)
//	{
//		this->Lchild = new BinTree<DataType>(data);
//	}
//		
//	void Push_Right(DataType data)
//	{
//		this->Rchild = new BinTree<DataType>(data);
//	}*/
//		
//	void PreOrderTraverse()
//	{
//		
//	}
//		
//	void InOrderTraverse(BinTree<DataType>* T)
//	{
//		if (T)
//		{
//			InOrderTraverse(T->Lchild);
//			cout << T->Data << endl;
//			InOrderTraverse(T->Rchild);
//		}
//	}
//		
//	void PostOrderTraverse(BinTree<DataType>* T)
//	{
//		if (T)
//		{
//			PostOrderTraverse(T->Lchild);
//			PostOrderTraverse(T->Rchild);
//			cout << T->Data << endl;
//		}
//	}
//		
//	void ClearBinTere(BinTree<DataType>* T)
//	{
//		if (T)
//		{
//			ClearBinTere(T->Lchild);
//			ClearBinTere(T->Rchild);
//			delete T;
//			T = NULL;
//		}
//	}
//		
//	void CreatBinTree()
//	{
//		DataType ch{};
//		cin >> ch;
//		if (ch != '#')
//		{
//			this->Lchild->CreatBinTree();
//			this->Rchild->CreatBinTree();
//			this->Lchild = new BinTree;
//			this->Rchild = new BinTree;
//			this->Data = ch;
//		}
//		else
//		{
//			delete this;
//		}
//	}
//		
//	~BinTree()
//	{
//		ClearBinTere(this);
//	}
//};
