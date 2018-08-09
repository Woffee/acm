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
    //freopen("in_c.txt","r",stdin);

    int n;
    cin>>n;
    char cmd[20],str[5000];
    int len;
    string tmp;
    while(n--)
    {
        //cin>>cmd>>str;
        scanf("%s %s",&cmd,&str);
        switch( cmd[0] )
        {
        case 'i':
            len = strlen(str);
            tmp ="";

            for(int i=0;i<len;++i)
            {
                tmp+=str[i];
                mp[ tmp ]++;
                //cout<<"mp:"<<str.substr(0,i) <<"=="<<mp[ str.substr(0,i)  ]<<endl;
            }

            break;
        case 'd':
            tmp ="";
            for(int i=0;i<len;++i)
            {
                tmp+=str[i];
            }
            if( mp[tmp] ) mp[tmp]=0;
            break;
        case 's':
            len = strlen(str);
            bool ok=true;

            tmp ="";

            for(int i=0;i<len;++i)
            {
                tmp+=str[i];
                if(mp[ tmp  ]==0)
                {
                    ok=false;
                    break;
                }
            }


            //if(ok)cout<<"ok:"<<str<<" mp:"<<mp[str]<<endl;

            if(ok)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            break;
        }
    }

    return 0;
}

