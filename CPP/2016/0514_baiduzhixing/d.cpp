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

map<string,int>mp;
int main()
{
    //freopen("in_d.txt","r",stdin);
    int n;
    string str;
    cin>>n;
    while(n--)
    {
        cin>>str;
        sort(str.begin(),str.end() );
        cout<<mp[str]<<endl;

            mp[str]++;

    }

    return 0;
}

