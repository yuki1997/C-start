/*找同样的值。输入一个数n，然后输入n个数值各不相同，
再输入一个值x，输出x在这个数组中的所有下标
（从0开始，若不在数组中则输出-1）。*/
#include<stdio.h>
#define N 10
int main( )
{
	int n,a[N],count = 0;
	int i;
	scanf("%d",&n);
	for(i = 0;i < N;i++)
		scanf("%d",&a[i]);
	for(i = 0;i < N;i++)
	{
		if(n == a[i])
			printf("%d ",i);
		count++;
	}
	if(count == 0)
		printf("-1");
}

