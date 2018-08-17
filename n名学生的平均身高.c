/*求平均身高。班上有学生若干名，给出每名学生的身高（整数，厘米数），求班上所有学生的平均身高，保留到小数点后一位。
输入：第一行输入一个n表示学生数，第二行输入n个整数，表示n个学生的身高。 输出：n个学生的平均身高值。*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int sum=0,i,n,a[100];
   int b;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
       sum=sum+a[i];
   }
   b=sum/n;
   printf("%d\n",b);
    return 0;
}
