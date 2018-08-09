/*
第一题GCD，欧拉函数；第二题50 years, 50 colors，
二分图最大匹配，这是个意外，小伙伴们选做；
第三题放大的X，输出控制，注意每行的最后一个X后边不再输出空格；
第四题Climbing Worm，过程模拟；
第五题小明系列故事——买年货，多维背包。
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

int main()
{
	int t;
	int n;
	cin>>t;
	while(t--){
		
		cin>>n;
		int s=1;
		int e=n;
		bool mid=false;
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				if(i==s || i==e)
					cout<<"X";
				else if(i>s && i>e)
					break;
				else 
					cout<<" ";
				
			}
			cout<<endl;
			s++;
			e--;
		}
		cout<<endl;
	}
}