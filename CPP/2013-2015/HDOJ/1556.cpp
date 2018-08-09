/*
    Name:
    Http:
    AC? :yes
    Date:2014.12.28
*/
 
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std; 

const int INF=10000000;
const int MAXN=100005;
int c[MAXN],n;

int lowbit(int x)
{
     return x&(-x);    
}

int Sum(int n)
{
    int sum=0;
    while(n>0)
    {
         sum+=c[n];
         n=n-lowbit(n);
    }    
    return sum;
}

void change(int i,int x)
{
     while(i<=n)
     {
          c[i]=c[i]+x;
          i=i+lowbit(i);
     }
}
int main()
{
    int a,b;
    while(cin>>n && n){
        memset(c,0,sizeof c);
        for(int i=1;i<=n;++i){
            cin>>a>>b;
            change(a,1);
            change(b+1,-1);
        }
        cout<<Sum(1);
        for(int i=2;i<=n;++i)
            cout<<" "<<Sum(i);
        cout<<endl;
    }

    return 0;
}