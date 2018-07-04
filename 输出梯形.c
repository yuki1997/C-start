/*1.	[DAY 4]输出梯形。输入一个高度h，然后在屏幕上输出一个上底为h（用*号的个数表示），高度也为h（即h行）的梯形（向右侧对齐）。如输入：3，则输出梯形如下图：
    ***
  *****
*******
*/
#include <stdio.h>
int main(){
    int h;
    while(scanf("%d",&h)==1){
        int maxl=h+2*(h-1);
        for(int i=1;i<=h;i++){
            for(int j=1;j<=maxl;j++){
                if(j<=maxl-h-2*(i-1)) printf(" ");
                else printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
