/*
Problem :
Status  :AC

裸打kmp，一次AC，好爽。

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
const int maxn=1e7+5;

char str[maxn];
int kmp_next[maxn];
void kmp_pre(char * x)
{
    int m = 4;
    int i=0,j=-1;
    kmp_next[0]=-1;
    while(i<m)
    {
        while( -1!=j && x[i]!=x[j])j=kmp_next[j];
        kmp_next[++i]=++j;
    }
}
int kmp_count(char * word,int m,char *str,int n)
{
    int i=0,j=0,ret=0;
    while(i<n)
    {
        while( -1!=j && str[i]!=word[j])j=kmp_next[j];
        ++i;++j;
        if(j>=m)
        {
            ret++;
            j = kmp_next[j];
        }
    }
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    kmp_pre("doge");
    int ans = 0;
    while( scanf("%s",&str)!=EOF )
    {
        int len = strlen(str);
        for(int i=0;i<len;++i)
        {
            if( isalpha(str[i]) )
            {
                str[i] = tolower(str[i]);
            }
        }
        ans += kmp_count("doge",4,str, len) ;
    }
    printf("%d\n",ans);
    return 0;
}
