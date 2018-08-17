#include<stdio.h>
int main(void){
    int a[100],i,quit_num,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        a[i]=i+1;
    quit_num=0;
    i=0;

    while(quit_num<n-1){
        if(a[i]!=0)
            k++;
        if(k==3){
            a[i]=0;
            quit_num++;
            k=0;
        }
        i++;
        if(i==n)
            i=0;
    }
    for(i=0;i<n;i++)
        if(a[i]!=0)
    printf("%d\n",a[i]);
    return 0;
}
