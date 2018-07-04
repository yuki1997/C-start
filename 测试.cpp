#include<stdio.h>
int main( )
{
	int n;
	scanf("%d",&n);	
	int a[n];
	int i,max,min,maxid,minid,temp;
	for(i = 0;i < n;i++)
		scanf("%d",&a[i]);
	max = a[0];
	min = a[0];
	for(i = 1;i < n;i++)
	{
		if(max < a[i]){ 
			maxid = i;
			max = a[i];
		}
		if(min > a[i]){
			minid = i;
			min = a[i];
		}
	}
	temp = a[maxid];
	a[maxid] = a[minid];
	a[minid] = temp;
	for(i = 0;i < n;i++)
		printf("%d ",a[i]);
	return 0;
 } 
