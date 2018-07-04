/** 2.[DAY 2]字符串反序输出。输入一个字符串（长度小于200）
			第一行反序输出该字符串，第二行原序再输出一遍该字符串。 **/
#include<stdio.h>
#include<string.h>
int main( )
{
	char str1[200],str2[200]; 
	int i,j; 
	gets(str1); 
	int n = strlen(str1);
	i = 0;
	j = n-1; 
	while(i < n){ 
		while(j >= 0){ 
			str2[j] = str1[i];
			i++;
			j--;
		}
	}
	puts(str2); 
	puts(str1); 
 } 


