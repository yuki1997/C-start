//[DAY 4]数字求和。给定一个整数n，分别求其各个数位上的数值之和及其平方数的各个数位上的数值之和。例如：输入：7，输出：7  13
#include<stdio.h>
int f(int n)
{
  if(n>=10)
    f(n/10);
  while(n > 10){
    printf("%d ",n%10);
    n = n%10;
  }
  return n%10;
}
int main( )
{
  int n;
  scanf("%d",&n);
  f(n);
  //printf("%d %d\n", n,f(n));
  return 0;
}
