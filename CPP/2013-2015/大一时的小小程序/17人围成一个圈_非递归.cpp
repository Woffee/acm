#include<iostream>
using namespace std;
int main()
{
    const int num=17;
    int interval=3;
    int a[num];

    for(int i=0; i<num; i++)
        a[i]=i+1;
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
    cout<<"17人，数到3的倍数离开，胜利者："<<a[i];
}


