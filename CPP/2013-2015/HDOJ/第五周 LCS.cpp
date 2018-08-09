/*
LCS
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
	char y[]={"yABCBDAB"};
	char x[]={"xBDCABA"};

	int vis[10][10]={0};
	int C[10][10]={0};
	
	int i,j;
	int lx=sizeof(x)-1;
	int ly=sizeof(y)-1;

	for(i=1;i<lx;++i)
	{
		for(j=1;j<ly;++j)
		{
			if(x[i]==y[j])
			{
				vis[i][j]=1;
				C[i][j]=C[i-1][j-1]+1;
			}
			else 
				C[i][j]=max(C[i-1][j],C[i][j-1]);
		}
	}

	cout<<C[lx-1][ly-1]<<endl;
}