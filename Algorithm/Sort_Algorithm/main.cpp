#include <iostream>

using namespace std;

const int cap = 50;
const int Hdlta[5] = { 1, 3, 7, 31, 127 };	//Hibbard增量序列 2^(k-1)
const int Sdlta[5] = { 1, 5, 19, 41, 109 };	//Sedgewick增量序列 9*4^i-9*2^i+1或4^i-3*2^i+1

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
//直接插入排序
void Insertsort(arr& a)
{
	for (int i = 2; i <= a.len; i++)
	{
		if (a.a[i] < a.a[i - 1])
		{
			a.a[0] = a.a[i];		//0号位置为哨兵位
			int j = i - 1;
			for (; a.a[j] > a.a[0]; j--)
				a.a[j + 1] = a.a[j];
			a.a[j + 1] = a.a[0];
		}
	}
}
//二分直接插入排序
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
//希尔排序
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
//冒泡排序
void Bubblesort(arr& a)
{
	bool flag = true;	//判断上一趟是否发生交换
	for (int i = a.len; i >= 1 && flag == true; i--)
	{
		flag = false;	//未发生交换则说明已经有序，则停止排序
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
//快速排序
int Partition(arr& a, int low, int high)
{
	a.a[0] = a.a[low];	//去第一个元素为枢轴
	while (low < high)
	{
		while (low < high && a.a[high] >= a.a[0])	//在高子表中找到比枢轴小的元素
			high--;
		a.a[low] = a.a[high];	//将其放在空出来的low位置
		while (low < high && a.a[low] < a.a[0])	//在低子表中找到比枢轴大的元素
			low++;
		a.a[high] = a.a[low];	//将其放在空出来的high位置
	}
	a.a[low] = a.a[0];	//low和high位置重合即为排好序后枢轴的位置
	return low;
}

void Qsort(arr& a, int low, int high)
{
	if (low < high)	//长度必须大于一
	{
		int pivotloc = Partition(a, low, high);	//将表一分为二，pivotloc为枢轴元素排好序的位置
		Qsort(a, low, pivotloc - 1);	//对低子表进行递归排序
		Qsort(a, pivotloc + 1, high);	//对高子表进行递归排序
	}
}
//简单选择排序
void Selectsort(arr& a)
{
	for (int i = 1; i <= a.len; i++)
	{
		int k = i;
		for (int j = i + 1; j <= a.len; j++)
			k = a.a[k] > a.a[j] ? j : k;	//找到最小值的下标
		if (k != i)
		{
			a.a[0] = a.a[k];
			a.a[k] = a.a[i];
			a.a[i] = a.a[0];
		}
	}
}
//堆排序
void HeapAdjustL(arr& a, int s, int m)
{//已知R[s...m]除R[s]外均满足堆的定义，本函数调整R[s]使之成为一个大根堆
	a.a[0] = a.a[s];
	for (int i = 2 * s; i <= m; i *= 2)
	{
		if (i < m && a.a[i] < a.a[i + 1])	//沿key值较大的节点向下筛选
			i++;		//i记录key值较大的节点下标
		if (a.a[0] >= a.a[i])	//找到R[s]所在的节点
			break;
		a.a[s] = a.a[i];//将较大的孩子节点变成双亲结点
		s = i;			//s向下迭代
	}
	a.a[s] = a.a[0];	//找到的s为R[s]的位置
}

void HeapAdjustS(arr& a, int s, int m)
{//已知R[s...m]除R[s]外均满足堆的定义，本函数调整R[s]使之成为一个小根堆
	a.a[0] = a.a[s];
	for (int i = 2 * s; i <= m; i *= 2)
	{
		if (i < m && a.a[i] > a.a[i + 1])	//沿key值较小的节点向下筛选
			i++;		//i记录key值较小的节点下标
		if (a.a[0] < a.a[i])	//找到R[s]所在的节点
			break;
		a.a[s] = a.a[i];//将较小的孩子节点变成双亲结点
		s = i;			//s向下迭代
	}
	a.a[s] = a.a[0];	//找到的s为R[s]的位置
}

void Heapsort(arr& a)
{
	for (int i = a.len / 2; i >= 1; i--)	//从无序状态建立一个
		HeapAdjustL(a, i, a.len);			//大根堆
	//HeapAdjustS(a, i, a.len);			//小根堆
	for (int i = a.len; i > 1; i--)			//进行n-1趟排序
	{
		swap(a.a[1], a.a[i]);				//根与最后一个元素交换
		HeapAdjustL(a, 1, i - 1);			//对R[1]到R[i-1]重新建立堆
		//HeapAdjustS(a, i + 1, a.len);		//用小根堆输出逆序
	}
}
//归并排序-递归
void Mergesort(arr& a, int* tmp, int start, int end)
{
	if (start >= end) return; //即子序列长度为一时返回
	int len = end - start + 1;
	int mid = start + (len - 1) / 2;
	Mergesort(a, tmp, start, mid);	//对左子列排序
	Mergesort(a, tmp, mid + 1, end);//对右子列排序
	int k = start; int i = start; int j = mid + 1;
	while (i <= mid && j <= end)	//将子序列在tmp中排好序
		tmp[k++] = a.a[i] < a.a[j] ? a.a[i++] : a.a[j++];
	while (i <= mid)				//将过长的子序列后面的全部拷贝到tmp中
		tmp[k++] = a.a[i++];
	while (j <= end)
		tmp[k++] = a.a[j++];
	for (int index = start; index < start + len; index++)
		a.a[index] = tmp[index];	//将tmp中排好序的元素拷贝回去
}
//基数排序or桶排序
int maxbit(arr& a)	//获取最大值的位数
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
	int* count = new int[10];	//计数器，用于记录序列中有相同基数的元素的个数
	int* tmp = new int[a.len + 1];	//临时数组，用于记录每趟排序后的序列
	for (int i = 1; i <= d; i++)
	{
		for (int j = 0; j < 10; j++)
			count[j] = 0;	//将计数器置为0
		for (int j = 1; j <= a.len; j++)
			count[(a.a[j] / radix) % 10]++;	//记录有相同基数的元素的个数
		for (int j = 1; j < 10; j++)//让count记录j之前所有元素的个数
			count[j] = count[j - 1] + count[j];	//count记录有基数为j的元素在有序序列的从后往前(从高到低)的位置
		for (int j = a.len; j >= 1; j--)
			tmp[count[(a.a[j] / radix) % 10]--] = a.a[j]; //将原序列中的元素在tmp中进行排序
		for (int j = 1; j <= a.len; j++)
			a.a[j] = tmp[j];	//将tmp中的序列拷贝进原序列中
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