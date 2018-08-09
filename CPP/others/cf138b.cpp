/*
Problem :
Status  :

给你一个数字n，数字a和b由n的每个位上的数组成，

问你什么情况下：a+b的和中，末尾0最多。

输出这种情况下的a和b。

通过以下样例，基本就行了：
111
12345
2468
990100
198500
7722819


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

char s[maxn];
int numa[10];
int numb[10];
int a[maxn];
int b[maxn];


int main()
{
    //freopen("in.txt","r",stdin);
    //while( scanf("%s",&s)!=EOF )
    //{
     scanf("%s",&s);
        memset(numa,0,sizeof numa);
        memset(numb,0,sizeof numb);
        int index=0;
        int len = strlen(s);
        for(int i=0; i<len; ++i)
        {
            numa[ s[i]-'0' ]++;
            numb[ s[i]-'0' ]++;
        }

        //寻找相加为9的个数最多的情况
        int max9=-1,keyi,keyj;
        bool is10 =false;
        for(int i=1; i<=9; ++i)
        {
            for(int j=1; j<=9; ++j)
            {
                if( i+j==10 && numa[i] && numb[j] )
                {

                    numa[i]--;
                    numb[j]--;
                    is10=1;
                    int num9 = 0;
                    for(int ii=0; ii<=9; ++ii)
                    {
                        if( numa[ii] && numb[9-ii] )
                        {
                            num9+= min(numa[ii],numb[9-ii]);
                            //printf("%d %d \n");
                        }
                    }
                    //printf("i==%d,j==%d,num9==%d\n",i,j,num9);
                    if( num9 >max9 )
                    {
                        max9 = num9;
                        keyi = i;
                        keyj = j;
                    }
                    numa[i]++;
                    numb[j]++;
                }
            }
        }

        int u = numa[0]-min(numa[0],numb[9]);
        for(int i=0;i<u;++i)
        {
            a[index]=0;
            b[index]=0;
            index++;
            numa[0]--;
            numb[0]--;
        }

        bool perfect = false;
        if(is10)
        {
            //printf("max:%d ,%d %d\n",max9,keyi,keyj);
            a[index] = keyi;
            b[index] = keyj;
            index++;
            numa[keyi]--;
            numb[keyj]--;

            //寻找全部是9的
            for(int ii=0; ii<=9; ++ii)
            {
                int x = min(numa[ii],numb[9-ii]);
                for(int jj = 0;jj<x;++jj)
                {
                    a[index]=ii;
                    b[index]=9-ii;
                    index++;
                }
                numa[ii]-=x;
                numb[9-ii]-=x;
            }
        }

        int n=index;
        int m=index;
        for(int i=0;i<=9;++i)
        {
            for(int j=0;j<numa[i];++j)a[n++]=i;
            for(int j=0;j<numb[i];++j)b[m++]=i;
        }

        for(int i=n-1; i>=0; --i)
        {
            printf("%d",a[i]);
        }
        printf("\n");
        for(int i=m-1; i>=0; --i)
        {
            printf("%d",b[i]);
        }
        printf("\n");

    //}

    return 0;
}

