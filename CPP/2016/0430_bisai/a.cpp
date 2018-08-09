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

string str;
int ans;
int a[200];

int main()
{
    //freopen("in.txt","r",stdin);


    cin>>str;
        ans = 0;
        int len = str.length();
        int index = 0;

        memset(a,0,sizeof a);

        a[index] ++;
        for(int i=1;i<len;i++)
        {
            if( str[i]==str[i-1] )
            {
                a[index]++;
            }
            else
            {
                index++;
                a[index]++;
            }
        }
        for(int i=0;i<=index;++i)
        {
            //cout<<a[i]<<" ";

            int tmp = a[i]/5;
            a[i] -= tmp*5;
            if(a[i])tmp++;
            //cout<<"+"<<tmp<<endl;
            ans+=tmp;
        }
        cout<<ans<<endl;


    return 0;
}

