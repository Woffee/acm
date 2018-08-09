#include<iostream>
using namespace std;
void bubble(int a[],int size)
{
    int i,temp;
    for(int pass=1;pass<size;pass++)
    {
        for(i=0;i<size-pass;i++)
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
    }
    for(i=0;i<size-1;i++)cout<<a[i]<<" < ";cout<<a[size-1]<<endl;
    cout<<endl;
}
int main()
{
    int shu[10];
    cout<<"Enter 10 numbers:\n";
    for(int i=0;i<10;i++)cin>>shu[i];
    bubble(shu,10);
    return 0;
}
