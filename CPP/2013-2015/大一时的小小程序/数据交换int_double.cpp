//��д����ʵ�����ݽ������ֱ���ָ���������Ϊ����mySwap���βΣ���ͨ�����طֱ�ʵ��int��double�ͱ���ֵ�Ľ�����
#include <iostream>
using namespace std;

void mySwap(int* a,int* b);       //ָ��
void mySwap(double* a,double* b);

void mySwap(int& a,int &b);       //����
void mySwap(double& a,double& b);

int main()
{
   int a=1,b=2;
   double c=1.6,d=3.9;
   cout <<"Before swapping: a="<<a<<"\tb="<<b<<"\t"<<"c="<<c<<"\td="<<d<<endl;
   mySwap(a,b);                     //Ϊʲô���õ������ã�
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
