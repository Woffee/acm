
#include <algorithm>   //sort()
#include <iostream>
#include <iomanip>     //
#include <fstream>     //
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <time.h>      //
using namespace std; 
bool flag=true;


int main()
{

    int n,p,q;
    while(~scanf("%d",&n))
    {
        int t;
        flag=true;
        for(int i=1;i<=n;i++){
            cin>>t;
            t = t%(1+t);
            if(i%2!=0){
                if(t>1)
                    flag=false;
                
            }
            else {
                
                if(t>0 && t<=1)
                    flag=false;
                
            }
            
        }
        if(flag)cout<<"Win"<<endl;
        else cout<<"Lose"<<endl;
    }

    return 0;
}

//