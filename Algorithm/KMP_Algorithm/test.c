#define _CRT_SECURE_NO_WARNINGS 1

#include "KMP.h"

void Stest()
{
	char ts[] = { "abcabdabcddsacsef" };
	char ps[] = { "abcabd" };
	int pos = KMP(ts, ps);
	if (pos == -1)
		printf("û�ҵ�!\n");
	else
		printf("�ҵ���!�±�Ϊ%d\n", pos);
}

int main()
{
	Stest();
	return 0;
}