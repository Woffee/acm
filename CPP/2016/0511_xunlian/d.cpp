/*
Problem :
Status  :

1.�ڵ�i����ͼ�����ֱ�����궼û���ҵ���i��۸���˵ģ���ô���ϼ�����������һ��ȥ��
2.�ڵ�i����ͼ���������֮ǰ�ܹ��ҵ���i����˵ĵ㣬�����ǵ����յ㣬
��ôֻҪ���ͼӵ��ܵ�������㼴�ɣ�Ȼ��ֱ�ӵ�������㡣��󣬰�ÿ���������ͷѼ��������ɡ�


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
ll cap;

struct Route
{
    ll miles,consume,price;
};


bool cmp(Route a,Route b)
{
    return a.price < b.price;
}


Route routes[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        bool ok = true;

        scanf("%d %lld",&n,&cap);
        for(int i=0;i<n;++i)
        {
            scanf("%lld%lld%lld",&routes[i].miles,&routes[i].consume,&routes[i].price);

            if( routes[i].miles * routes[i].consume > cap )
            {
                ok=false;
            }
        }
        if(!ok)
        {
            printf("Impossible\n");
            continue;
        }

        ll ans = 0,gas = 0;
        int i=0,j=0;
        while(i<n)
        {
            j = i+1;

            //��ʱ������
            int tmp_gas = routes[i].miles * routes[i].consume;

            while( j<n && routes[j].price >= routes[i].price && cap-tmp_gas >= routes[j].consume*routes[j].miles )
            {
                tmp_gas+=routes[j].consume*routes[j].miles;
                j++;
            }
            if( j>=n || routes[j].price < routes[i].price )
            {
                if( gas > tmp_gas ) gas-=tmp_gas;
                else
                {
                    ans += routes[i].price * (tmp_gas-gas);
                    //printf("add:%d\n",routes[i].price * (tmp_gas-gas));
                    gas = 0;
                }
                i = j;
            }
            else
            {
                ans += (cap-gas)*routes[i].price;
                //printf("add:%d\n", (cap-gas)*routes[i].price );
                gas = cap - routes[i].consume * routes[i].miles;
                i++;
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}

