#include<stdio.h>
int main( )
{
	int n = 100;
	int i;
	while(n<=999)
	{
		while(i <=999){
			
		if(n%3 == 0)
			printf("%d,",n);
		if(i%20 == 0)
			printf("\n");
		n++;
		i++;
		}
	}
 } 
