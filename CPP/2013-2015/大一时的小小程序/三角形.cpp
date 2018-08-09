#include<iostream>
#include<math.h>
using namespace std;
int is(double a,double b,double c);
double area(double a,double b,double c);
int main()
{
    double a,b,c;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"c=";
    cin>>c;
    if(is(a,b,c)) area(a,b,c);
    else cout<<"无法构成三角形";
    return 0;
}
int is(double a,double b,double c)
{
    if(a+b>c && a+c>b && b+c>a)return 1;
    else return 0;
}
double area(double a,double b,double c)
{
    double s;
    s=(a+b+c)/2;
    cout<<"面积："<<sqrt(s*(s-a)*(s-b)*(s-c));
}
