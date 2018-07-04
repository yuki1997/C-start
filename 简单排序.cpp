#include<stdio.h>
int main( )
{
	double a,b,c,m = 0;
	scanf("%lf%lf%lf",&a,&b,&c);
	
	if(a < b){
		m = a;
		a = b;
		b = m;
	}
	if(a < c){
		m = a;
		a = c;
		c = m;
	}
	if(b < c){
		m = b;
		b = c;
		c = m;
	}
	printf("%.2lf > %.2lf > %.2lf\n",a,b,c);
 } 
