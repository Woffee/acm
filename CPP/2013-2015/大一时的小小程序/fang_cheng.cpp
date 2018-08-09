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
	if(a==0&&b!=0)cout<<"只有1个实根";
	else if(a==b==c==0)cout<<"无根";
	else if(d=0)cout<<"只有1个实根";
	else if(d>0)cout<<"有2个不同实跟";
	else if(d<0)cout<<"有2个不同复根";
	else cout<<"无根";
    
    return 0;
 }


  
  
  
 