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
		long long a,b;
		long long sum=0;
		cin>>a>>b;
		
			for(int j=a;j<=b;j++){
				sum+=j*j*j;
			}
		cout<<"Case #"<<i<<": "<<sum<<endl;

	}

	
	//printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );
}