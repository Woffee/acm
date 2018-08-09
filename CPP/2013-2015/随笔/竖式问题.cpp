/*
给定一个几位数，例如2357，列出竖式，竖式中出现的数必须是“2357”其中的数字。
  775
X  33
-----
 2325
2325 
-----
25575
输出每种情况。
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
#include <time.h>      
using namespace std; 

int main()
{
	char s[10];
	char ans[50];
	int a;
	while(cin>>a){
		int count=0;
		sprintf(s,"%d",a);
		for(int i=111;i<=999;i++){
			for(int j=11;j<=99;j++){
				int x=i*(j%10);
				int y=i*(j/10);
				int z=i*j;
				sprintf(ans,"%d%d%d%d%d",i,j,x,y,z);
				bool ok=1;
				for(int k=0;k<strlen(ans);k++){
					if(strchr(s,ans[k])==NULL)
						ok=0;
				}
				if(ok){
					++count;
					printf("%5d\nX%4d\n-----\n%5d\n%4d \n-----\n%5d\n\n",i,j,x,y,z);
				}
				

			}
		}	
		printf("The number of solutions = %d\n",count);
	}
	printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );
}