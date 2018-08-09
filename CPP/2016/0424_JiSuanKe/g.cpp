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


int n,m;
string s1,s2,tmp;

int main()
{
    //freopen("in_g.txt","r",stdin);

//    int a = 'a'+0;
//    int A = 'A'+0;
//    printf("a==%d,A==%d\n",a,A);

    while( cin>>n>>m )
    {
        s1="";
        s2="";
        for(int i=0; i<n; ++i)
        {
            cin>>tmp;
            s1 = s1 + tmp;
        }
        cin>>s2;

        int len1 = s1.length();
        int len2 = s2.length();

        if(len1<len2)
        {
            cout<<"NO"<<endl;
            continue;
        }

        for(int i=0; i<len1; ++i)
        {
            s1[i]= s1[i]|32;
        }
        for(int i=0; i<len2; ++i)
        {
            s2[i]= s2[i]|32;
        }

        // different member versions of find in the same order as above:
        std::size_t found = s1.find(s2);
        if (found!=std::string::npos)
        {


            //std::cout << "first 'needle' found at: " << found << '\n';
            printf("YES\n");
        }
        else printf("NO\n");
    }


    return 0;
}

