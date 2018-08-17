//有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前n项之和。
#include<stdio.h>
int main()
{
    int a,b,c,i,n;
    float sum;
    a=1;b=2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum=sum+1.0*b/a;
        c=a;
        a=b;
        b=c+b;
    }
    printf("%.2f\n",sum);
    return 0;
}
