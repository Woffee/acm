/*
Constructing Roads
2014.8.30
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

int map[101][101];
int parent[101];
bool lian[101][101]={0};
struct S
{
	int x;
	int y;
	int dis;
}s[10000];
int find(int x)
{
    if(x!=parent[x])
        parent[x]=find(parent[x]);
    return parent[x];
}
void union_set(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
    {
        parent[x]=y;
        //sum[y]+=sum[x];
    }
}

int cmp(const S &a,const S &b)  
{  
    return  a.dis < b.dis ? 1 : 0;  
}  
int main()
{
	int n;
	while(cin>>n){
		memset(lian,0,sizeof(lian));
		memset(map,0,sizeof(map));
		int road=0;
		for(int i=1;i<=n;i++){
			parent[i]=i;
			for(int j=1;j<=n;j++){
				cin>>map[i][j];
				if(i<j){
					s[road].dis=map[i][j];
					s[road].x=i;
					s[road].y=j;
					road++;
				}
			}
		}
		int used;
		cin>>used;
		int a,b;
		for(int i=1;i<=used;i++){
			cin>>a>>b;
			union_set(a,b);

		}

		sort(s,s+road,cmp);
		int sum=0;
		for(int i=0;i<road;i++){
			if(find(s[i].x)!=find(s[i].y)){
				union_set(s[i].x,s[i].y);
				sum+=s[i].dis;
			}
			
		}
		cout<<sum<<endl;
	}

}