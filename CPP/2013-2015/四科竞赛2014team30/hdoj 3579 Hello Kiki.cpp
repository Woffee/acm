//hdoj 3579 Hello kiki
//AC:2014.12.21

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define lint __int64
using namespace std;
int n;
lint m[100],c[100];

lint mod(lint x,lint y){
    lint res=x%y;
    if(res<=0)res+=y;
    return res;
}
lint exgcd(lint a, lint b, lint & x, lint & y)
{
    if(b==0)
    {   x=1; y=0;
        return a;
    }
    lint gcd=exgcd(b, a%b, x, y);
    lint t=x; x=y; y=t-a/b*y;
    return gcd;
}

lint doit(){
    bool check=true;
    lint ans=c[1],LCM=m[1],x,y,g;
    if(ans==0)ans=m[1];
    for(int i=2;i<=n;++i){
        g=exgcd(LCM,m[i],x,y);
        if((c[i]-ans)%g){
            check=false;
            return -1;
        }
        ans=mod(ans+LCM*mod((c[i]-ans)/g*x,m[i]/g),LCM/g*m[i]);
        LCM=LCM/g*m[i];
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>m[i];
        for(int i=1;i<=n;++i)cin>>c[i];
        cout<<"Case "<<ii<<": "<<doit()<<endl;
    }
}