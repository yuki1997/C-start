#include<stdio.h>
int main()
{
	int a[]={3,5,8,12,99,6,2,3,-15,7,0,-5,17,99,-15,22,18,99};
	int c[]={3,5,8,12,16,16,22,23,37,37,50,55,67,79,85,92,98};
	int d[]={93,85,78,72,72,62,53,37,30,25,17,9,8};

	double avg3,avg,sum = 0;
	int i;
	int arrlen = sizeof(a)/sizeof(a[0]);

	avg3 = (a[0]+a[arrlen - 1]+a[arrlen/2+1])/3;
	for(i = 0;i < arrlen;i++)
		sum += a[i];
	avg = sum/arrlen;
	printf("%.2lf\n",avg3 - avg);

	return 0;
}
