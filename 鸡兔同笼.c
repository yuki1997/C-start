/*鸡兔同笼问题。一个笼子里面关了若干只鸡和兔子（鸡有2只脚，兔子有4只脚，没有例外）。已经知道了笼子里面脚的总数a，问笼子里面至少有多少只动物，至多有多少只动物。
输入：总脚数a  输出：最少动物数   最多动物数（如果没有满足要求的动物数，则输出两个0）*/
#include<stdio.h>
int main( )
{
  int cook,rabbit,a;
  int i,j;
  scanf("%d", &a);
  for(i = 0;i < a;i++){
    for(j = 0;j < a;j++)
      if(2*cook + 4*rabbit == a)
        printf("%d %d\n",cook,rabbit);
  }
  return 0;
}
