#include<stdio.h>
#include<string.h>
#define M 4 
#define N 3
int main() {
        int a[M][N] = {1,5,7,4,2,6,4,3,8,2,3,1};
        int p=0;
        for (int i=0;i<M;i++ ) {
                p=0;
                for ( int j=0;j<N;j++ )
                        if ( a[i][p]<a[i][j] )
                                p=j;
                printf("The max num of Line %d is %d\n",i+1, a[i][p]);
        }
}
