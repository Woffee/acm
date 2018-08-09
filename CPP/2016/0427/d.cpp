/*
Problem :
Status  :

��Ŀ���⣺��һ���˿��ƣ�ÿһ���ƶ������棬ÿһ����һ����ɫ����һ���������ƣ����Ե����κ���ɫ��

���ڸ���һ����ɫ���У�Ҫ��ѷ���ĳЩ�˿��ƣ�ʹ������������˿�����ɫ���е������С�

���ⱨ�棺��������г�����<=100��

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
