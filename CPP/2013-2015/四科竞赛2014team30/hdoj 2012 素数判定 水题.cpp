//需要g++编译才通过

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
using namespace std;
const int MAXN=3000;
bool prime[MAXN];

int main(){
    for(int i=0;i<MAXN;i+=2){
        prime[i]=false;
        prime[i+1]=true;
    }
    prime[2]=true;
    for(int i=3;i<=sqrt(MAXN);i+=2){
        if(prime[i])
            for(int j=i+i;j<MAXN;j+=i)
                prime[j]=false;
    }

    int x,y;
    while(cin>>x>>y ){
        int sum=0;
        if(x==0 && y==0)break;
        bool flag=true;
        for(int n=x;n<=y;n++){
            sum=n*n+n+41;
            if(prime[sum]==false){
                flag=false;
                break;
            }
        }
        if(flag)cout<<"OK"<<endl;
        else cout<<"Sorry"<<endl;
    }
    return 0;
}
