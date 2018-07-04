#include<stdio.h>
#include<string.h>
int main( )
{
	char s;
	scanf("%s",&s); 


		if(s >= 'A'&&s <= 'Z')
			s =s + 32;
		else if(s >= 'a'&&s <'z')
			s = s-32;
	
	printf("%c\n",s);
 } 
