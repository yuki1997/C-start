#include<stdio.h>
#include<math.h>
int main( )
{
	double a,b,c,x1,x2,dt,p,q;
	scanf("%lf%lf%lf",&a,&b,&c);
	dt=sqrt(b*b-4*a*c);
    p=-b/(2*a);
    q=dt/(2*a);
    x1=p+q;
    x2=p-q;
    printf("x1=%6.2f x2=%6.2f\n",x1,x2);
 } 
