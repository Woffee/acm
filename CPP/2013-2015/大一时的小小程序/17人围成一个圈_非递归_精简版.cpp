#include<iostream>
using namespace std;
int main()
{
    int a=17,b=3,winner=0;//总人数a，数到b的倍数离开，最后的人winner
    for(int i=1;i<a;i++)
        winner=(winner+b)%(i+1);
    cout<<"Winner:"<<winner+1<<endl;
}
