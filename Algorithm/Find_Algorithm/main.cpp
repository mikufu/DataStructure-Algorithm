#include "Balance_BinTree.h"

void test01()
{
	Balance_BinTree T;
	int a[] = { 3, 5, 1, 9, 4, 18, 2, 7, 21, 16 };
	T.creatBTree(a, sizeof(a) / sizeof(a[0]));
	T.InOrderprint();
	std::cout << std::endl;
	T.insert(3);
	T.insert(4);
	T.insert(6);
	T.insert(7);
	T.insert(8);
	T.InOrderprint();
	std::cout << std::endl;
}

void test02()
{
	Balance_BinTree T;
	int a[] = { 3, 5, 1, 9, 4, 18, 2, 7, 21, 16, 3, 7, 10, 12 };
	T.creatBTree(a, sizeof(a) / sizeof(a[0]));
	T.InOrderprint();
	std::cout << std::endl;
	if (T.find(8))
	{
		std::cout << "ÕÒµ½ÁË£¡" << std::endl;
	}
	else
		std::cout << "Î´ÕÒµ½£¡" << std::endl;
}

int main()
{
	using namespace std;
	//test01();
	test02();

	return 0;
}