#include "indirected_netByADjlist.h"

ALGraph::ALGraph(int vex, int arc)
{
	this->vex = vex;
	this->arc = arc;
	for (int i = 0; i < this->vex; i++)		//构造顶点表
	{
		std::cout << "请输入第" << i << "个顶点:> ";
		std::cin >> this->vertices[i].data;
		this->vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < this->arc; k++)
	{
		VerTextype v1, v2;
		OtherInfo w;
		std::cout << "请输入第" << k << "条边的权值:> ";	//无向图则只需要将权值置为1即可
		std::cin >> v1 >> v2 >> w;
		int i, j;
		i = LocateVex(v1);
		j = LocateVex(v2);
		
		ArcNode* p1 = this->vertices[i].firstarc;	//头插边节点
		ArcNode* p2 = new ArcNode;		
		p2->adjvex = j;
		p2->info = w;
		this->vertices[i].firstarc = p2;
		p2->nextarc = p1;

		p1 = this->vertices[j].firstarc;			//有向网不需要这一步
		p2 = new ArcNode;							//将两节点均头插边界点
		p2->adjvex = i;
		p2->info = w;
		this->vertices[j].firstarc = p2;
		p2->nextarc = p1;
	}
}
//若想得到有向图则需w初始化为1，同时两节点不需要同时连接
int ALGraph::LocateVex(VerTextype v)	//在顶点表中找到对应顶点的下标并返回
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
void ALGraph::BFS_List(int* visit, int v)	//G为邻接表
{
	std::queue<int> q;		//辅助队列
	q.push(v);				//将第v个顶点入队
	while (!q.empty())		//队列不为空就访问顶点
	{
		std::cout << this->vertices[q.front()].data << "->";//访问顶点
		visit[q.front()] = true;							//访问后标记为1
		ArcNode* p1 = this->vertices[q.front()].firstarc;		
		q.pop();											//将访问的顶点出队
		while (p1 != NULL)
		{
			if (!visit[p1->adjvex])
			{
				q.push(p1->adjvex);							//将与之相连且没有被访问的顶点入队
				visit[p1->adjvex] = true;					//入队后标记为真，防止重复入队
			}
			p1 = p1->nextarc;								
		}
	}
}
//空间复杂度O(n)，时间复杂度O(n + e) (n为顶点数，e为边数)(时间复杂度只与存储结构有关)
int ALGraph::GetVex()
{
	return this->vex;
}

int ALGraph::GetArc()
{
	return this->arc;
}
