#include<stdio.h>
#include<string.h>
int main( )
{
  char s[200];
  int cnt_words = 0,
      cnt_space = 0,
      cnt_num = 0,
      cnt_other = 0,
      i = 0;
  gets(s);
  for(i = 0;i < strlen(s);i++){
    if((s[i] >= 'A'&& s[i] <= 'Z')||(s[i] >= 'a'&& s[i] <= 'z'))
      cnt_words++;
    else if(s[i] >= '0'&& s[i] <= '9')
      cnt_num++;
    else if(s[i] == ' ')
      cnt_space++;
    else
      cnt_other++;
  }
  printf("字母：%d\n数字：%d\n空格：%d\n其他：%d\n",cnt_words,cnt_num,cnt_space,cnt_other);
  return 0;
}
