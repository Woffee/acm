/*
Problem :
Status  :

By wf,
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

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

typedef long long ll;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1e5+5;

int dp[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<maxn;++i)dp[i]=dp[i-1]+dp[i-2];
    int n,a;
    cin>>n;
    while(n--)
    {
        cin>>a;
        cout<<dp[a]<<endl;
    }
    return 0;
}

