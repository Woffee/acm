#include<iostream>
using namespace std;
int main()
{
    int a=17,b=3,winner=0;//������a������b�ı����뿪��������winner
    for(int i=1;i<a;i++)
        winner=(winner+b)%(i+1);
    cout<<"Winner:"<<winner+1<<endl;
}
