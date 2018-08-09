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

int main()
{
    //freopen("in_4.txt","r",stdin);
    int n;
    double a,r;
    int t;
    cin>>t;
    for(int ii=1;ii<=t;++ii)
    {
        cout<<"Case #"<<ii<<":"<<endl;
        cin>>n>>a>>r;

        double l = a/(2.0* tan(3.1415926/n) );
        //cout<<l<<endl;
        if( l>=3*r || r<l )cout<<"Give me a kiss!"<<endl;
        else cout<<"I want to kiss you!"<<endl;
    }

    return 0;
}


