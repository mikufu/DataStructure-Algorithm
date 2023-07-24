#include <iostream>

using namespace std;

const int cap = 50;
const int Hdlta[5] = { 1, 3, 7, 31, 127 };	//Hibbard�������� 2^(k-1)
const int Sdlta[5] = { 1, 5, 19, 41, 109 };	//Sedgewick�������� 9*4^i-9*2^i+1��4^i-3*2^i+1

typedef struct arr
{
	int a[cap] = { 0 };
	int len;
}arr;

void print(const arr& a)
{
	for (int i = 1; i <= a.len; i++)
		cout << a.a[i] << ' ';
	cout << endl;
}
//ֱ�Ӳ�������
void Insertsort(arr& a)
{
	for (int i = 2; i <= a.len; i++)
	{
		if (a.a[i] < a.a[i - 1])
		{
			a.a[0] = a.a[i];		//0��λ��Ϊ�ڱ�λ
			int j = i - 1;
			for (; a.a[j] > a.a[0]; j--)
				a.a[j + 1] = a.a[j];
			a.a[j + 1] = a.a[0];
		}
	}
}
//����ֱ�Ӳ�������
void BInsertsort(arr& a)
{
	for (int i = 2; i <= a.len; i++)
	{
		if (a.a[i] < a.a[i - 1])
		{
			a.a[0] = a.a[i];
			int left = 1; int right = a.len;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (a.a[0] > a.a[mid])
					left = mid + 1;
				else
					right = mid - 1;
			}
			for (int j = i - 1; j >= right + 1; j--)
				a.a[j + 1] = a.a[j];
			a.a[right + 1] = a.a[0];
		}
	}
}
//ϣ������
void ShellInset(arr& a, int dlta)
{
	for (int i = dlta + 1; i <= a.len; i++)
	{
		if (a.a[i] < a.a[i - dlta])
		{
			a.a[0] = a.a[i];
			int j = i - dlta;
			for (; j > 0 && a.a[j] > a.a[0]; j -= dlta)
				a.a[j + dlta] = a.a[j];
			a.a[j + dlta] = a.a[0];
		}
	}
}

void Shellsort(arr& a, int t)
{
	for (int i = t; i >= 0; i--)
	{
		//Shellinset(a, Hdlta[i]);
		ShellInset(a, Sdlta[i]);
	}
}
//ð������
void Bubblesort(arr& a)
{
	bool flag = true;	//�ж���һ���Ƿ�������
	for (int i = a.len; i >= 1 && flag == true; i--)
	{
		flag = false;	//δ����������˵���Ѿ�������ֹͣ����
		for (int j = 2; j <= i; j++)
		{
			if (a.a[j - 1] > a.a[j])
			{
				flag = true;
				a.a[0] = a.a[j];
				a.a[j] = a.a[j - 1];
				a.a[j - 1] = a.a[0];
			}
		}
	}

}
//��������
int Partition(arr& a, int low, int high)
{
	a.a[0] = a.a[low];	//ȥ��һ��Ԫ��Ϊ����
	while (low < high)
	{
		while (low < high && a.a[high] >= a.a[0])	//�ڸ��ӱ����ҵ�������С��Ԫ��
			high--;
		a.a[low] = a.a[high];	//������ڿճ�����lowλ��
		while (low < high && a.a[low] < a.a[0])	//�ڵ��ӱ����ҵ���������Ԫ��
			low++;
		a.a[high] = a.a[low];	//������ڿճ�����highλ��
	}
	a.a[low] = a.a[0];	//low��highλ���غϼ�Ϊ�ź���������λ��
	return low;
}

void Qsort(arr& a, int low, int high)
{
	if (low < high)	//���ȱ������һ
	{
		int pivotloc = Partition(a, low, high);	//����һ��Ϊ����pivotlocΪ����Ԫ���ź����λ��
		Qsort(a, low, pivotloc - 1);	//�Ե��ӱ���еݹ�����
		Qsort(a, pivotloc + 1, high);	//�Ը��ӱ���еݹ�����
	}
}
//��ѡ������
void Selectsort(arr& a)
{
	for (int i = 1; i <= a.len; i++)
	{
		int k = i;
		for (int j = i + 1; j <= a.len; j++)
			k = a.a[k] > a.a[j] ? j : k;	//�ҵ���Сֵ���±�
		if (k != i)
		{
			a.a[0] = a.a[k];
			a.a[k] = a.a[i];
			a.a[i] = a.a[0];
		}
	}
}
//������
void HeapAdjustL(arr& a, int s, int m)
{//��֪R[s...m]��R[s]�������ѵĶ��壬����������R[s]ʹ֮��Ϊһ�������
	a.a[0] = a.a[s];
	for (int i = 2 * s; i <= m; i *= 2)
	{
		if (i < m && a.a[i] < a.a[i + 1])	//��keyֵ�ϴ�Ľڵ�����ɸѡ
			i++;		//i��¼keyֵ�ϴ�Ľڵ��±�
		if (a.a[0] >= a.a[i])	//�ҵ�R[s]���ڵĽڵ�
			break;
		a.a[s] = a.a[i];//���ϴ�ĺ��ӽڵ���˫�׽��
		s = i;			//s���µ���
	}
	a.a[s] = a.a[0];	//�ҵ���sΪR[s]��λ��
}

