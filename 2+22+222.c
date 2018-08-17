/*[DAY 6] 求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加由键盘控制。*/
#include <stdio.h>
int mul(int);
int main()
{
  int a, n, i, k; long sum = 0;
  printf("请输入a和相加个数：");
  scanf("%d%d", &a, &n);
  k = n;
  for (i=1; i<=n; i++){
    sum =  sum +k*a*(mul(i));
    k--;
  }
  printf("%d\n", sum);
  return 0;
}
int mul(int n)
{
  int i, m = 1;
  for (i=2; i<=n; i++){
    m = m*10;
  }
  return m;
}
