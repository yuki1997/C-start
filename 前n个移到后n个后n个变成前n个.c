//有n个整数，使其前面各数顺序向后移m个位置，最后m个数变成最前面的m个数。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void move(int *p, int n, int m)
{
  int i, temp;
  if (m > 1)
  for (i = 0; i < m; i ++)
    move(p, n, 1);
  else
  {
    temp = p[n-1];
    for (i = n-1; i > 0; i --)
      p[i] = p[i-1];
    p[0] = temp;
  }
}

void main()
{   void move(int *p,int n,int m);
   int a[10];
   int *p=a;
   int m,n;
   printf("input the n:\n");
   scanf("%d",&n);
      printf("input the num:\n");
      for(p=a;p<a+n;)
		  scanf("%d",p++);
	     printf("input the m:\n");
         scanf("%d",&m);
		 p=a;
		 move(p,n,m);
		 for(p=a;p<a+n;)
		 printf("%d ",*p++);
     printf("\n");
}
