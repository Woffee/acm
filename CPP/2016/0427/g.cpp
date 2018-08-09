/*
Problem :
Status  :

poj3461 ，求一个模式串在字符串中的出现次数。

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

int f[ maxn];
char s[maxn];
char a[maxn];
int lens,lena;

void getfill()
{
    memset(f,0,sizeof(f));  //根据其前一个字母得到
    for(int i=1;i<lens;i++)
    {
        int j=f[i];
        while(j && s[i]!=s[j])
            j=f[j];
        f[i+1]=(s[i]==s[j])?j+1:0;
    }
}
int find()
{
    int ans=0;
    getfill();int j=0;
    for(int i=0;i<lena;i++)
    {
        while(j && a[i]!=s[j])
            j=f[j];
        if(a[i]==s[j])
            j++;
        if(j==lens){
            ans++;
        }
    }
    return ans;
}
int main()
{
    //string s,a;

    int T;
    scanf("%d",&T);
    while(T--)
    {
        //getchar();
        scanf("%s",&s);
        scanf("%s",&a);
        lens = strlen(s);
        lena = strlen(a);
        //cin>>s>>a;
        int ans=find();
        printf("%d\n",ans);
    }
    return 0;
}
