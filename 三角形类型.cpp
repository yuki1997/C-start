/*再来判断三角形类型。输入三个数值（保证一定可以构成三角形），判断该三角形的类型（直角三角形、锐角三角形、钝角三角形）。*/
#include<stdio.h>
int main()
{
	float a,b,c;
	scanf("%f%f%f",&a,&b,&c);
	if(a+b>c&&a+c>b&&b+c>a)
	{
		if(a==b&&a==c&&b==c)
			printf("等边三角形\n");
		else if((a == b||a == c||b == c)&&(a!=b||b!=c||a!=c))
			printf("等腰三角形\n");
		else
			printf("一般三角形\n");
	}
}
