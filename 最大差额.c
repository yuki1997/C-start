#include<stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int a[n],i,max,min;
  for(i = 0;i < n;i++)
    scanf("%d",&a[i]);
  max = a[0];
  min = a[0];
  for(i = 1;i < n;i++){
    if(max < a[i])
      max = a[i];
    if(min > a[i])
      min = a[i];
  }
  printf("%d\n",max - min);
}
