//两个字符串连接。（不允许用strcat函数）
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j;
    char str1[100],str2[100],str3[201];
    gets(str1);
    gets(str2);
    for(i=0;str1[i]!='\0';i++)
        str3[i]=str1[i];
    for(j=0;str2[j]!='\0';j++)
        str3[j+i]=str2[j];
        str3[j+i]='\0';
    printf("%s\n",str3);
    return 0;
}
