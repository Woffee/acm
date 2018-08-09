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
const int maxn=1e5+5;

int num[10];
char s[maxn];

int numa[10];
int numb[10];
int a[maxn];
int b[maxn];

void add(int i,int j)
{

}

int main()
{
    //freopen("in.txt","r",stdin);
    memset(num,0,sizeof num);
    memset(numa,0,sizeof numa);
    memset(numb,0,sizeof numb);
    scanf("%s",s);
    int len=strlen(s);

    for(int i=0; i<len; ++i)
    {
        num[ s[i]-'0' ]++;
        numa[ s[i]-'0' ]++;
        numb[ s[i]-'0' ]++;
    }
    int index=0;
    /*
        //首先是0

        while(numa[0])
        {
            a[index]=0;
            b[index]=0;
            index++;
            numa[0]--;
            numb[0]--;
        }
    */
    int max9=-1,keyi,keyj;
    bool is10 =false;
    for(int i=1; i<=9; ++i)
    {
        for(int j=1; j<=9; ++j)
        {
            if( i+j>=10 && numa[i] && numb[j] )
            {
                numa[i]--;
                numb[j]--;
                is10=1;
                int num9 = 0;
                for(int ii=0; ii<=4; ++ii)
                {
                    if( numa[ii] && numb[9-ii] )
                    {
                        num9+= min(numa[ii],numb[9-ii]);
                        //printf("add == 9\n");
                    }
                }
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
    if(is10)
    {
        //printf("key==%d\n",key);
        a[index] = keyi;
        b[index] = keyj;
        index++;
        numa[keyi]--;
        numb[keyj]--;

        for(int ii=0; ii<=9; ++ii)
        {
            while( numa[ii] && numb[9-ii] )
            {
                a[index] = ii;
                b[index] = 9-ii;
                index++;
                numa[ii]--;
                numb[9-ii]--;
                //printf("add == 9\n");
            }
        }
    }

    //最后是不进位的
    for(int ii=0; ii<=9; ++ii)
    {
        for(int jj=0; jj<9; ++jj)
        {
            if( ii==0 && jj==0)continue;
            while( numa[ii] && numb[jj] )
            {
                a[index] = ii;
                b[index] = jj;
                index++;
                numa[ii]--;
                numb[jj]--;
                //printf("add == 9\n");
            }
        }
    }

    int ii=index-1;

    while(a[ii]==0 && b[ii]==0)
    {
        ii--;
    }


    for(int i=ii; i>=0; i--)
    {
        printf("%d",a[i]);
    }
    for(int i=ii+1; i<index; ++i)
    {
        printf("%d",a[i]);
    }
    while(numa[0])
    {
        printf("0");
        numa[0]--;
    }
    printf("\n");




    for(int i=ii; i>=0; i--)
    {
        printf("%d",b[i]);
    }
    for(int i=ii+1; i<index; ++i)
    {
        printf("%d",b[i]);
    }
    while(numb[0])
    {
        printf("0");
        numb[0]--;
    }
    printf("\n");

    return 0;
}
