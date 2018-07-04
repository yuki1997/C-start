#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

/*
	Name: show
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：显示数组中的每一个元素，每10个数占一行
				数字之间用空格分开显示
		参数：
			int from[]：数组的首地址
			int len：数组长度
		返回值：
			无
*/
void show(int from[], int len){
	int i;
	for(i=0;i<len;i++)
		if((i+1)%10)
			printf("%d ",from[i]);
		else
			printf("%d\n",from[i]);
	printf("\n\n");
}

/*
	Name: insertSort
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：用插入排序算法对数组进行排升序
		参数：
			int from[]：数组的首地址
			int len：数组长度
		返回值：
			无
*/
void insertSort(int from[], int len){
	int i,j;
	for(i=1; i<len;++i){
		int t=from[i];
		if(t<from[0])
			for(j=i-1;j>=0;--j)
				from[j+1]=from[j];
		else
			for(j=i-1;t<from[j];--j)
				from[j+1]=from[j];
		from[j+1]=t;
	}
}

/*
	Name: shell_help
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：希尔排序的辅助函数，供内部调用
*/
void shell_help(int arr[], unsigned len, unsigned span)
{
	unsigned i;
	int j;
	for(i=span; i<len; i+=span)
	{
		int t=arr[i];
		if(t<arr[0])
			for(j=i-span; j>=0; j-=span)
				arr[j+span]=arr[j];
		else
			for(j=i-span; t<arr[j]; j-=span)
				arr[j+span]=arr[j];
		arr[j+span]=t;
	}
}

/*
	Name: shellSort
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：用希尔排序算法对数组进行排升序
		参数：
			int arr[]：数组的首地址
			unsigned len：数组长度
		返回值：
			无
*/
void shellSort(int arr[], unsigned len)
{
	unsigned w=2;
	unsigned span=len/w;
	while(span)
	{
		unsigned i;
		for(i=0; i<span; ++i)
			shell_help(&arr[i], len-i, span);
		if(span<w && span!=1)
			span=1;
		else
			span/=w;
	}
}

/*
	Name: swap
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：交换两个整数
		参数：
			int *a：第一个数的指针
			int *b：第二个数的指针
		返回值：
			无
*/
void swap(int *a, int *b)
{
	if(a!=b)
	{
		int t=*a;
		*a=*b;
		*b=t;
	}
}

/*
	Name: selectSort
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：用选择排序算法对数组进行排升序
		参数：
			int arr[]：数组的首地址
			unsigned len：数组长度
		返回值：
			无
*/
void selectSort(int arr[], unsigned len)
{
	unsigned i, j;
	for(i=0; i<len-1; ++i)
	{
		unsigned pos=0;
		for(j=1; j<len-i; ++j)
			if(arr[pos]<arr[j])
				pos=j;
		swap(&arr[pos], &arr[len-i-1]);
	}
}

/*
	Name: bubbleSort
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：用冒泡排序算法对数组进行排升序
		参数：
			int arr[]：数组的首地址
			unsigned len：数组长度
		返回值：
			无
*/
void bubbleSort(int arr[], unsigned len)
{
	unsigned i, j;
	bool swapped;
	for(i=0; i<len-1; ++i)
	{
		swapped=0;
		for(j=0; j<len-1-i; ++j)
			if(arr[j+1]<arr[j])
			{
				swap(&arr[j+1], &arr[j]);
				swapped=1;
			}
		if(!swapped) break;
	}
}

/*
	Name: merge
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：归并辅助函数
*/
void merge(const int a[], int lena, const int b[], int lenb, int c[])
{
	int i=0, j=0;
	while(i<lena && j<lenb)
		if(b[j]<a[i])
			*c++=b[j++];
		else
			*c++=a[i++];
	while(i<lena)
		*c++=a[i++];
	while(j<lenb)
		*c++=b[j++];
}

/*
	Name: mergeSort
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：用归并排序算法对数组进行排升序
		参数：
			int arr[]：数组的首地址
			unsigned len：数组长度
		返回值：
			无
*/
void mergeSort(int arr[], unsigned len)
{
	unsigned i, m=1;
	int* tarr=(int*)malloc(sizeof(int)*len);
	while(m<len)
	{
		for(i=0; i<len; i+=2*m)
			merge(&arr[i], i+m<len?m:len-i, &arr[i+m],
				i+2*m<len?m:len-i-m, &tarr[i]);
		m*=2;
		for(i=0; i<len; i+=2*m)
			merge(&tarr[i], i+m<len?m:len-i, &tarr[i+m],
				i+2*m<len?m:len-i-m, &arr[i]);
		m*=2;
	}
	free(tarr);
}

