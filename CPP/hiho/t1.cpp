#include <iostream>
#include <cstdio>
using namespace std;

int t,n,m;
int bian;
bool ok;
int f[505];

int Find(int x)
{
    int r = x;
    while( f[r]!=r )r=f[r];

    int i=x,j;
    while(i!=r)
    {
        j=f[i];
        f[i]=r;
        i=j;
    }
    return r;
}

void Join(int u,int v)
{
    if(u==v)
    {
        ok=false;
        return;
    }
    int fu = Find(u);
    int fv = Find(v);
    if(fu!=fv)
    {
        //printf("u==%d,v==%d,fu==%d,fv==%d\n",u,v,fu,fv);
        f[fu]=fv;
        bian ++ ;

    }else ok=false;
}


void print()
{
    for(int i=1;i<=n;++i)
    {
        printf("%d ",Find(i));
    }
    printf("\n");
}

int main()
{
    freopen("in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        bian = 0;
        ok=1;
        for(int i=1;i<=n;++i)f[i]=i;

        int u,v;
        for(int i=0;i<m;++i)
        {
            cin>>u>>v;
            Join(u,v);
        }


        int tmp = Find(1);
        for(int i=1;i<=n;++i)
        {
            if(Find(i)!=tmp)
            {
                ok=false;
                //printf("not \n");
                break;
            }
        }

        //print();

        if(ok )cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


}
