#include <iostream>
 using namespace std;
 int main()
 {
    cout<<" ax2+bx+c=0 \n";
	double a,b,c,d;
	cout<<"a=";
	cin>>a;
	cout<<"b=";
	cin>>b;
	cout<<"c=";
	cin>>c;
	d=b*b-4*a*c;
	if(a==0&&b!=0)cout<<"ֻ��1��ʵ��";
	else if(a==b==c==0)cout<<"�޸�";
	else if(d=0)cout<<"ֻ��1��ʵ��";
	else if(d>0)cout<<"��2����ͬʵ��";
	else if(d<0)cout<<"��2����ͬ����";
	else cout<<"�޸�";
    
    return 0;
 }


  
  
  
 