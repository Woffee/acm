/*
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

freopen("in.txt","r",stdin);
fclose(stdin);
printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );
*/

/*
	  ID:
	http:
	DATA:
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	char a[25];
	char b[25];
	char ans[50];
	while(cin>>a){
		cin>>b;
		int index=0;
		int lena=strlen(a);
		int lenb=strlen(b);
		//cout<<len<<endl;
		for(int i=0;i<lena;++i){
			if(a[i]=='_'){
				for(int j=i+1;j<lena;j++)
					ans[index++]=a[j];
				break;
			}
		}
		ans[index++]='_';
		ans[index++]='s';
		ans[index++]='m';
		ans[index++]='a';
		ans[index++]='l';
		ans[index++]='l';
		ans[index++]='_';
		for(int i=0;i<lenb;++i){
			if(b[i]=='_'){
				for(int j=i+1;j<lena;j++)
					ans[index++]=b[j];
				break;
			}
		}
		for(int i=0;i<index;++i)
			cout<<ans[i];
		cout<<endl;
	}
}