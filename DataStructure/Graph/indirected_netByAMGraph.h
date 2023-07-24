#pragma once
#include <iostream>

typedef char VerTextype;	//设置顶点的数据类型为字符型
typedef int Arctype;		//设置边的权值类型为整型
const int MVNum0 = 50;		//设置最大顶点数

typedef struct
{
	VerTextype vexs[MVNum0];	//顶点表
	Arctype arcs[MVNum0][MVNum0];//邻接矩阵
	int vexnum, arcnum;		//当前图的顶点数和边数
}AMGraph;	//Adjacency Matrix Graph

void CreateIN(AMGraph& G);		//创建图

int LocateVex(AMGraph& G, VerTextype u);	//定位顶点

void DFS_Graph(const AMGraph& G, int* visit, int v);	//深度优先搜索遍历图