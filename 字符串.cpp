/*输入一个字符串，然后在屏幕上显示"Hello, "串后，再接上你刚才输入的那个字符串。例如：输入David   输出：Hello, David*/
#include<stdio.h>
int main()
{
	char s1[200];
	gets(s1);
	printf("Hello,%s\n",s1);
	return 0;
}
