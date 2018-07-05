/*又一个字符统计。输入一个字符串（长度小于200），统计每个大写字母的个数（个数为0的字母不用输出个数，每个字母一行）。例如：输入aB.+.2C:w   输出：B:1
C:1*/
#include <stdio.h>
#include <string.h>
int main()
{
	char a[100];
	int result[26];

	for (int i=0;i<26;i++){
		result[i]=0;
	}
	scanf("%s",a);
	int len=strlen(a);
	for (int j=0;j<len;j++){
		result[a[j]-'A']++;
	}
	for (int i=0;i<26;i++){
		if (result[i]>0)
		{
			printf("%c: ",'A'+i);
			printf("%d\n",result[i]);
		}
	}
	return 0;
}
