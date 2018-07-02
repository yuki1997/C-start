
#include<stdio.h>
int main( )
{
  int h,i,j;
  scanf("%d",&h);
  while(h){
    if(h < 1||h > 1000)
      continue;
    else{
      for(i = 0;i < h;i++){
        for(j = 0;j < 2*h-2-2*i;j++)
          printf(" ");
        for(j = 0;j < h+2*i;j++)
          printf("*");
        printf("\n");
      }
    }
    h--;
  }
  return 0;
}
