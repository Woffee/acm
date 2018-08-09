#include <algorithm>   
#include <iostream>
#include <iomanip>     
#include <fstream>     
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <time.h>      
#include <map>
using namespace std; 
int a[50005];

int main()
{

	int n;

	while(cin>>n){

		map<int,int> mymap;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<=j;k++){
					mymap[a[k]]++;
					
				}
				int len=mymap.size();
				int len2=len*len;

				for(int l=i+1;l<=j;l++){
					a[l]=0;
				}
				
				a[i]= (len2<(j-i))?len2:(j-i);
				mymap.clear();
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;

	}
	printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );

}