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

char str[maxn],word[maxn];

int kmpnext[maxn];
void getNext(int* x,int m)
{
    int i=0,j=-1;
    x[0]=-1;
    while( i<m )
    {
        while( j!=-1 && x[i]!=x[j] )j=kmpnext[j];
        kmpnext[++i]=++j;
    }
}
int kmpCount(char * str,char*word)
{
    int n = strlen(str);
    int m = strlen(word);
    getNext(kmpnext,m);
    int i=0,j=0,ret=0;
    while(i<n)
    {
        while( j!=-1 && str[i]!=word[j] )j=kmpnext[j];
        ++i;
        ++j;
        if( j>=m )
        {
            ret++;
            j=kmpnext[j];
        }
    }
    return ret;

}

int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&str);
        scanf("%s",&word);
        int num = kmpCount(str,word);
        printf("%d\n",num);
    }

    return 0;
}
