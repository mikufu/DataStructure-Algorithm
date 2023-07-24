#include "Tree.hpp"
//#include "Stack.hpp"

//void test01()
//{
//	BinTree<char> *parent = new BinTree<char>('a');
//	parent->Push_Left('b');
//	parent->Push_Right('c');
//	BinTree<char>* Lchild = parent->GetLchild();
//	BinTree<char>* Rchild = parent->GetRchild();
//	Lchild->Push_Left('d');
//	Lchild->Push_Right('e');
//	Rchild->Push_Right('f');
//	
//	parent->PreOrderTraverse();
//	cout << endl;
//	parent->InOrderTraverse(parent);
//	cout << endl;
//	parent->PostOrderTraverse(parent);
//}
//
//void test02()
//{
//	BinTree<int>* parent = new BinTree<int>(1);
//	parent->Push_Left(2);
//	parent->Push_Right(3);
//	BinTree<int>* Lchild = parent->GetLchild();
//	BinTree<int>* Rchild = parent->GetRchild();
//	Lchild->Push_Left(6);
//	Lchild->Push_Right(4);
//	Rchild->Push_Right(5);
//
//	parent->PreOrderTraverse();
//	cout << endl;
//	parent->InOrderTraverse(parent);
//	cout << endl;
//	parent->PostOrderTraverse(parent);
//}
//
//void test05()
//{
//	BinTree<char>* parent = new BinTree<char>;
//	parent->CreatBinTree();
//
//	parent->PreOrderTraverse();
//	cout << endl;
//	parent->InOrderTraverse(parent);
//	cout << endl;
//	parent->PostOrderTraverse(parent);
//}
//
//int main()
//{
//	//test01();
//	//test02();
//	test05();
//
//	return 0;
//}