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

/*  * 高精度，支持乘法和加法  */
struct BigInt
{
    const static int mod = 10000;
    const static int DLEN = 4;
    int a[600],len;


    BigInt()
    {
        memset(a,0,sizeof(a));
        len = 1;
    }  BigInt(int v)
    {
        memset(a,0,sizeof(a));
        len = 0;
        do
        {
            a[len++] = v%mod;
            v /= mod;
        }
        while(v);
    }  BigInt(const char s[])
    {
        memset(a,0,sizeof(a));
        int L = strlen(s);
        len = L/DLEN;
        if(L%DLEN)len++;
        int index = 0;
        for(int i = L-1; i >= 0; i -= DLEN)
        {
            int t = 0;
            int k = i - DLEN + 1;
            if(k < 0)k = 0;
            for(int j = k; j <= i; j++)     t = t*10 + s[j] - '0';
            a[index++] = t;
        }
    }  BigInt operator +(const BigInt &b)const
    {
        BigInt res;
        res.len = max(len,b.len);
        for(int i = 0; i <= res.len; i++)    res.a[i] = 0;
        for(int i = 0; i < res.len; i++)
        {
            res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
            res.a[i+1] += res.a[i]/mod;
            res.a[i] %= mod;
        }
        if(res.a[res.len] > 0)res.len++;
        return res;
    }  BigInt operator *(const BigInt &b)const
    {
        BigInt res;
        for(int i = 0; i < len; i++)
        {
            int up = 0;
            for(int j = 0; j < b.len; j++)
            {
                int temp = a[i]*b.a[j] + res.a[i+j] + up;
                res.a[i+j] = temp%mod;
                up = temp/mod;


            }
            if(up != 0)     res.a[i + b.len] = up;
        }
        res.len = len + b.len;
        while(res.a[res.len - 1] == 0 &&res.len > 1)res.len--;
        return res;
    }  void output()
    {
        printf("%d",a[len-1]);
        for(int i = len-2; i >=0 ; i--)    printf("%04d",a[i]);
        printf("\n");
    }
} a[205];

int main()
{
    //freopen("in_b.txt","r",stdin);
    a[1]=1;
    a[2]=2;
    for(int i=3; i<205; ++i)
    {
        a[i]=a[i-1]+a[i-2];
    }
    //cout<<a[200]<<endl;
    int n;
    while( scanf("%d",&n)!=EOF )
    {
        a[n].output();
    }

    return 0;
}

