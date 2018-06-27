/*反序数。如果N的9倍恰好是其反序数（例如：12345的反序数是54321）。求100000以内所有符合条件的N。输入：无输入；输出：符合条件的N。*/
#include <stdio.h>
int reverse_int(int n )
{
    int r=0;
    while(n)
    {
        r=r*10+n%10;
        n/=10;
    }
    return r;
}
int main()
{
    int n;
    for(n=1;n<100000; n ++)
        if(n*9 == reverse_int(n)) printf("%d\n", n);
    return 0;
}
