/*对于一个整数n，如果是偶数，就把n砍掉一半；如果是奇数，把n变成 3*n+ 1后砍掉一半，
直到该数变为1为止。请计算需要经过几步才能将n变到1，同时显示每一步变化的过程。（n=0时结束程序）*/
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n); 
	if(n != 0){
		while(n != 1)
		{
			if(n%2 != 0)
				n = (3*n+1)/2;
			else
				n = n/2;
			printf("%d ",n);
		}
	}
}

