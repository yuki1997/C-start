// top n。输出某次考试（总人数m）中前n（n<=m）名的成绩（按降序输出）。当m和n均为0时，程序结束。 输入：第一个输入整数m和n，第二行输出m个成绩。
//输出：在一行上输出n个成绩（降序），成绩之间用一个空格分隔。
#include<stdio.h>
int main()
{
  int m,n,temp,i;
  scanf("%d%d",&m,&n);
  int a[m];
  int max = a[0];
  int min = a[0];
  for(i = 0;i < m;i++)
    scanf("%d",&a[i]);
  for(i = 0;i < m;i++)
    printf("%d ",a[i]);
  printf("\n");
  for(i = 1;i < m;i++){
    if(max < a[i]){
      temp = max;
      max = a[i];
      a[i] = temp;
    if(min > a[i]){
      temp = min;
      min = a[i];
      a[i] = temp;
    }
    }
  }
  for(i = 0;i < n;i++)
    printf("%d ",a[i]);
  printf("\n");
}
