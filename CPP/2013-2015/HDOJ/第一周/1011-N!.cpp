/*
ID: jinyu121
PROG:
LANG: C++
EDIT: 1.0
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <iomanip>

#define ten 10000               //标明：万进制。不用万进制压缩的话要加大数组，时间增长。

using namespace std;
int a[10000],b[10000];          //10000的阶乘也就36000多位，用万进制压缩的话1W的数组能存下
int maxmax,n;
void doit(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    a[1]=1;
    maxmax=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=maxmax;j++){
            b[j]=b[j]+a[j]*i;
            int k=j;
            for (;b[k]>=ten;){      //处理乘法中“进位”的问题
                b[k+1]+=b[k]/ten;
                b[k]%=ten;
                k++;
            }
            if (k>maxmax)
                maxmax=k;
        }
        memcpy(a,b,sizeof(b));
        memset(b,0,sizeof(b));
    }
    cout<<a[maxmax];            //首先输出第一位
    for (int i=maxmax-1;i>=1;i--)
        cout<<setiosflags(ios::right)<<setw(4)<<setfill('0')<<a[i];//之后的每一位都要“补0”
    cout<<endl;
}

int main(){

    for (;cin>>n;)
        doit();

    return 0;
}
