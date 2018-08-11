/*
求 n 个字母'a'，和 m 个字母'a'组成的单词，按照字典序排序，第 k 个单词是什么？

输入n，m，k，输出第k个单词。

样例输入：
2 2 6

洋例输出：
zzaa

分析：
aazz, azaz, azza, zaaz, zaza, zzaa.
*/

#include "algorithm"
#include "iostream"
#include "cstring"
#include "cstdio"
#include "string"
#include "stack"
#include "cmath"
#include "queue"
#include "set"
#include "map"
#include "vector"

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1e6+5;

//right,down,left,up
int dir4[4][2]={0,1,1,0,0,-1,-1,0};
int dir8[8][2]={0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};


int dp[105][105];
bool isEnd = false;
void init()
{
	for(int i=0;i<105;++i) dp[i][0]=1;
	for(int i=0;i<105;++i) dp[0][i]=1;
	dp[0][0]=0;

	for(int i=1;i<105;i++){
		for(int j=1;j<105;j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
}


void solve(int n,int m,int k){
	if( n==0 && m==0) {
		isEnd = true;
	}
	if(isEnd || n<0 || n>100 || m<0 || m>100) return;

	if( n==0 ){
		cout<<"z";
		solve(n,m-1,k-1);
		return;
	}else if( m==0 ){
		cout<<"a";
		solve(n-1,m,k);
		return;
	}

	int aa = dp[n-1][m];
	int bb = dp[n][m-1];

	if( aa>=k ){
		cout<<"a";
		solve(n-1, m, k);
	}else{
		k-=aa;
		cout<<"z";
		solve(n,m-1,k);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	init();
	int n,m,k;
	while(cin>>n>>m>>k){
		
		if(dp[n][m]<k){
			cout<<"-1"<<endl;
		}else{
			isEnd = false;
			solve(n,m,k);
			cout<<endl;
		}
	}

	return 0;
}