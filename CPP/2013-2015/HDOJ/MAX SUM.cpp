/*
Max Sum
http://acm.hdu.edu.cn/showproblem.php?pid=1003

给你一系列整数，找出最大连续元素和，输出它的值、起点与终点

原创
*/
#include <algorithm>   //sort()
#include <iostream>
#include <iomanip>     //
#include <fstream>     //
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <time.h>      //
using namespace std; 

int main()
{
	int t;
	cin>>t;
	for(int Case=1;Case<=t;Case++){
		int n;
		cin>>n;

		bool flag=false;
		int a,temp=-100000,temp_s;  //全是负数时用到的变量
		int max=-1,max_s,max_e;     //最大元素和，起点，终点（要输出的值）
		int s=1,e=1,sum=0;          //下标
		for(int i=1;i<=n;i++){
			cin>>a;
			sum+=a;

			//这是处理全是负数的情况
			if(a>0)flag=true;
			if(a>temp){
				temp=a;
				temp_s=i;
			}

			if(sum<0){
				s=i+1;
				sum=0;
			}
			else
				e=i;
			if(sum>max){
				max=sum;
				max_s=s;
				max_e=e;
			}
		}

		//如果全是负数
		if(!flag){ 
			max=temp;
			max_s=temp_s;
			max_e=temp_s;
		}

		if(Case!=1)cout<<endl;
		cout<<"Case "<<Case<<":"<<endl;
		cout<<max<<" "<<max_s<<" "<<max_e<<endl;
	}
}

