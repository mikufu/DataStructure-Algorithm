#include "Tree.hpp"
#include "HuffmanTree.h"

void test01()
{
	BinTree* parent = NULL;
	CreatTree(parent);
	
	PreOrderTraverse(parent);
	cout << endl;
	InOrderTraverse(parent);
	cout << endl;
	PostOrderTraverse(parent);
	cout << endl;
	InOrderTraverseByStack(parent);
	cout << endl;
	LevelTraverse(parent);
}

void test02()
{
	BinTree* Tree1 = NULL;
	CreatTree(Tree1);
	BinTree* Tree2 = NULL;
	Copy(Tree1, Tree2);

	cout << "Tree1:> ";
	PreOrderTraverse(Tree1);
	cout << endl;
	cout << "Tree2:> ";
	PreOrderTraverse(Tree2);
}

void test03()
{
	BinTree* parent = NULL;
	CreatTree(parent);
	PreOrderTraverse(parent);
	cout << endl;
	cout << "二叉树的深度为: " << Depth(parent) << endl;
	cout << "二叉树的节点个数为: " << NodeCount(parent) << endl;
	cout << "二叉树的叶子节点个数为: " << LeafCount(parent) << endl;
}

void test04()
{
	HTNode* H = NULL;
	int n = 8;
	InitHTree(H, n);
	CreatHuffmanTree(H, n);
	for (int i = 1; i < 2 * n; i++)
	{
		cout << i << "-weight:> " << H[i].weight
			<< " parent:> " << H[i].parent
			<< " lch:> " << H[i].lchild
			<< " rch:> " << H[i].rchild
			<< endl;
	}
}

void test05()
{
	HTNode* H = NULL;
	int n = 7;
	HuffmanCode* HC = new HuffmanCode[n];
	InitHTree(H, n);
	CreatHuffmanTree(H, n);
	CreatHuffmanCode(H, HC, n);
	for (int i = 1; i < 2 * n; i++)
	{
		cout << i << "---character:> " << H[i].ch
			<< "\tweight:> " << H[i].weight
			<< "\tparent:> " << H[i].parent
			<< "\tlch:> " << H[i].lchild
			<< "\trch:> " << H[i].rchild
			<< endl;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << i << "---character:> " << HC[i].ch
			<< "\tHuffmanCode:> " << HC[i].s
			<< endl;
	}
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	return 0;
}