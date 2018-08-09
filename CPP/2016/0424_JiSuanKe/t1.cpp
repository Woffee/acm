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

int t,n;


int main()
{
    //freopen("in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans = n;
        int pingzi  =n;
        int pinggai =n;
        while(pingzi>=3 || pinggai>=4)
        {
            if(pingzi>=3)
            {
                pingzi -= 2;
                ans++;
                pinggai++;
            }
            if(pinggai>=4)
            {
                pinggai-=3;
                ans++;
                pingzi++;
            }

        }
        cout<<ans<<endl;
    }

    //cout<<"test"<<endl;

    return 0;
}
