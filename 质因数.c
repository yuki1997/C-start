/*质因数的个数。求正整数N(N>1)的质因数的个数。相同的质因数需要重复计算。如120=2*2*2*3*5，共有5个质因数。 输入：N， 输出：质因数的个数*/
#include <stdio.h>

  int main()
  {
    int n, count, i;
    scanf("%d",&n);
      count = 0;

      for (i = 2; i * i <= n; i ++) {
        if(n % i == 0) {
          while (n % i == 0) {
            count ++;
            n /= i;
          }
        }
      }

      if (n > 1) {
        count ++;
      }

    printf("%d\n", count);
    return 0;
  }
