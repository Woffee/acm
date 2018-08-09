/* HENU第二周练习题目1001
Title:绝对值排序 
Time Limit : 2000/1000ms (Java/Other)   Memory Limit : 65536/32768K (Java/Other)
Total Submission(s) : 40   Accepted Submission(s) : 21
Font: Times New Roman | Verdana | Georgia 
Font Size: ← →
Problem Description
输入n(n<=100)个整数，按照绝对值从大到小排序后输出。题目保证对于每一个测试实例，所有的数的绝对值都不相等。 
Input
输入数据有多组，每组占一行，每行的第一个数字为n,接着是n个整数，n=0表示输入数据的结束，不做处理。 

Output
对于每个测试实例，输出排序后的结果，两个数之间用一个空格隔开。每个测试实例占一行。 
Sample Input
3 3 -4 2
4 0 1 2 -3
0
Sample Output
-4 3 2
-3 2 1 0

Author
lcy 
Source
C语言程序设计练习（三） 
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int cmp(const void *a,const void *b)
{
 if((*(int *)a)<0||(*(int *)b)<0) return abs(*(int *)b)-abs(*(int *)a);
 return *(int *)b-*(int *)a; 
}

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	while(cin>>n&&n)
	{
		int Num[105];
		int i=0;
		while(i<n)
		{
			cin>>Num[i];
			++i;
			
		}
		qsort(Num,n, sizeof(Num[0]),cmp);
		i=0;
		while(i<n)
		{
			if(i!=n-1)
				cout<<Num[i]<<" ";
			else
				cout<<Num[i]<<endl;
			++i;
		}
	}
	fclose(stdin);
	return 0;
}

