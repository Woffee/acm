// hdoj5058:So easy
// 水题，确实像题目一样
// AC date:2014.10.29
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105


using namespace std;

int a[MAXN],b[MAXN];
bool cmp(int a,int b){
    return a>b;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		bool ok=true;
		int t,j;
		for(int i=0;i<n;++i){
			scanf("%d",&t);
			for(j=0;j<i;j++)if(a[j]==t)break;
			if(j==i)a[i]=t;
		}
		for(int i=0;i<n;++i){
			scanf("%d",&t);
			for(j=0;j<i;j++)if(b[j]==t)break;
			if(j==i)b[i]=t;
		}
		

		sort(a,a+n,cmp);
		sort(b,b+n,cmp);

		for(int i=0;i<n;++i){
			if(a[i]!=b[i])
				ok=false;
		}
		if(ok)printf("YES\n");
		else printf("NO\n");
	}
}