/*
A/B
*/
#include <iostream>
using namespace std;
int main()
{
    __int64 n,b;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>b;
        for(int i=1;i<9973;i++)
        {
            if((i*b-n)%9973==0)cout<<i<<endl;
        }
    }
    return 0;
}
