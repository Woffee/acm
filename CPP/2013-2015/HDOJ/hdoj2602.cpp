/*
    Name:bone collector
    Http:
    AC? :YES
    Date:
*/
 
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std; 
int value[1005];
int volume[1005];
int f[1005];
int main()
{
    int t;
    cin>>t;
    while(t--){
        memset (f,0,sizeof f);
        int n,v;
        cin>>n>>v;
        for(int i=1;i<=n;++i){
            cin>>value[i];
        }
        for(int i=1;i<=n;++i){
            cin>>volume[i];
        }

        for(int i=1;i<=n;++i){
            for(int j=v;j>=0;j--){
                if(j>=volume[i])
                    if(f[j]<(f[j-volume[i]]+value[i]))
                        f[j]=f[j-volume[i]]+value[i];
            }
            for(int j=1;j<=10;j++)cout<<f[j]<<" "; 
            cout<<endl;
        }
        cout<<f[v]<<endl;
    }
    return 0;
}