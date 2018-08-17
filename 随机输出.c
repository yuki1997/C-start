//随机生成1000个1~20之间的数，不用输出这些数，但要统计并输出每个数出现的次数。
#include<stdio.h>
#include<stdlib.h>
#define NUM 1000
int main()
{
   int i,l;
   int a[20]={0,0,0,0,0,0,0,0,0,0};
   srand(1000);
   for(i=0;i<NUM;i++)
   {
  switch((rand()%20+1))
  {
  case 1:a[0]+=1;break;
  case 2:a[1]+=1;break;
  case 3:a[2]+=1;break;
  case 4:a[3]+=1;break;
  case 5:a[4]+=1;break;
  case 6:a[5]+=1;break;
  case 7:a[6]+=1;break;
  case 8:a[7]+=1;break;
  case 9:a[8]+=1;break;
  case 10:a[9]+=1;break;
  case 11:a[10]+=1;break;
  case 12:a[11]+=1;break;
  case 13:a[12]+=1;break;
  case 14:a[13]+=1;break;
  case 15:a[14]+=1;break;
  case 16:a[15]+=1;break;
  case 17:a[16]+=1;break;
  case 18:a[17]+=1;break;
  case 19:a[18]+=1;break;
  case 20:a[19]+=1;break;
  default:break;}
}
   for(l=1;l<11;l++)
  printf(" 数字%3d 出现%4d 次\n",l,a[l-1]);
  }
