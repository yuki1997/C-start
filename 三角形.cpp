#include<stdio.h>
#include<math.h>
int main( )
{
	double a,b,c,s,area;
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a+b>c&&a+c>b&&b+c>a){
		s = (a+b+c)/2;
		area = sqrt(s*(s-a)*(s-b)*(s-c));
		printf("%.2lf\n",area);
	}
	else
		printf("不能构成三角形\n");
 } 
