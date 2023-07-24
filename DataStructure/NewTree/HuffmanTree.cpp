#include "HuffmanTree.h"

void InitHTree(HTNode* &H, int n)
{
	H = new HTNode[2 * n];	//开辟存放哈夫曼树的数组
	for (int i = 1; i < 2 * n; i++)
	{
		H[i].ch = 0;
		H[i].weight = 0;
		H[i].parent = 0;
		H[i].lchild = 0;
		H[i].rchild = 0;
	}
}

void select(HTNode* H, pair<int, int>& p, int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (H[i].parent == 0)		//只访问无双亲节点的子树
		{
			if (p.first == 0)		//设置first和second的初始值，必须不同
			{
				p.first = i;
				p.second = n;
			}
			if ((H[i].weight < H[p.first].weight
				|| H[i].weight < H[p.second].weight)	//更新队组中的最小值
				&& (i != p.first && i != p.second))		//且first和second的值不能相同
			{
				H[p.first].weight > H[p.second].weight ? p.first = i : p.second = i;
			}
			
		}
	}
}

void CreatHuffmanTree(HTNode* &H, int n)
{
	int i = 0;
	for (i = 1; i <= n; i++)		//输入哈夫曼树的节点的数据和权重
	{
		cout << "请输入哈夫曼树节点" << i << "的字符:> ";
		cin >> H[i].ch;
		cout << "请输入哈夫曼树节点" << i << "的权重:> ";
		cin >> H[i].weight;
	}

	for (i = n + 1; i < 2 * n; i++)
	{
		pair<int, int> p(0, 0);
		select(H, p, i - 1);		//获得最小权重的两颗子树
		H[p.first].parent = i;		//令最小权重的子树的双亲节点为新建的节点i
		H[p.second].parent = i;
		H[i].weight = H[p.first].weight + H[p.second].weight;	//新建节点i的权重为两子树权重之和
		H[i].lchild = p.first;		//让新建节点的左右孩子为两颗小权重子树
		H[i].rchild = p.second;
	}
}

void CreatHuffmanCode(HTNode* &H, HuffmanCode* &HC, int n)
{
	string tmp(n, '\0');		//创建临时字符串存储每个叶子节点的哈夫曼编码
	for (int i = 1; i <= n; i++)	
	{
		HC[i].ch = H[i].ch;		//获取哈夫曼树叶子节点的字符
		int c = i;				//c存储当前叶子节点
		int f = H[i].parent;	//f存储叶子节点的双亲
		int start = n - 1;		//存储哈夫曼编码的最后一位
		while (f != 0)			//循环迭代，直到根节点被访问完
		{
			if (H[f].lchild == c)	
				tmp[--start] = '0';	//左子树编号为0
			else
				tmp[--start] = '1';	//右子树编号为1
			c = f;					//c变为c结点的双亲，往(上)根节点迭代
			f = H[f].parent;		//f变为f结点的双亲，往(上)根节点迭代
		}
		HC[i].s = new char[n - start];	//开辟空间存放哈夫曼编码
		tmp.copy(HC[i].s, (size_t)(n - start), start);
	}
}