#include<iostream>
using namespace std;
int main()
{
    int m,n;
    char a[30], b[30];
    cout<<"a:";
    cin>>a;
    cout<<"b:";
    cin>>b;
    for(int i=0;i<30;i++)
    {
        if (a[i]=='\0')
        {m=i;break;}
    }
    for(int i=0;i<30;i++)
    {
        if(b[i]=='\0')
        {n=i;break;}
    }
    for(int i=0;i<=n;i++)
    {
        if(b[i]!='\0')a[m++]=b[i];
        else a[m++]='\0';
    }
    cout<<"a+b:"<<a;
    return 0;
}