void HeapAdjustS(arr& a, int s, int m)
{//��֪R[s...m]��R[s]�������ѵĶ��壬����������R[s]ʹ֮��Ϊһ��С����
	a.a[0] = a.a[s];
	for (int i = 2 * s; i <= m; i *= 2)
	{
		if (i < m && a.a[i] > a.a[i + 1])	//��keyֵ��С�Ľڵ�����ɸѡ
			i++;		//i��¼keyֵ��С�Ľڵ��±�
		if (a.a[0] < a.a[i])	//�ҵ�R[s]���ڵĽڵ�
			break;
		a.a[s] = a.a[i];//����С�ĺ��ӽڵ���˫�׽��
		s = i;			//s���µ���
	}
	a.a[s] = a.a[0];	//�ҵ���sΪR[s]��λ��
}

void Heapsort(arr& a)
{
	for (int i = a.len / 2; i >= 1; i--)	//������״̬����һ��
		HeapAdjustL(a, i, a.len);			//�����
	//HeapAdjustS(a, i, a.len);			//С����
	for (int i = a.len; i > 1; i--)			//����n-1������
	{
		swap(a.a[1], a.a[i]);				//�������һ��Ԫ�ؽ���
		HeapAdjustL(a, 1, i - 1);			//��R[1]��R[i-1]���½�����
		//HeapAdjustS(a, i + 1, a.len);		//��С�����������
	}
}
//�鲢����-�ݹ�
void Mergesort(arr& a, int* tmp, int start, int end)
{
	if (start >= end) return; //�������г���Ϊһʱ����
	int len = end - start + 1;
	int mid = start + (len - 1) / 2;
	Mergesort(a, tmp, start, mid);	//������������
	Mergesort(a, tmp, mid + 1, end);//������������
	int k = start; int i = start; int j = mid + 1;
	while (i <= mid && j <= end)	//����������tmp���ź���
		tmp[k++] = a.a[i] < a.a[j] ? a.a[i++] : a.a[j++];
	while (i <= mid)				//�������������к����ȫ��������tmp��
		tmp[k++] = a.a[i++];
	while (j <= end)
		tmp[k++] = a.a[j++];
	for (int index = start; index < start + len; index++)
		a.a[index] = tmp[index];	//��tmp���ź����Ԫ�ؿ�����ȥ
}
//��������orͰ����
int maxbit(arr& a)	//��ȡ���ֵ��λ��
{
	int j = 1;
	for (int i = 1; i <= a.len; i++)
		j = a.a[i] > a.a[j] ? i : j;
	a.a[0] = a.a[j];
	int d = 1;
	while (a.a[0] /= 10)
		d++;
	return d;
}

void Radixsort(arr& a)
{
	int d = maxbit(a); int radix = 1;
	int* count = new int[10];	//�����������ڼ�¼����������ͬ������Ԫ�صĸ���
	int* tmp = new int[a.len + 1];	//��ʱ���飬���ڼ�¼ÿ������������
	for (int i = 1; i <= d; i++)
	{
		for (int j = 0; j < 10; j++)
			count[j] = 0;	//����������Ϊ0
		for (int j = 1; j <= a.len; j++)
			count[(a.a[j] / radix) % 10]++;	//��¼����ͬ������Ԫ�صĸ���
		for (int j = 1; j < 10; j++)//��count��¼j֮ǰ����Ԫ�صĸ���
			count[j] = count[j - 1] + count[j];	//count��¼�л���Ϊj��Ԫ�����������еĴӺ���ǰ(�Ӹߵ���)��λ��
		for (int j = a.len; j >= 1; j--)
			tmp[count[(a.a[j] / radix) % 10]--] = a.a[j]; //��ԭ�����е�Ԫ����tmp�н�������
		for (int j = 1; j <= a.len; j++)
			a.a[j] = tmp[j];	//��tmp�е����п�����ԭ������
		radix *= 10;
	}
}

int main()
{
	arr a;
	int i = 0;
	while (true)
	{
		cin >> a.a[++i];
		char ch;
		if (ch = cin.get() == '\n')
			break;
	}
	a.len = i;
	int* tmp = new int[a.len + 1];
	//Insertsort(a);
	//BInsertsort(a);
	//Shellsort(a, 1);
	//Bubblesort(a);
	//Qsort(a, 1, a.len);
	//Selectsort(a);
	//Heapsort(a);
	//Mergesort(a, tmp, 1, a.len);
	Radixsort(a);
	print(a);
	delete[] tmp;

	return 0;
}