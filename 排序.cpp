/*输入三个整数，将它们按从小到大的顺序排列并输出。*/
#include<stdio.h>
int main( )
{
	int a[3],i,t = 0,t1 = 0,t2 = 0;
	for(i = 0;i < 3;i++)
		scanf("%d",&a[i]);
	t = a[0];
	t1 = a[1];
	t2 = a[2];
	for(i = 1;i < 3;i++)
		{
			if(a[i] > t);
				t = a[i];
		}
	printf("%d",t);
	for(i = 2;i < 3;i++)
		{
			if(a[i] != t&&a[i] > t1)
				t1 = a[i];
		}
		printf(",%d,",t1);
	for(i = 0;i < 3;i++)
	{
		if(a[i] != t&&a[i] != t1)
			printf("%d\n",a[i]);
	}
	return 0;
 }
