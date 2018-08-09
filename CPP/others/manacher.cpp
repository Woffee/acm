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
const int maxn=3e6+5;

// http://articles.leetcode.com/longest-palindromic-substring-part-ii

char Ma[maxn];
int Mp[maxn];
int Manacher(char *s,int len)
{
    int l=0;
    Ma[l++]='$';
    Ma[l++]='#';
    for(int i=0;i<len;++i)
    {
        Ma[l++]=s[i];
        Ma[l++]='#';
    }
    int C = 0, R = 0;
    for(int i=0;i<l;++i)
    {
        int i2 = 2*C - i;
        Mp[i] = i<R ? min( Mp[i2],R-i ) : 1;
        while( Ma[ i+Mp[i] ] == Ma[ i-Mp[i] ] ) Mp[i]++;
        if( R<i+Mp[i] )
        {
            R = i+Mp[i];
            C = i;
        }
    }
    int ret = -1;
    for(int i=0;i<l;++i)
    {
        //printf("%d ",Mp[i]);
        ret = max( ret,Mp[i]-1 );
    }
    //printf("\n");
    return ret;
}

char str[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    while( scanf("%s",&str)!=EOF )
    {
        //cout<<Manacher(str,strlen(str))<<endl;
        printf("%d\n",Manacher( str,strlen(str) ) );
    }
}
