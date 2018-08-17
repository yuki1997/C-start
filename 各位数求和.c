//[DAY 4]数字求和。给定一个整数n，分别求其各个数位上的数值之和及其平方数的各个数位上的数值之和。例如：输入：7，输出：7  13
#include<stdio.h>
int f(int n)
{
  int x = n*n;
  int sum=0;
  while(x > 0){
      sum += x%10;
      x = x/10;
    }
  return sum;
}
int main()
{
  int x;
  scanf("%d",&x);
  printf("%d\n",f(x));
  return 0;
}
