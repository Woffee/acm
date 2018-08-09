/*
力釘点小。。。
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
	int n,u,d;
	int t;
	int s;
	while(cin>>n>>u>>d && n){
		t=0;
		s=0;
		while(1){
			s+=u;
			t++;
			if(s>=n)
				break;
			s-=d;
			t++;
		}
		cout<<t<<endl;

	}
}