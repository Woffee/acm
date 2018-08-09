/*
VirtualFriends ²¢²é¼¯
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;
const int MAX=100005;
int parent[MAX],sum[MAX];
int number;
map<string,int>fri;

int find(int x)
{
    if(x!=parent[x])
        parent[x]=find(parent[x]);
    return parent[x];
}
void union_set(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
    {
        parent[x]=y;
        sum[y]+=sum[x];
    }
}

int main()
{
    int t,n;
    string a,b;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            number=0;
            fri.clear();
            scanf("%d",&n);
            while(n--)
            {
                cin>>a>>b;
                if(fri.find(a)==fri.end())
                {
                    number++;
                    fri[a]=number;
                    parent[number]=number;
                    sum[number]=1;

                }
                if(fri.find(b)==fri.end())
                {
                    number++;
                    fri[b]=number;
                    parent[number]=number;
                    sum[number]=1;
                }
                union_set(fri[a],fri[b]);
                int ans=find(fri[b]);
                printf("%d\n",sum[ans]);
            }
        }
    }
    return 0;
}
