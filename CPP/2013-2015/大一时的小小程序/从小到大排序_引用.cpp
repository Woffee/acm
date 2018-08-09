#include <iostream>
using namespace std;

void paixu(int &x,int &y,int &z);

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    paixu(a,b,c);
}


void paixu(int &x,int &y,int &z)
{
    int temp;
    if(x>y)
    {
	temp=x;
	x=y;
	y=temp;
    }
    if(z<=x)cout<<z<<" < "<<x<<" < "<<y;
    else if(z<=y)cout<<x<<" < "<<z<<" < "<<y;
    else cout<<x<<" < "<<y<<" < "<<z;

}
