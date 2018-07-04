#include<stdio.h>
#define PI 3.14
int main( )
{
	double r,h,l,s,bs,v;
	scanf("%lf%lf",&r,&h);
	l = PI*r*2;
	s = PI*r*r;
	bs = s * 2 + l * h;
	v = s * h;
	printf("圆的周长为%.2lf，圆的面积为%.2lf,圆柱的表面积为%.2lf,圆柱的体积为%.2lf\n",l,s,bs,v); 
}
