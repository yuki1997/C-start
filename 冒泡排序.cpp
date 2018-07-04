#include<stdio.h>
int main()
{
	int a[10];
	int i,j,t;
	for(i = 1;i <= 10;i++)
		scanf("%d",&a[i]);
	for(i = 1; i <= 9;i++)
	{
		for(j = 1;j < 10 - i;j++)
		{
			if(a[j] < a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for(i = 1;i <= 10;i++)
		printf("%d ",a[i]);	
}
