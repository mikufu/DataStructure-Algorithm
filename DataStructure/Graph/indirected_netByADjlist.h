#pragma once
#include <iostream>
#include <queue>

typedef char VerTextype;	//设置顶点的数据类型为字符型
typedef int Arctype;		//设置边的权值类型为整型
typedef int OtherInfo;
const int MVNum1 = 50;		//设置最大顶点数

typedef struct ArcNode		//边节点
{
	int adjvex;				//与边相连的节点在顶点表中的下标
	struct ArcNode* nextarc;//与节点相连的下一个节点
	OtherInfo info;			//节点的权值或其他信息
}ArcNode;

typedef struct VNode
{
	VerTextype data;		//顶点表中的顶点
	ArcNode* firstarc;		//指向与顶点相连的节点构成的链表
}VNode;

class ALGraph				//邻接表
{
private:
	VNode vertices[MVNum1]; //顶点表
	int vex, arc;			//图的顶点和边的个数
public:
	ALGraph(int vex, int arc);		//创建图

	int LocateVex(VerTextype v);	//定位顶点

	void BFS_List(int* visit, int v);	//广度优先搜索遍历图

	int GetVex();

	int GetArc();
};