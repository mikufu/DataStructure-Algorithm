#include "indirected_netByAMGraph.h"
#include "indirected_netByADjlist.h"

void test01()
{
	AMGraph G;
	CreateIN(G);
}

void test02()
{
	int vex, arc;
	std::cout << "请输入无向网的顶点和边的个数:> ";
	std::cin >> vex >> arc;
	ALGraph G(vex, arc);
}

void test03()	//无向图的深度优先搜索
{
	AMGraph G;
	CreateIN(G);
	int* visit = new int[G.vexnum];	//辅助数组，查看该顶点是否被访问
	for (int i = 0; i < G.vexnum; i++)
		visit[i] = false;
	DFS_Graph(G, visit, 2);
}

void test04()	//无向图的广度优先搜索
{
	int vex, arc;
	std::cout << "请输入无向网的顶点和边的个数:> ";
	std::cin >> vex >> arc;
	ALGraph G(vex, arc);
	int* visit = new int[vex];	//辅助数组，查看该顶点是否被访问
	for (int i = 0; i < vex; i++)
		visit[i] = 0;
	G.BFS_List(visit, 1);
}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();

	return 0;
}