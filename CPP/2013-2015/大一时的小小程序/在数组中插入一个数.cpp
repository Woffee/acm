#include<iostream>
using namespace std;
int s[10]={2,3,5,7,11,13,17,19,23,29};
void InsertSort(int a[],int m,int n);
void Print();
int main()
{
    int z;
    Print();
    cout<<"\n插入一个整数：";
    cin>>z;
    InsertSort(s,10,z);
    Print();

    return 0;
}
void InsertSort(int a[],int m,int n)
{
    for (int i=0;i<m;i++)
    {
        if(s[i]==n)return;
        if(s[i]<=n)continue;
        else
        for(int x=9;x>i;x--)
        {
            s[x]=s[x-1];
        }
        s[i]=n;
        return;
    }
}
void Print()
{
    for(int i=0;i<10;i++)
        cout<<s[i]<<" ";
    return;
}
