/*3.	[DAY 6] 众数。输入20个数，每个数都在1-10之间，求这些数中的众数（众数就是出现次数最多的数，
如果存在一样多次数的众数，则输出权值较小的那一个）。例如输入：5 1 5 10 3 5 3 4 10 6 8 3 6 5 10 7 10 2 6 2  输出：5*/
#include <stdio.h>
int main()
{
    int a[50];
    int i,j,maxCount=0,index=0,nCount=0;
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j]==a[i])
                nCount++;
        }

        if(nCount>maxCount)
        {
            maxCount=nCount;
            index=i;
        }

        nCount=0;
    }
    printf("%d\n",a[index]);
}
