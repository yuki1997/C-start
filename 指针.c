#include<stdio.h>
int main(void)
{

  int *p;//声明了一个指针p，类型是，指向整形的
        //此处的*是声明符，不是运算符
  /*int a = 10;
  p = &a;//对指针p进行赋值，存入了变量a的地址
  //(*p) = 5;

  printf("%d\n",*p);//此处的*为解引用的
  printf("%p %p\n",++p,&a);*/
  int a[20];//int 20[a]错误
  int i;
  for(i = 0;i < 20;++i)
    a[i] = i;
  printf("%d\n",a[15]);
  //printf（"%d\n",15[a]);//运算符
  p = &a[0];
  printf("%d\n",*(p+=15));
  //a[k] ==== *(p+k)
  //k[a] ==== *(k+p)

  //for(i = 0;i < 20;++i)
      //printf("%d\n",a[i]);
  //for(i = 0;i < 20;++i)
      //printf("%d\n", *(p+i));
    for(i = 0;i < 20;++i)
      printf("%d, %d\n",(*p)+i,*(p+i));
  return 0;


}
