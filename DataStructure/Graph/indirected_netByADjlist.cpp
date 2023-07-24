#include "indirected_netByADjlist.h"

ALGraph::ALGraph(int vex, int arc)
{
	this->vex = vex;
	this->arc = arc;
	for (int i = 0; i < this->vex; i++)		//���춥���
	{
		std::cout << "�������" << i << "������:> ";
		std::cin >> this->vertices[i].data;
		this->vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < this->arc; k++)
	{
		VerTextype v1, v2;
		OtherInfo w;
		std::cout << "�������" << k << "���ߵ�Ȩֵ:> ";	//����ͼ��ֻ��Ҫ��Ȩֵ��Ϊ1����
		std::cin >> v1 >> v2 >> w;
		int i, j;
		i = LocateVex(v1);
		j = LocateVex(v2);
		
		ArcNode* p1 = this->vertices[i].firstarc;	//ͷ��߽ڵ�
		ArcNode* p2 = new ArcNode;		
		p2->adjvex = j;
		p2->info = w;
		this->vertices[i].firstarc = p2;
		p2->nextarc = p1;

		p1 = this->vertices[j].firstarc;			//����������Ҫ��һ��
		p2 = new ArcNode;							//�����ڵ��ͷ��߽��
		p2->adjvex = i;
		p2->info = w;
		this->vertices[j].firstarc = p2;
		p2->nextarc = p1;
	}
}
//����õ�����ͼ����w��ʼ��Ϊ1��ͬʱ���ڵ㲻��Ҫͬʱ����
int ALGraph::LocateVex(VerTextype v)	//�ڶ�������ҵ���Ӧ������±겢����
{
	for (int i = 0; i < this->vex; i++)
	{
		if (v == this->vertices[i].data)
		{
			return i;
		}
	}
	return -1;
}
//Breadth-First search
void ALGraph::BFS_List(int* visit, int v)	//GΪ�ڽӱ�
{
	std::queue<int> q;		//��������
	q.push(v);				//����v���������
	while (!q.empty())		//���в�Ϊ�վͷ��ʶ���
	{
		std::cout << this->vertices[q.front()].data << "->";//���ʶ���
		visit[q.front()] = true;							//���ʺ���Ϊ1
		ArcNode* p1 = this->vertices[q.front()].firstarc;		
		q.pop();											//�����ʵĶ������
		while (p1 != NULL)
		{
			if (!visit[p1->adjvex])
			{
				q.push(p1->adjvex);							//����֮������û�б����ʵĶ������
				visit[p1->adjvex] = true;					//��Ӻ���Ϊ�棬��ֹ�ظ����
			}
			p1 = p1->nextarc;								
		}
	}
}
//�ռ临�Ӷ�O(n)��ʱ�临�Ӷ�O(n + e) (nΪ��������eΪ����)(ʱ�临�Ӷ�ֻ��洢�ṹ�й�)
int ALGraph::GetVex()
{
	return this->vex;
}

int ALGraph::GetArc()
{
	return this->arc;
}
