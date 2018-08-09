#include<iostream>
using namespace std;
int main()
{
    const int num=10;
    int interval;
    int a[num];

    for(int i=0; i<num; i++)
        a[i]=i+1;
    cout<<"Interval:";
    cin>>interval;
    int k=1;
    int i=-1;
    while(1)
    {
        for(int j=0; j<interval;)
        {
            i=(i+1)%num;
            if(a[i]!=0)j++;
        }
        if(k==num)break;
        a[i]=0;
        k++;
    }
    cout<<"\nWinner:"<<a[i];
}


