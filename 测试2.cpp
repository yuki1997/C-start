#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	float a,b;
	scanf("%f",&a);
	
	b = 1.852*a;
	if(a >= 0)
		printf("%f\n",b);
	else
		printf("²»¿ÉÄÜ\n");
	
	return 0;
} 
