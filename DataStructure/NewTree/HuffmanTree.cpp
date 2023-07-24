#include "HuffmanTree.h"

void InitHTree(HTNode* &H, int n)
{
	H = new HTNode[2 * n];	//���ٴ�Ź�������������
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
		if (H[i].parent == 0)		//ֻ������˫�׽ڵ������
		{
			if (p.first == 0)		//����first��second�ĳ�ʼֵ�����벻ͬ
			{
				p.first = i;
				p.second = n;
			}
			if ((H[i].weight < H[p.first].weight
				|| H[i].weight < H[p.second].weight)	//���¶����е���Сֵ
				&& (i != p.first && i != p.second))		//��first��second��ֵ������ͬ
			{
				H[p.first].weight > H[p.second].weight ? p.first = i : p.second = i;
			}
			
		}
	}
}

void CreatHuffmanTree(HTNode* &H, int n)
{
	int i = 0;
	for (i = 1; i <= n; i++)		//������������Ľڵ�����ݺ�Ȩ��
	{
		cout << "��������������ڵ�" << i << "���ַ�:> ";
		cin >> H[i].ch;
		cout << "��������������ڵ�" << i << "��Ȩ��:> ";
		cin >> H[i].weight;
	}

	for (i = n + 1; i < 2 * n; i++)
	{
		pair<int, int> p(0, 0);
		select(H, p, i - 1);		//�����СȨ�ص���������
		H[p.first].parent = i;		//����СȨ�ص�������˫�׽ڵ�Ϊ�½��Ľڵ�i
		H[p.second].parent = i;
		H[i].weight = H[p.first].weight + H[p.second].weight;	//�½��ڵ�i��Ȩ��Ϊ������Ȩ��֮��
		H[i].lchild = p.first;		//���½��ڵ�����Һ���Ϊ����СȨ������
		H[i].rchild = p.second;
	}
}

void CreatHuffmanCode(HTNode* &H, HuffmanCode* &HC, int n)
{
	string tmp(n, '\0');		//������ʱ�ַ����洢ÿ��Ҷ�ӽڵ�Ĺ���������
	for (int i = 1; i <= n; i++)	
	{
		HC[i].ch = H[i].ch;		//��ȡ��������Ҷ�ӽڵ���ַ�
		int c = i;				//c�洢��ǰҶ�ӽڵ�
		int f = H[i].parent;	//f�洢Ҷ�ӽڵ��˫��
		int start = n - 1;		//�洢��������������һλ
		while (f != 0)			//ѭ��������ֱ�����ڵ㱻������
		{
			if (H[f].lchild == c)	
				tmp[--start] = '0';	//���������Ϊ0
			else
				tmp[--start] = '1';	//���������Ϊ1
			c = f;					//c��Ϊc����˫�ף���(��)���ڵ����
			f = H[f].parent;		//f��Ϊf����˫�ף���(��)���ڵ����
		}
		HC[i].s = new char[n - start];	//���ٿռ��Ź���������
		tmp.copy(HC[i].s, (size_t)(n - start), start);
	}
}