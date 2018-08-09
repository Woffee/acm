#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
const int MAXN=10000000;

int main(){
    freopen("in.txt","r",stdin);
    //int a;
    int t,n,ans;
    cin>>t;
    while(t--){

        ans=1;
        scanf("%d",&n);
        int i=2;
        for(;i*i<n;i++)
        {
            if(n%i==0)
            {
                ans+=i;
                ans+=(n/i);
            }
        }
        if(i*i==n)ans+=i;
        printf("%d\n",ans);
    }
    fclose(stdin);
    return 0;
}
