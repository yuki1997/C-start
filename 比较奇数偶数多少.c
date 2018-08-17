/*谁多谁少？第一行输入一个数，为n，第二行输入n个数，这n个数中，如果偶数比奇数多，输出NO，否则输出YES。*/
#include<stdio.h>
_Bool f(int n)
{
  int a[n];
  int i;
  int cnt = 0,
      cnt1 = 0;
  for(i = 0;i < n;i++)
    scanf("%d",&a[i]);
  for(i = 0;i < n;i++){
    if(a[i] % 2 == 0)
      cnt++;
    else if(a[i] % 2 != 0)
      cnt1++;
  }
  if(cnt > cnt1)
    return 0;
  else
    return 1;
}
int main( )
{
  int n;
  scanf("%d",&n);
  if(f(n) == 0)
    printf("No\n");
  else
    printf("YES\n");
}
