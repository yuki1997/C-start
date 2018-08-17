#include<stdio.h>
void main()
{
    int i,j,k;
    for(i=1;i<=1000;i++)
    {
        k=0;
        for(j=1;j<=i-1;j++)
            if(i%j==0) k+=j;
        if(k==i) printf("%d\n",i);
    }
}
