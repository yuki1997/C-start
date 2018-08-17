//打印出n行的杨辉三角形
#include	<stdio.h>
int main()
{
	int a[100][100]={0};
	int i,j,n;
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j<1)a[i][j]=1;
			else if(i==0)break;
			else
				a[i][j]=a[i-1][j-1]+a[i-1][j];

		}
	}

	for(i=0;i<n;i++)
	{
		for(int k=0;k<n-i-1;k++)
			printf(" ");
		for(j=0;j<=i;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
