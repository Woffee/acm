/*
Title :
Status:
By wf,2016.04.22

��һ�����Ե����ʣ�����Ӵ�(i,j)(i,j)����������kk����ͬ���ַ���
��ô�Ӵ�(i,k),(j < k < length)(i,k),(j<k<length)Ҳ����������kk����ͬ�ַ���


��˶���ÿһ����߽磬ֻҪ�ҵ���С�������������ұ߽磬������O(1)O(1)ʱ����ͳ���������������߽翪ʼ�ķ����������Ӵ���

Ѱ������ұ߽磬�Ǿ����׷�Ϸ�����ȡ��,˫ָ�뷨�����⡣

ά������ָ�루�����±꣩�������������ұ߽磬ͬʱ�ۼӴ𰸼��ɡ����Ӷ� O(length(S))O(length(S))��
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
#define FOR(i,s,t) for(int i = (s) ; i "= (t) ; ++i )

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1e6+5;

int t;
int k;
char str[maxn];

bool vis[26];

int main()
{
/*
    int iarray[]={5,6,15,89,7,2,1,3,52,63,12,64,47};
    int len=sizeof(iarray)/sizeof(int);
    int i;
    for(i=0;i<len;i++)
       cout<<iarray[i]<<" ";
    nth_element(iarray,iarray+6,iarray+len);         //�����6��Ԫ��
        cout<<endl;
    for(i=0;i<len;i++)
       cout<<iarray[i]<<" ";
    cout<<"  ��6-th��Ԫ��     "<<iarray[6]<<endl;
*/


    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        //scanf("%d%d%d",&n,&m,&q);
        scanf("%s",&str);
        scanf("%d",&k);
        int len = strlen(str);
        int ans=0;

        for(int s=0;s<len;s++)
        {
            for(int t=s+k-1;t<len;++t)
            {
                memset(vis ,0,sizeof vis);
                bool ok=0;
                int num=0;
                for(int i=s;i<=t;++i)
                {
                    if( !vis[ str[i]-'a' ] )
                    {
                        vis[ str[i]-'a' ]=1;
                        num++;
                    }
                    if(num>=k)
                    {
                        ok=1;
                        break;
                    }
                }
                if( ok )
                {
                    int right = len-t;
                    ans+=right;
                    break;
                }
            }
        }
        //cout<<ans<<endl;
        printf("%d\n",ans);

    }
    return 0;
}

