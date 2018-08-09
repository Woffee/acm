/*
Problem :IP聚合
Status  :AC

当今世界，网络已经无处不在了，小度熊由于犯了错误，当上了度度公司的网络管理员，
他手上有大量的 IP列表，小度熊想知道在某个固定的子网掩码下，有多少个网络地址。
网络地址等于子网掩码与 IP 地址按位进行与运算后的结果，例如：

子网掩码：A.B.C.D

IP 地址：a.b.c.d

网络地址：(A&a).(B&b).(C&c).(D&d)

By wf,2016.05.09
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

struct IP
{
    int n1,n2,n3,n4;
};

int t,n,m;
IP ip[1005],yanma[55];

map<ll,int>mp;

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for(int tt = 1;tt<=t;++tt)
    {

        printf("Case #%d:\n",tt);
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;++i)
        {
            scanf("%d.%d.%d.%d",&ip[i].n1,&ip[i].n2,&ip[i].n3,&ip[i].n4);
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d.%d.%d.%d",&yanma[i].n1,&yanma[i].n2,&yanma[i].n3,&yanma[i].n4);
            mp.clear();
            for(int j=0;j<n;++j)
            {
                ll ip_num =
                        (ip[j].n1 & yanma[i].n1) *1000000000 +
                        (ip[j].n2 & yanma[i].n2) *1000000 +
                        (ip[j].n3 & yanma[i].n3) *1000 +
                        (ip[j].n4 & yanma[i].n4);
                mp[ip_num]++;

            }
            printf("%d\n",mp.size());
        }
    }

    return 0;
}


