/*4.	[DAY 4]字符统计。输入一个字符串（长度小于200），求非字母字符的个数。例如：输入：aB.+.2C:w   输出：5*/
#include<stdio.h>
#include<string.h>
int main( )
{
    char s[200];
    gets(s);
    int i,
        cnt = 0;
    for(i = 0;i < strlen(s);i++)
    {
      if((s[i] >= 'a'&& s[i] <= 'z') || (s[i] >= 'A' && s[i] < 'Z'))
        cnt++;
    }
    printf("%d\n",strlen(s)-cnt);
    return 0;
}
