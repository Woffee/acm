/*
    Name:
    Http:
    AC? :
    Date:
*/
 
#include <iostream>
#include <cstdio>
using namespace std; 

int a[]={3,1,5,7,2,4,9,6};
int n=8;
void print(){
    for(int i=0;i<8;i++)cout<<a[i]<<" ";
    cout<<endl;
}
void sort(){
    int tmp,t;
    for(int d=n/2;d>=1;d=d/2){
        for(int  i=d;i<n;i++){
            tmp=a[i];
            int j;
            for(j=i-d;j>=0&&tmp<a[j];j-=d){
                t=a[j+d];
                a[j+d]=a[j];
                a[j]=t;
                print();
            }
            a[j+d]=tmp;
        }
    }
}

int main()
{
    sort();
    return 0;
}