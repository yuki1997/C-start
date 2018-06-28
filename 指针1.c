#include<stdio.h>
#include<string.h>
int main(void)
{
    /*int a = 10;
    int *p = &a;
    int **q = &p;
    printf("%p\n", p);
    printf("%p\n", q);
    printf("%p\n", *q);
    printf("%d\n",*(*q));
    return 0;*/
    /*const int a = 10;
    const int *p = &a;
    p++;
    printf("%d\n",a);
    return 0;*/
    const int a = 10;
    const int * const p = &a;
    
    printf("%d\n",a);
    return 0;
}
