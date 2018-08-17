/*矩阵转置。输入一个N*N的矩阵（2<=N<=10），将其转置后输出。要求：不得使用任何数组(就地逆置)。输入：第一行是整数n，接下来的n行每行输入n个整数   输出：逆置后的n*n的矩阵*/
#include <stdio.h>
int main(void)
{
     int n,i,j,t,a[100][100];
  scanf("%d",&n);
     for(i=0;i<n;i++)
          for(j=0;j<n;j++)
               scanf("%d", &a[i][j]);

          for(i=0;i<n;i++)
              for(j=0;j<n;j++)
                  if(i<=j){
                      t=a[i][j];
                      a[i][j]=a[j][i];
                      a[j][i]=t;}
      for(i=0;i<=n-1;i++)
      {
       for(j=0;j<=n-1;j++)
        printf("%d  ",a[i][j]);
       printf("\n");
      }
      return 0;
}
