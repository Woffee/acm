#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main(){
    int t,n,ans;
    cin>>t;
    while(t--){

        cin>>n;
        ans=n*(n-1)*3+2;
        printf("%d\n",ans);
    }
    return 0;
}

