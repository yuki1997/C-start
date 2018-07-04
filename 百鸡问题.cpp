/*新百鸡问题。用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的
一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。
 输入：n；输出：对于每组输入,请输出x,y,z所有可行解，
 按照x，y，z依次增大的顺序输出*/
#include<stdio.h>
int fun( )
{
	int cook,hen,chicken,n;
	scanf("%d",&n);
	for(cook = 0;cook <= n/5;cook++)
		for(hen = 0;hen <= n/3;hen++){
				chicken = 100 - hen - cook;
				if(5*cook+3*hen+chicken/3.0 == n){
					printf("cook:%d hen:%d chicken:%d\n",cook,hen,chicken);
			}
		}
 }
 int main( )
 {
 	fun( );
 	return 0;
  } 
