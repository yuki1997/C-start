/*鸡兔同笼问题。一个笼子里面关了若干只鸡和兔子（鸡有2只脚，兔子有4只脚，没有例外）。已经知道了笼子里面脚的总数a，问笼子里面至少有多少只动物，至多有多少只动物。
输入：总脚数a  输出：最少动物数   最多动物数（如果没有满足要求的动物数，则输出两个0）*/
#include<stdio.h>
int main( )
{
  int a,i;
  scanf("%d", &a);
  if(a % 2 != 0)
    printf("least: 0 most: 0\n");
  else if(a %4 != 0)
    printf("least: %d most: %d\n",a / 4 + 1, a / 2);
  else
    printf("least: %d most: %d\n",a / 4, a / 2);

}
