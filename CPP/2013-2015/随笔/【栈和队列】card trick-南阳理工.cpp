/*
    Name: Card  Trick    
    Http:南阳理工   
    AC? :yes
    Date:2015.1.23
*/
 
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std; 

const int INF=10000000;
const int MAXN=100;

queue<int>q;
stack<int>s;
int main()
{
    int t,n,nn;
    cin>>t;
    while(t--){
        cin>>nn;
        int n=nn;
        while(n){
            q.push(n);
            int temp;
            for(int i=1;i<=n;i++){
                temp=q.front();
                q.push(temp);
                q.pop();
            }
            n--;
        }
        n=nn;
        while(n--){
            s.push(q.front());
            q.pop();
        }
        for(int i=1;i<nn && !s.empty();i++){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}