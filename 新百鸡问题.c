/*新百鸡问题。用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。
输入：n；输出：对于每组输入,请输出x,y,z所有可行解，按照x，y，z依次增大的顺序输出。*/
#include<stdio.h>
int main( )
{
  int n;
  scanf("%d",&n);
  int x,y,z;
  for(x = 0;x <= n/5;x++){
    for(y = 0;y <= n/3;y++){
      z = 100 - x - y;
      if(5*x+3*y+z/3 == n)
        printf("%d,%d,%d\n",x,y,z);
    }
  }
  return 0;
}
