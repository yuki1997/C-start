/*最大差额。第一行输入一个整数N（2<=N<=100），接着输入N个数，求这N个数的最大差额。*/ 
#include<stdio.h>
int main( )
{
	int N;
	scanf("%d",&N);
	int a[N],max,min,i,delta;
	for(i = 0;i < N;i++)
		scanf("%d",&a[i]);
	max = a[0];
	min = a[0];
	for(i = 1;i < N;i++)
	{
		if(max < a[i])
			max = a[i];
		if(min > a[i])
			min = a[i];
	}
	delta = max - min;
	printf("%d",delta);
	return 0;	
 } 
