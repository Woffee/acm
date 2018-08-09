#include <string>
#include<iostream>
#include<fstream>
using namespace std;

string sum(string a,string b)
{
    int dot_a=0,dot_b=0;
    for(int i=0; i<a.length(); ++i)
    {
        if(a[i]=='.')
        {
            dot_a=a.length()-i-1;
            break;
        }
    }
    for(int i=0; i<b.length(); ++i)
    {
        if(b[i]=='.')
        {
            dot_b=b.length()-i-1;
            break;
        }
    }
    if(dot_a||dot_b)
    {
        if(dot_a==0)a=a+'.';
        if(dot_b==0)b=b+'.';
        if(dot_a>dot_b)
            b=b+string(dot_a-dot_b,'0');
        if(dot_a<dot_b)
            a=a+string(dot_b-dot_a,'0');
    }
    if(a.length()>b.length())
        b=string(a.length()-b.length(),'0')+b;
    else
        a=string(b.length()-a.length(),'0')+a;
    int t=0;
    for(int i=a.length()-1; i>=0; --i)
    {
        if(a[i]=='.')continue;
        t+=a[i]-'0'+b[i]-'0';
        a[i]=t%10+'0';
        t/=10;
    }
    for(int i=a.length()-1; i>=0; --i)
    {
        if(a[i]=='0')
        {
            a[i]=NULL;
            if(a[i-1]=='.')
            {
                a[i-1]=NULL;
                break;
            }
        }
        else break;
    }
    return (t?'1'+a:a);

}
int main()
{
    freopen("input.txt","r",stdin);
    string a,b;
    while(cin>>a>>b)
    {
        cout<<sum(a,b)<<endl;
    }
    fclose(stdin);
    return 0;
}
