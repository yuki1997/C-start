
#include<stdio.h>
int main()
{
  int a[]={3,5,8,12,99,6,2,3,-15,7,0,-5,17,99,-15,22,18,99};
  double b[]={3,5,8,12,6,2,3.5,7,0,-5,17.8,99,-15.7,22.2,18};
  double c[]={3,5,8,12,6,2,3,7,0,5,17,99,15,22,18};
  int arrlen = sizeof(a)/sizeof(a[0]);
  int i = arrlen - 1;
  while(i > 0){
    printf("%d��",a[i]);
    --i;
  }
  printf("%d\n",a[0]);
  return 0;
}
  
