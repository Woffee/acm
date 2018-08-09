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
using namespace std; 
int map[100001][100001];
bool m[100001];
int ans[100001];
int main()
{
	int n;

	while(cin>>n){
		for(int i=1;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			map[a][b]=map[b][a]=c;
		}
		for(int i=1;i<=n;i++){
			cin>>m[i];
		}

		for(int i=1;i<=n;i++){
			if(m[i]==false){
				m[i]=true;
			}
			
		}

	}


	//printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );

}