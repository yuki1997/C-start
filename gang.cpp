#include<stdio.h> 
#include<math.h>
/* 
int main( )
{
	int i;
	int x = 0;
	for(i = 100;i <= 999;i++)
	{
			
		if(i % 3 == 0)//判断 
		{
			printf("%d",i);
			++x;
			if(x % 20 == 0)//换行 （每20个一行） 
				printf("\n");
			else 
				printf(",");	
			
		}
	}
}

int main()
{
    int i, j;
    int count = 0;
    for (i = 101; i <= 999; i++)
    {
        int flag = 1;
        for (j = 2; j <= i - 1; j++)
        {
            if (i%j == 0) //如果不是素数，应该直接跳出循环，计算下一个i
            {
                flag=0; //并设置标志为0
                break;
            }            
        }
        if (flag==1)  //在循环之外判断标志，如果是break出来的，肯定flag = 0，即不是素数
        {
            count++;
            printf("%d", i);
            if (count % 20 == 0)
            {
                printf("\n");
            }
            if(count %20 != 0)
            {
            	printf(",");
			}
        }        
    }
    return 0;
}
*/

int main( )
{
	int n=1;
	float temp;
	float sum=0;
	do
	{
		temp=(float)1/(2*n-1);
		if(n%2==1)
			sum+=temp;
		else
			sum-=temp;
		n++;
	}while(temp>=0.00001);
	printf("Pi=%f\n",sum*4);
}
