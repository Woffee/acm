#include <iostream>
using namespace std;

int main(){
    int n,i,j;
    string s;
    while(cin>>s>>n){
        j=0;
        for(i=0;i<s.length();i++){
            j=(j*10%n+(s[i]-'0')%n)%n;
        }
        cout<<j<<endl;
    }
}