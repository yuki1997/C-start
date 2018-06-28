/*新百鸡问题。用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每
只的一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。 输入：n；输出：
对于每组输入,请输出x,y,z所有可行解，按照x，y，z依次增大的顺序输出。*/
#include<stdio.h>
int main()
{
    int n;
    int chicken,cook,littlechicken;
    scanf("%d",&n);
    for(chicken = 0;chicken <= 100;chicken++){
      for(cook = 0;cook <= 100;cook++){
        littlechicken = 100 - chicken - cook;
        if(chicken*5+cook*3+littlechicken/3==n){
          if(chicken < cook < littlechicken)
            printf("chicken:%d cook:%d littlechicken:%d\n",chicken,cook,littlechicken);
          }
      }
    }
    return 0;
}
