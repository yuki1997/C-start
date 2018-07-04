#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
    int i;
    for(i = 2; i <= (int)sqrt(n); i ++)
        if(n%i == 0) return 0;
    return 1;
}
int main()
{
    int n;
    for(n = 100; n<200; n ++)
        if(isPrime(n)) printf("%d ", n);
 
    return 0;
}
