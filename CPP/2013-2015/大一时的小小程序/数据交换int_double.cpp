//编写程序实现数据交换。分别用指针和引用作为函数mySwap的形参，并通过重载分别实现int、double型变量值的交换。
#include <iostream>
using namespace std;

void mySwap(int* a,int* b);       //指针
void mySwap(double* a,double* b);

void mySwap(int& a,int &b);       //引用
void mySwap(double& a,double& b);

int main()
{
   int a=1,b=2;
   double c=1.6,d=3.9;
   cout <<"Before swapping: a="<<a<<"\tb="<<b<<"\t"<<"c="<<c<<"\td="<<d<<endl;
   mySwap(a,b);                     //为什么调用的是引用？
   mySwap(c,d);

   cout <<"After swapping:  a="<<a<<"\tb="<<b<<"\t"<<"c="<<c<<"\td="<<d<<endl;
}


void mySwap(int* a,int* b)
{
   int temp=*a;
   *a=*b;
   *b=temp;
   cout<<"zhi zhen jiao huan\n";
}

void mySwap(double* a,double* b)
{
    double temp=*a;
    *a=*b;
    *b=temp;
    cout<<"zhi zhen jiao huan\n";
}


void mySwap(int& a,int &b)
{
  int temp=a;
   a=b;
   b=temp;
   cout<<"yin yong jiao huan\n";
}

void mySwap(double& a,double& b)
{
   double temp=a;
   a=b;
   b=temp;
   cout<<"yin yong jiao huan\n";
}
