#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN=10000000;
char s[1005];
int main(){
    bool ding=false;

    while(cin>>s){
            int a=0,b=0,c=0,n1=0,n2=0,n3=0;
            int step=1;
            bool ans=false;
            bool flag1=false;
            bool flag2=false;
            for(int i=0;i<strlen(s);i++){
                if(s[i]=='z'){
                    n1++;
                    step=2;
                }
                if(s[i]=='j'){
                    n3++;
                    step=3;
                }

                if(s[i]=='o' && step==1){
                    a++;n2++;
                }
                if(s[i]=='o' && step==2){
                    b++;
                    n2++;
                }
                if(s[i]=='o' && step==3){
                    c++;n2++;
                }
            }

            if(n1==1 && b==1 && n3==1 && a==0 && c==0){
                ans=true; // 1
            }
            if(n1==1 && b==1 && n3==1 && a==c){ //2
                ans=true;
            }
	    //这是四科竞赛的题目，在下面的语句中，原是if(a*2==c...)，死活不AC
	    //改为a*b==c后，果断通过	
            if(a*b==c && b>=1 && n1==1 && n3==1){
                ans=true;
            }
            if(n1!=1 && n3!=1 &&n2==0)ans=false;

            if(ans)cout<<"Accepted"<<endl;
            else cout<<"Wrong Answer"<<endl;
    }
    return 0;
}
