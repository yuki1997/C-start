#include<stdio.h>  
int main()  
{  
    int x, y, z, m, n;  
    scanf("%d%d", &x, &y);  
    m = x, n = y;  
    while (y != 0)  
    {  
        z = x%y;  
        x = y;  
        y = z;  
    }  
    printf("最大公约数是: %d\n", x);  
    printf("最小公倍数是: %d\n", m*n / x);  
    return 0;  
}  
