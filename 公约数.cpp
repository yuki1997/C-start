/*公约数和公倍数。输入两个整数，
求出它们的最大公约数和最小公倍数
（在同一行上输出，中间用一个空格分隔）*/
#include<stdio.h>
int main( )
{
	int a,b,r,m,n;
	scanf("%d%d",&a,&b);
	m = a;
	n = b;
	while(b)
	{
		r = a%b;
		a = b;
		b = r;
	}
	printf("%d %d\n",a,m*n/a);
	return 0;
}

