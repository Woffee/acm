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
const int maxn=1e6+5;


char sub[10000+5];
char str[maxn];

//ÁõÈê¼Ñ
int f[10000+5];
void getFail(char* P,int * f)
{
    int m = strlen(P);
    f[0]=0;f[1]=0;
    for(int i=1;i<m;++i)
    {
        int j = f[i];
        while(j && P[i]!=P[j])j=f[j];
        f[i+1] = P[i]==P[j] ? j+1 :0;
    }
}

void kmp(char*T,char * P,int *f)
{
    int ret = 0;
    int n = strlen(T),m = strlen(P);
    getFail(P,f);
    int j=0;
    for(int i=0;i<n;++i)
    {
        while(j && P[j]!=T[i]) j = f[j];
        if(P[j]==T[i])j++;
        if(j==m)
        {
            ret++;
            //printf("%d\n",i-m+1);
        }

    }
    printf("%d\n",ret);
}

/*
kuangbin
void getFail(char P[],int f[])
{
    int m = strlen(P);
    int i=0,j=-1;
    f[0]=-1;
    while(i<m)
    {
       while(-1!=j && P[i]!=P[j])j=f[j];
       f[++i]=++j;
    }
    for(int i=0;i<m;++i)printf("%d ",f[i]);
    printf("\n");
}

void kmp(char T[],char P[],int f[])
{
    int ret = 0;
    int n = strlen(T),m = strlen(P);
    //printf("n==%d , m==%d\n",n,m);
    getFail(P,f);
    int i=0,j=0;
    while(i<n )
    {
        while(-1!=j && T[i]!=P[j])j=f[j];
        ++i;++j;
        if(j>=m)
        {
            ret++;
            j=f[j];
        }
    }
    printf("ret==%d\n",ret);
}
*/

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&sub);
        scanf("%s",&str);
        //printf("%s\n",sub);
        //printf("%s\n",str);
        kmp(str,sub,f);
    }

    return 0;
}

