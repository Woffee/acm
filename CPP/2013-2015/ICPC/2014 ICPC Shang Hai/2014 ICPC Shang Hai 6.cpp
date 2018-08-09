#include <algorithm>   
#include <iostream>
#include <iomanip>     
#include <fstream>     
#include <cstring>
#include <string>
#include <cstdio>
#include <time.h>
#include <cmath>
#include <stack>
#include <map>  
    
using namespace std; 

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long sum=2;
		long long a;
		cin>>a;
		a*=4;
		for(long long j=1;j<=a;j++){
			sum+=j;
		}
		sum/=2;
		cout<<sum<<endl;
	}
	//printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );
}