/*
	Name: cocktailSort
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：用鸡尾酒排序算法对数组进行排升序
		参数：
			int arr[]：数组的首地址
			unsigned len：数组长度
		返回值：
			无
*/
void cocktailSort(int arr[], unsigned len)
{
	int i, lower=0, upper=len-1;
	bool swapped;
	while(lower<upper)
	{
		swapped=0;
		for(i=lower; i<upper; ++i)
			if(arr[i+1]<arr[i])
			{
				swap(&arr[i+1], &arr[i]);
				swapped=1;
			}
		--upper;
		for(i=upper-1; i>=lower; --i)
			if(arr[i+1]<arr[i])
			{
				swap(&arr[i+1], &arr[i]);
				swapped=1;
			}
		++lower;
		if(!swapped) break;
	}
}

/*
	Name: adjustHeap
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：调整堆的临时函数，内部调用
*/
void adjustHeap(int arr[], unsigned len, unsigned hole)
{
	unsigned left=2*hole+1;  //洞结点的左孩子
	unsigned right=2*hole+2;  //洞结点的右孩子
	int t=arr[hole];  //保存洞结点的值
	while(left<len && t<arr[left] || right<len && t<arr[right])
	//某个孩子结点比洞结点值大
	{
		if(right<len && arr[left]<arr[right])
		//有右孩子，且右孩子大，右孩子上移，洞下移
		{
		  	arr[hole]=arr[right];
		  	hole=right;
		}
		else
		//左孩子大，左孩子上移，洞下移
		{
			arr[hole]=arr[left];
			hole=left;
		}
		//重新设置洞的左右孩子下标
		left=hole*2+1;
		right=hole*2+2;
	}
	arr[hole]=t;
}

/*
	Name: makeHeap
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：把指定的数组构建成堆
		参数：
			int arr[]：数组的首地址
			unsigned len：数组长度
		返回值：
			无
*/
void makeHeap(int arr[], unsigned len)
{
	int i;
	for(i=len/2-1; i>=0; --i)
		adjustHeap(arr, len, i);
}

/*
	Name: popHeap
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：出堆，临时函数，内部调用
*/
void popHeap(int arr[], unsigned len)
{
	swap(&arr[0], &arr[len-1]);
	adjustHeap(arr, len-1, 0);
}

/*
	Name: heapSort
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：用堆排序算法把数组排为升序
		参数：
			int arr[]：数组的首地址
			unsigned len：数组长度
		返回值：
			无
*/
void heapSort(int arr[], unsigned len)
{
	int i;
	for(i=len; i>1; --i)
		popHeap(arr, i);
}

/*
	Name: showNum
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：显示指定的整数
		参数：
			int num：待显示的整数
		返回值：
			无
*/
void showNum(int num)
{
	printf("the number is: %d\n", num);
}

/*
	Name: biSearch
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：用折半查找法查找指定数据是否出现在数组中
		参数：
			const int* from：原始数组的首地址
			int len：数组长度
			int v：待查找的数据
		返回值：
			bool：找到返回true，没找到返回false
*/
bool biSearch(const int* from, int len, int v)
{
	int L=0;
	int H=len-1;
	int M=(L+H)/2;
	while(L<=H)
		{
			if(v<from[M])
				H=M-1;
			else if(from[M]<v)
				L=M+1;
			else return true;
			M=(L+H)/2;
		}
	return false;
}

/*
	Name: showSource
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：显示运算之前的浮点数，保留2位小数
		参数：
			double source：原始浮点数
		返回值：
			无
*/
void showSource(double source)
{
	printf("the source number is: %.2lf\n", source);
}

/*
	Name: showResult
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：显示运算之后的浮点数，保留2位小数
		参数：
			double result：运算后的浮点数
		返回值：
			无
*/
void showResult(double result)
{
	printf("the result number is: %.2lf\n", result);
}

/*
	Name: sequentialSearchByArray
	Copyright: Neusoft
	Author: Dongqing Zhang
	Date: 04/07/18 09:23
	Description:
		功能：顺序查找算法，从数组中查找是否存在要查找的值
		参数：
			int from[]：原始数组
			int len：数组长度
			int v：待查找的整数
		返回值：
			bool：找到返回true，没找到返回false
*/
bool sequentialSearchByArray(int from[], int len, int v){
	int i;
	for(i=0;i<len;++i)
		if(from[i]==v) return true;
	return false;
}

int main()
{
	int a[]={3,5,8,12,99,6,2,3,-15,7,0,-5,17,99,-15,22,18,99};
	int b[]= {1,4,5,7,9,11,44,55,77,5554};
	int n1=5, n2=5000;
	double x1=5.25, y1;
	srand((unsigned int)time(NULL));
	int lenb = sizeof(b)/sizeof(b[0]);
	int result1 = biSearch(b,lenb,n1);

	if(result1 == 0)
		printf("找不到\n");

	else if(result1 == 1)
	{
		for(int i = 0;i < lenb;i++)
			if(n1 == b[i])
				printf("%d\n", i);
	}

	int result2 = biSearch(b,lenb,n2);

	if(result2 == 0)
		printf("找不到\n");

	else if(result2 == 1)
	{
		for(int i = 0;i < lenb;i++)
			if(n2 == a[i])
				printf("%d\n", i);
	}

	return 0;
}
