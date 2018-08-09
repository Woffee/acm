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
	DATA:2014.10.18
*/

#include <cstdio>
#include <cstring>

int map[52][52];
bool vis[1<<16];
int state=0,move=0,player=0,n=0;

bool is_vis(int state){
	if(vis[state])return true;
	int state90=0,state180=0,state270=0;
	for(int i=0; i<n; ++i){  
        for(int j=n-1; j>=0; --j)
        	state90 = ((state90<<1)+map[i][j]) ;
    } 
    for(int i=n-1; i>=0; --i){  
        for(int j=n-1; j>=0; --j)
        	state180 = ((state180<<1)+map[i][j]) ;
    }
    for(int i=n-1; i>=0; --i){  
        for(int j=0; j<n; ++j)
        	state270 = ((state270<<1)+map[i][j]) ;
    }
    if(state==state90||state==state180||state==state270)return true;
	return false;
}
void f(int a,int b,char c,int i){
	if(move!=0)return ;
	int t1=1;
	int t2=(a-1)*n+b-1;
	for(int ii=0;ii<t2;ii++)
		t1=t1<<1;
	
	if(c=='+'){
		//map[a-1][b-1]=1;
		state = state|t1;
		
	}
	else {
		//map[a-1][b-1]=0;
		t1 = ~t1;
		state = state & t1;
	}

	if( is_vis(state) ){
		move=i+1;
		player=(i+1)&1;
	}
	else {
		vis[state]=true;
		if(c=='+')map[a-1][b-1]=1;
		else map[a-1][b-1]=0;
	}
	
}
int main()
{
	int a,b;
	char c;
	while(scanf("%d",&n) && n){

		move=0;player=0;state=0;
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));

		for(int i=0;i<2*n;++i){
			scanf("%d %d %c",&a,&b,&c);
				f(a,b,c,i);
		}

		if(move!=0)printf("Player %d wins on move %d\n",player+1,move);
		else printf("Draw\n");
	}
	return 0;
}