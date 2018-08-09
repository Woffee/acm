/*
Problem :
Status  :

题目大意：有一列扑克牌，每一张牌都有两面，每一面是一种颜色，有一种牌是王牌，可以当作任何颜色。

现在给你一个颜色序列，要求把翻动某些扑克牌，使得这个序列是扑克牌颜色序列的子序列。

解题报告：这题的序列长度是<=100的

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

char s[maxn],a[maxn],b[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&s);
        scanf("%s",&a);
        scanf("%s",&b);
        bool ok=false;
        int lens = strlen(s);
        int lena = strlen(a);
        int lenb = strlen(b);
        int i=0,j=0;
        while(i<lens)
        {
            while( j<lena &&  s[i]!=a[j] && s[i]!=b[j] && a[j]!='*' && b[j]!='*')
            {
                j++;
            }
            if(s[i] == a[j] || s[i] == b[j] || a[j]=='*' || b[j]=='*')
            {
                i++;
                j++;
            }
            if( i>=lens || j>=lena )break;
        }
        if(i==lens)
        {
            printf("win\n");
        }
        else
        {
            printf("lose\n");
        }
    }

    return 0;
}
