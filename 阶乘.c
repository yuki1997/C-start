//Çó1+2!+3!+...+n!µÄºÍ¡££¨n<15£©
#include<stdio.h>
int sum(int n)
{
  int sum = 0,i,t = 1;
  for(i = 1;i <= n;i++){
    t*=i;
    sum+=t;
    }
  return sum;
}
int main()
{
  int n;
  scanf("%d",&n);
  printf("%d\n",sum(n));
  return 0;
}
