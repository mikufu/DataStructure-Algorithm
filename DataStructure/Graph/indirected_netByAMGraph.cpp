#include "indirected_netByAMGraph.h"

void CreateIN(AMGraph& G)
{
	std::cout << "请输入需要创建的无向图的顶点数:> ";
	std::cin >> G.vexnum;
	std::cout << "请输入需要创建的无向图的边数:> ";
	std::cin >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++)			
		for (int j = 0; j < G.vexnum; j++)		//将顶点表初始化为无穷大
			G.arcs[i][j] = 0;					//无向图初始化为0

	for (int i = 0; i < G.vexnum; i++)
	{
		std::cout << "请输入顶点" << i <<":> ";
		std::cin >> G.vexs[i];
	}

	char v1, v2; 
	int w;
	for (int k = 0; k < G.arcnum; k++)
	{
		std::cout << "请输入顶点:> ";	
		std::cin >> v1 >> v2 >> w;				//无向图将w赋值为1
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		G.arcs[j][i] = G.arcs[i][j] = w;		//有向网不将arcs[j][i]赋值
	}
}
//若想得到有向图则需w初始化为0，输入w为1，同时不为arcs[j][i]赋值
int LocateVex(AMGraph& G, VerTextype u)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == u)
			return i;
	}
	return -1;
}
//Depth-First search
void DFS_Graph(const AMGraph& G, int* visit, int v)	//G为邻接矩阵
{
	std::cout << G.vexs[v] << "->";		//访问顶点v
	visit[v] = true;		//将辅助数组顶点v处设为true表示已访问
	for (int w = 0; w < G.vexnum; w++)	//遍历与顶点v相连的每个顶点
	{
		if (!(visit[w]) && G.arcs[v][w])	//顶点w没被访问同时与v相连才访问w
			DFS_Graph(G, visit, w);			//递归调用DFS_Graph
	}
}
//空间复杂度O(n)，时间复杂度O(n ^ 2) (n为顶点数，e为边数)(时间复杂度只与存储结构有关)