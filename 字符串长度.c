#include<stdio.h>
char len(char str[200])
{
  int len,count = 0,i;
  for(i = 0;str[i] != '\0';i++)
  {
    count++;
  }
  return count;
}
int main()
{
  char s[200];
  gets(s);
  printf("%d\n",len(s));
  return 0;
}
