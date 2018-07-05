/***3.字符串替换。在主串S中查找子串T，将所有的T都替换成字符串R。***/
#include<stdio.h>
#include<string.h>
void replace (char *s, char *t, char *q)
{
    int i,j,k;
    int lens=strlen(s);
    int lent=strlen(t);
    int lenq=strlen(q);

    for(i=0;i<=lens-lent;i++){
    k=i;
    for(j=0;j<lent;j++,k++){
    if(s[k]==t[j])
    continue;
    else break;
    }
    if(j==lent)
    {
    int p,m,temp;
    p=i+lenq;
    m=lens-lent+lenq;
    for(j=m;j>=i+lenq;j--){
    s[j]=s[j-1];
    }
    for(j=i;j<i+lenq;j++){
    s[j]=q[j-i];
    }
    i=i+lenq;
    }
  }
}
int main()
{
    printf("S：");
    char s[100];
    gets(s);
    printf("\nT:");
    char t[100];
    gets(t);
    printf("\nR:");
    char q[100];
    gets(q);
    replace(s,t,q);
    printf("\n%s\n",s);
}
