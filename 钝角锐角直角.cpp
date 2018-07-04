/*判断三角形类型。输入三个数值（保证一定可以构成三角形），判断该三角形的类型（直角三角形、锐角三角形、钝角三角形）。*/
#include<stdio.h>
int main( )
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a+b>c&&a+c>b&&b+c>a)
	{
		if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
			printf("直角三角形\n");
		else if(a*a>b*b+c*c||b*b>a*a+c*c||c*c>a*a+b*b)
			printf("钝角三角形\n");
		else if(a*a<b*b+c*c||b*b<a*a+c*c||c*c<a*a+b*b)
			printf("锐角三角形\n"); 
	}
	return 0;
 }
