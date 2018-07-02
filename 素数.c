
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
