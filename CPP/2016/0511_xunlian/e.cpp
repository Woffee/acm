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

int t;
int n;

map<string,int>mp;
vector<string>v[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        mp.clear();


        for(int i=0;i<maxn;++i)v[i].clear();

        cin>>n;
        getchar();
        string str;
        for(int i=0; i<n; ++i)
        {
            getline(cin,str);
            //cout<<str<<endl;

            int len = str.length();
            for(int i=0; i<len;)
            {
                if( isalpha(str[i]) )
                {
                    str[i]=tolower(str[i]);
                    int j = i + 1;
                    while(j<len && isalpha(str[j]))
                    {
                        str[j]=tolower(str[j]);
                        j++;
                    }
                    string word = str.substr(i,j-i);
                    mp[word]++;
                    //cout<<word<<" "<<endl;
                    i=j;
                }
                else i++;
            }
        }
        map<string,int>::iterator it;
        for(it=mp.begin(); it!=mp.end(); ++it)
        {
            //cout<< it->first <<endl;

            if(it->second==1)continue;

            if( v[ it->second ].empty() )
            {
                 v[ it->second ].push_back( it->first );
            }
            else
            {
                int len1 = it->first.length();
                int len2 = v[ it->second ].front().length();
                if( len1 > len2 )
                {
                    v[ it->second ].clear();
                    v[ it->second ].push_back( it->first );
                }
                else if( len1==len2 )
                {
                    v[ it->second ].push_back( it->first );
                }
            }

        }
        bool first=1;
        for(int i=maxn-1;i>=2;--i)
        {
            if( v[i].empty() )continue;
            int num = v[i].size();
            if( num==1 )
            {
                if(first)first=0;
                else cout<<" ";

                cout<<v[i].front();
                //cout<<" "<<mp[  v[i].front()   ]<<endl;
            }
            else
            {
                sort(v[i].begin(),v[i].end());

                if(first)first=0;
                else cout<<" ";

                v[i].pop_back();
                cout<<v[i].back();

                //cout<<" "<<mp[ v[i].back()  ]<<endl;
            }

            //debug
            /*
            if( i==2 )
            {
                vector<string>::iterator it2;
                it2 = v[i].begin();
                while( it2!=v[i].end() )
                {
                    cout<<"2:"<< *it2 <<endl;
                    ++it2;
                }
            }
            */
        }
        cout<<endl;

    }

    return 0;
}


