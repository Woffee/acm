/*
EXCEL排序 

Excel可以对一组纪录按任意指定列排序。现请你编写程序实现类似功能。 
Input
测试输入包含若干测试用例。每个测试用例的第1行包含两个整数 N (<=100000) 和 C，其中 N 是纪录的条数，C 是指定排序的列号。以下有 N 
行，每行包含一条学生纪录。每条学生纪录由学号（6位数字，同组测试中没有重复的学号）、姓名（不超过8位且不包含空格的字符串）、成绩（闭区间[0, 100]内的整数）组成，每个项目间用1个空格隔开。当读到 N=0 时，全部输入结束，相应的结果不要输出。

Output
对每个测试用例，首先输出1行“Case i:”，其中 i 是测试用例的编号（从1开始）。随后在 N 行中输出按要求排序后的结果，即：当 C=1 时，按学号递增排序；当 C=2时，按姓名的非递减字典序排序；当 C=3 
时，按成绩的非递减排序。当若干学生具有相同姓名或者相同成绩时，则按他们的学号递增排序。

Sample Input
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
0 0

Sample Output
Case 1:
000001 Zoe 60
000007 James 85
000010 Amy 90
Case 2:
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Case 3:
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	


	
	fclose(stdin);
	return 0;
}