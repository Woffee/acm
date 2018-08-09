/*HENU第二周练习题目1002
sort 
Time Limit : 6000/1000ms (Java/Other)   Memory Limit : 65536/32768K (Java/Other)
Total Submission(s) : 82   Accepted Submission(s) : 15
Font: Times New Roman | Verdana | Georgia 
Font Size: ← →
Problem Description
给你n个整数，请按从大到小的顺序输出其中前m大的数。

Input
每组测试数据有两行，第一行有两个数n,m(0<n,m<1000000)，第二行包含n个各不相同，且都处于区间[-500000,500000]的整数。

Output
对每组测试数据按从大到小的顺序输出前m大的数。

Sample Input
5 3
3 -35 92 213 -644

Sample Output
213 92 3

Hint
Hint
请用VC/VC++提交 
Author
LL 
Source
ACM暑期集训队练习赛（三） 
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int num[1000005];
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a; //a-b为升序
}

int main()
{
	freopen("input.txt","r",stdin);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);
		qsort(num,n, sizeof(num[0]),cmp);
		for(int i=0;i<m-1;++i)
			printf("%d ",num[i]);
		printf("%d\n",num[m-1]);
	}
	fclose(stdin);
	return 0;
}