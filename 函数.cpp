/*编写程序，输入一个浮点数x，计算下列分段函数y=f(x)的值。
y=-x+2.5; 0<=x<2
y=2-1.5(x-3)(x-3); 2<=x<4
y=x/2-1.5; 4<=x<6
*/
#include<stdio.h>
float f(float x)
{
	if(x >= 0&&x < 2)
		return -1*x+2.5;
	if(x >= 2&&x < 4)
		return 2-1.5*(x-3);
	if(x >= 4&&x < 6)
		return x/2-1.5;

 }
int main( )
{
	float n;
	scanf("%f",&n);
	printf("%.2f\n",f(n));
	return 0;
}
