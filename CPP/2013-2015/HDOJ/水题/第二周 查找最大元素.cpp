﻿/*
查找最大元素 

Problem Description
对于输入的每个字符串，查找其中的最大字母，在该字母后面插入字符串“(max)”。

Input
输入数据包括多个测试实例，每个实例由一行长度不超过100的字符串组成，字符串仅由大小写字母构成。

Output
对于每个测试实例输出一行字符串，输出的结果是插入字符串“(max)”后的结果，如果存在多个最大的字母，就在每一个最大字母后面都插入"(max)"。

Sample Input
abcdefgfedcba
xxxxx

Sample Output
abcdefg(max)fedcba
x(max)x(max)x(max)x(max)x(max)

Author
lcy 
Source
C语言程序设计练习（四） 
原创 一次性通过
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
char str[105];

int main()
{
	//freopen("input.txt","r",stdin);
	while(cin>>str)
	{
		char mymax='a';
		int len=strlen(str);

		for(int i=0;i<len;i++)
		{
			if(str[i]>=mymax)mymax=str[i];
		}
		for(int i=0;i<len;i++)
		{
			cout<<str[i];
			if(str[i]==mymax)cout<<"(max)";
		}
		cout<<endl;
	}

	//fclose(stdin);
	return 0;

}


