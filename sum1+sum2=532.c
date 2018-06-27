/*设a、b、c均是0到9之间的数字，abc、bcc是两个三位数，且有：abc+bcc=532。求满足条件的所有a、b、c的值。*/
#include<stdio.h>
int main( )
{
  int a,b,c;
  int sum1,sum2;
  int i,j;
  for(a = 1;a < 10;a++){
    for(b = 1;b < 10;b++){
      for(c = 0;c < 10;c++){
        sum1 = a*100+b*10+c;
        sum2 = b*100+c*10+c;
        if(sum1+sum2 == 532){
          printf("%d %d %d\n",a,b,c);
        }
      }
    }
  }
    return 0;
}
