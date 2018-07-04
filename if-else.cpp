/*输入两个浮点数A和B，如果它们相等，输出"=="，否则，输出"<>"。（精度限定不超过1e-6）。*/
#include<stdio.h>
int main( )
{
	float A,B;
	scanf("%f%f",&A,&B);
	if(A == B)
		printf("==\n");
	else
		printf("<>\n");
 }
