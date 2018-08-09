/*
Title :
Status:
By wf,2016.04.22

有一个明显的性质：如果子串(i,j)(i,j)包含了至少kk个不同的字符，
那么子串(i,k),(j < k < length)(i,k),(j<k<length)也包含了至少kk个不同字符。


因此对于每一个左边界，只要找到最小的满足条件的右边界，就能在O(1)O(1)时间内统计完所有以这个左边界开始的符合条件的子串。

寻找这个右边界，是经典的追赶法（尺取法,双指针法）问题。

维护两个指针（数组下标），轮流更新左右边界，同时累加答案即可。复杂度 O(length(S))O(length(S))。
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
    nth_element(iarray,iarray+6,iarray+len);         //排序第6个元素
        cout<<endl;
    for(i=0;i<len;i++)
       cout<<iarray[i]<<" ";
    cout<<"  第6-th个元素     "<<iarray[6]<<endl;
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

