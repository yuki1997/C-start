/*5.	[DAY 3]素数判定。给定一个整数n，要求判断其是否为素数。输入：n；输出：0或1，0表示不是，1表示是。规定负数都是非素数）*/

#include<stdio.h>
_Bool is_Prime(unsigned int n)
{
  int i;
  for(i = 2;i <= n/2;++i)
  {
    if(n%i == 0){
      return 0;
      break;
    }
    else
      return 1;
  }
}
int main()
{
  unsigned int n;
  scanf("%d",&n);
  printf("%d\n",is_Prime(n));
}
