/*
    Name: 异 形 卵
    Http:南阳理工
    AC? :yes
    Date:2015.1.23
*/
 
#include <iostream>
#include <cstdio>
using namespace std; 
int t,l,n,summ,ans;

const int INF=10000000;
const int MAXN=1001;
int a[MAXN];

int sum(int x){
    int su=0,s=l;
    while(s--){
        su+=a[x++];
    }
    return su;
}

int main()
{
    
    cin>>t;
    while(t--){
        summ=0;
        ans=-1;
        cin>>l>>n;
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        for(int i=0;i<=n-l;i++){
            int temp=sum(i);
            if(summ<temp){
                ans=i;
                summ=temp;
            }
        }
        if(ans>-1){
            cout<<ans+1<<endl;
        }
        else cout<<"0"<<endl;
        
    }
    return 0;
}
