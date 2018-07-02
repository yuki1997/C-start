#include<stdio.h>
int main( )
{
  int i;
  int cnt = 0;
  for(i = 1000;i <= 2000;i++){
    if(i%12 == 0 && i%16 == 0){
      cnt++;
      printf("%d ",i);
    if(cnt % 5 == 0)
        printf("\n");
      }
  }
}
