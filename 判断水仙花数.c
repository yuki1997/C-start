#include<stdio.h>
int main( )
{
  int n;
	int i,j,k;
  scanf("%d",&n);
  i = n%10;
  j = n/10%10;
  k = n/100;
  printf("%d %d %d",i,j,k);
  if(i*i*i+j*j*j+k*k*k == n)
    printf("Y\n");
  else
    printf("N\n");

	return 0;
}
