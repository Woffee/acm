/*
Problem :IP�ۺ�
Status  :AC

�������磬�����Ѿ��޴������ˣ�С�������ڷ��˴��󣬵����˶ȶȹ�˾���������Ա��
�������д����� IP�б�С������֪����ĳ���̶������������£��ж��ٸ������ַ��
�����ַ�������������� IP ��ַ��λ�����������Ľ�������磺

�������룺A.B.C.D

IP ��ַ��a.b.c.d

�����ַ��(A&a).(B&b).(C&c).(D&d)

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


