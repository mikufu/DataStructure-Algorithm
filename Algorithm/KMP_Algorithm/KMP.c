#define _CRT_SECURE_NO_WARNINGS 1

#include "KMP.h"

int* GetNext(char* ps)
{
	int length = 0;
	while (ps[++length])
		;
	int j = 0;
	int k = -1;
	int* next = (int*)malloc(length * sizeof(int));
	if (next == NULL)
		exit(-1);
	next[0] = -1;
	while (j < length - 1)
	{
		if (k == -1 || ps[j] == ps[k])
		{
			if (ps[++k] == ps[++j])		//�������ַ����ʱ����
				next[j] = next[k];
			else
				next[j] = k;
		}
		else
			k = next[k];
	}
	return next;
}

int KMP(char* ts, char* ps)
{
	int* next = GetNext(ps);
	int lenT = 0; int lenP = 0;
	int i = 0; int j = 0;		//������ģʽ��λ��;
	while (ts[++lenT])
		;
	while (ps[++lenP])
		;
	while (i < lenT && j < lenP)
	{
		if (j == -1 || ts[i] == ps[j])	//��jΪ-1ʱ,Ҫ�ƶ�i,j����;
		{
			i++; j++;
		}
		else
			j = next[j];		//j�ص�nextָ����λ��;
	}
	if (j == lenP)
		return i - j;
	else
		return -1;
}