/*互换最大最小数。输入一个数n，然后输入n个数值各不
相同的数，调换这组数中最大和最小的两个数，然后输出。*/ 
#include<stdio.h>  
#include<stdlib.h>  
     
int main()  
{  
    int n,i;  
    while(scanf("%d",&n)!=EOF)  
    {  
        int num[21],Min,Max,MinIndex,MaxIndex,temp;  
        for(i = 0;i < n;i++){  
            scanf("%d",&num[i]);  
            if(i == 0){  
                Min = num[i];  
                Max = num[i];  
                MinIndex = i;  
                MaxIndex = i;  
            }  
            if(Min > num[i]){  
                Min = num[i];  
                MinIndex = i;  
            }  
            if(Max < num[i]){  
                Max = num[i];  
                MaxIndex = i;  
            }  
        }  
        temp = num[MinIndex];  
        num[MinIndex] = num[MaxIndex];  
        num[MaxIndex] = temp;  
        for(i = 0;i < n;i++){  
            printf("%d",num[i]);  
            if(i != n-1){  
                printf(" ");  
            }  
        }  
        printf("\n");  
    }  
    return 0;  
}  
