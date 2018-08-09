/*
以 hdu 1134:Game of Connections(求卡特兰数) 为例 :
*/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define FOR(i,s,t) for(int i = (s) ; i <= (t) ; ++i )

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1e6+5;

/*
* 高精度，支持四则运算和小于比较。
*/
struct BigInt
{
    const static int mod = 10000;
    const static int DLEN = 4;
    const static int MAXN=9999;
    int a[600],len;
    BigInt()
    {
        memset(a,0,sizeof(a));
        len = 1;
    }
    BigInt(int v)
    {
        memset(a,0,sizeof(a));
        len = 0;
        do
        {
            a[len++] = v%mod;
            v /= mod;
        }
        while(v);
    }
    BigInt(const char s[])
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
            for(int j = k; j <= i; j++)
                t = t*10 + s[j] - '0';
            a[index++] = t;
        }
    }
    BigInt operator +(const BigInt &b)const
    {
        BigInt res;
        res.len = max(len,b.len);
        for(int i = 0; i <= res.len; i++)
            res.a[i] = 0;
        for(int i = 0; i < res.len; i++)
        {
            res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
            res.a[i+1] += res.a[i]/mod;
            res.a[i] %= mod;
        }
        if(res.a[res.len] > 0)res.len++;
        return res;
    }
    BigInt operator -(const BigInt &b)const
    {
        int i,j,big;
        bool flag;
        BigInt t1,t2;
        if(b < *this)
        {
            t1=*this;
            t2=b;
            flag=0;
        }
        else
        {
            t1=b;
            t2=*this;
            flag=1;
        }


        big=t1.len;
        for(i=0; i<big; i++)
        {
            if(t1.a[i]<t2.a[i])
            {
                j=i+1;
                while(t1.a[j]==0)
                    j++;
                t1.a[j--]--;
                while(j>i)
                    t1.a[j--]+=MAXN;
                t1.a[i]+=MAXN+1-t2.a[i];
            }
            else t1.a[i]-=t2.a[i];
        }
        t1.len=big;
        while(t1.a[len-1]==0 && t1.len>1)
        {
            t1.len--;
            big--;
        }
        if(flag)
            t1.a[big-1]=0-t1.a[big-1];
        return t1;
    }


    BigInt operator *(const BigInt &b)const
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
            if(up != 0)
                res.a[i + b.len] = up;
        }
        res.len = len + b.len;
        while(res.a[res.len - 1] == 0 &&res.len > 1)res.len--;
        return res;
    }

    BigInt operator /(const int &b)const
    {
        BigInt res;
        int i,down=0;
        for(i=len-1; i>=0; --i)
        {
            res.a[i]=(a[i]+down*(MAXN+1) )/b;
            down=a[i]+down*(MAXN+1)-res.a[i]*b;
        }
        res.len=len;
        while(res.a[res.len-1]==0 && res.len>1)res.len--;
        return res;
    }

    bool operator <(const BigInt&b)const
    {
        int ln;
        if( len < b.len )return true;
        else if( len==b.len )
        {
            ln=len-1;
            while(a[ln]==b.a[ln] && ln>=0 )ln--;
            if(ln>=0 && a[ln] < b.a[ln] )return true;
            else return false;
        }
        else return false;
    }

    void output()
    {
        printf("%d",a[len-1]);
        for(int i = len-2; i >=0 ; i--)
            printf("%04d",a[i]);
        printf("\n");
    }
};


BigInt a[110];

int main()
{
    //freopen("in.txt","r",stdin);
    a[0]=BigInt(1);
    for(int i=1; i<=100; ++i)
    {
        a[i]=a[i-1]*( 4*i-2 )/(i+1);
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)break;
        a[n].output();
    }
    /*
    加减法:
    BigInt a=BigInt(123);
    BigInt b=BigInt(123);
    BigInt c=BigInt(456);
    BigInt d=BigInt(123);

    BigInt e=a-b;
    e.output(); // 0
    BigInt f=c-d;
    f.output(); // 333
    BigInt g=d-c;
    g.output(); // -333
    */
    return 0;
}