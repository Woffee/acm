#include <string>
#include<iostream>
#include<fstream>
using namespace std;

string sum(string a,string b)
{
    if(a.length()>b.length())
        b=string(a.length()-b.length(),'0')+b;
    else
        a=string(b.length()-a.length(),'0')+a;
    int t=0;
    for(int i=a.length()-1;i>=0;--i)
    {
        t+=a[i]-'0'+b[i]-'0';
        a[i]=t%10+'0';
        t/=10;
    }
    return (t?'1'+a:a);

}
int main()
{

    string a,b;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        cout<<"Case "<<i<<":"<<endl;
        cout<<a<<" + "<<b<<" = "<<sum(a,b)<<endl;
        if(i<t)cout<<endl;
    }

    return 0;
}
