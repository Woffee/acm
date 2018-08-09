/*
最大连续子序列  动态规划

http://acm.hdu.edu.cn/showproblem.php?pid=1231

题意：给你一系列整数，选出所有 连续子序列 中 元素和最大 的一个子序列，
输出最大和、最大连续子序列的第一个和最后一个元素

思路见注释
*/


#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;
const int MAX=10005;

int a[MAX];

int main()
{
	int n;
	int flag,max,sum,start,end,temp;
	int i,j;
	while(cin>>n && n){
		 flag=0;
         for(i=0;i<n;i++)
         {
             scanf("%d",&a[i]);
             if(a[i]>=0)
                 flag=1;
         }
         max=0;
         if(flag==0)
         {
             printf("%d %d %d\n",max,a[0],a[n-1]);
             continue;
         }
         else
         {
         	sum=a[0];
         	max=a[0];
         	start=0;
         	end=0;
         	temp=0;  //临时起点
         	for(i=1;i<n;++i)
         	{
         		if(sum<0) { //如果前几项和小于0，就从新开始记录
         			sum=0;
         			temp=i; //刷新临时起点
         		}
         		sum+=a[i];        		
         		if(sum>max){ //如果现在的sum大于原来的max,刷新数据
         			max=sum;
         			start=temp;
         			end=i;
         		}
         	}
         	printf("%d %d %d\n",max,a[start],a[end]);
         }
	}
}