#include<stdio.h>
#include<string.h>
#define N 200
void fun( )
{
	char str[N];
	int i,j;

	gets(str);

	i = 0;
	j = strlen(str) - 1;
	while(i < j)
	{
		if(str[i] == str[j])
		{
			i++;
			j--;
		}
		else
			break;
	}
	if(i >= j)
		printf("Yes\n");
	else
		printf("No\n");
		}
int main( )
{
	fun();
	return 0;
}
