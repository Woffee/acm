#include<iostream>
void max(double a,double b);
void max(int a,int b);
void max(char a,char b);
using namespace std;
int main()
{
    max(3,5);         cout<<endl;
    max(3.5,5.5);   cout<<endl;
    max('A','B');     cout<<endl;
    return 0;

}
void max(double a,double b)
{
    if(a>b)cout<<a<<" "<<b<<"\nmax:  "<<a<<endl;
    else cout<<a<<" "<<b<<"\nmax:  "<<b<<endl;
}
void max(int a,int b)
{
    if(a>b)cout<<a<<" "<<b<<"\nmax:  "<<a<<endl;
    else cout<<a<<" "<<b<<"\nmax:  "<<b<<endl;
}
void max(char a,char b)
{
    if(a>b)cout<<a<<" "<<b<<"\nmax:  "<<a<<endl;
    else cout<<a<<" "<<b<<"\nmax:  "<<b<<endl;
}
