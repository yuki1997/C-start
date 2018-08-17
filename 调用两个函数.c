/*3.	[DAY 8] 输入一个整数n，当n为偶数时，调用函数求1/2+1/4+...+1/n,当输入n为奇数时，调用另一个函数求1/1+1/3+...+1/n
(要求在主调函数中必须利用函数指针)*/
#include<stdio.h>
double osh(int n)
{
  double sum=0;
  int i;
    for(i=2;i<=n;i+=2)
        sum+=1.0/i;
    return sum;
}
double jsh(int n)
{
  double sum=0;
  int i;
    for(i=1;i<=n;i+=2)
         sum+=1.0/i;
    return sum;
}
void main()
{
  int n;
  double (*p)(int);
  printf("请输入一个整数 n：");
  scanf("%d",&n);
  if(n%2==0)
    p= osh;
  else
    p= jsh;
    printf("\n和是: s = %lf\n",(*p)(n));
}
