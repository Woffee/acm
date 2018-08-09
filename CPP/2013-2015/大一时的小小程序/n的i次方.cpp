#include<iostream>
double n(int i,int n=2);
using namespace std;
int main()
{
    double s=0;
    for(int i=1;i<=10;i++)
    {
        s+=n(i);
    }
    cout<<s;
    return 0;
}
double n(int i,int n)
{
    double s=1;
    for (int a=1;a<=i;a++) s*=n;
    return s;
}
