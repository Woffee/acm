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

//dp[i][j]表示从i开始，长度为2^j的一段元素的最小值
int dp[maxn][20];
void RMQ_init(int A[],int n)
{
    //int n = A.size();
    for(int i=0;i<n;++i)dp[i][0]=A[i];
    for(int j=1; (1<<j)<=n ;++j )
    {
        for(int i=0; i+(1<<j)-1<n ;++i)
        {
            dp[i][j] = min(dp[i][j-1], dp[ i+( 1<< (j-1) )  ][j-1] );
        }
    }
}
int RMQ(int L,int R)
{
    int k = 0;
    while( 1<<(k+1) <= R-L+1 )k++;//如果2^(k+1)<=R-L+1，那么k还可以加1。
    return min( dp[L][k] , dp[ R-(1<<k)+1 ][k] );

}

int main()
{
    //freopen("in.txt","r",stdin);
    int a[]={5,4,6,7,8,6,3,5,6,8,7,9,2};
    RMQ_init(a,13);
    int ans = RMQ(2,10);
    cout<<ans<<endl;
    return 0;
}

