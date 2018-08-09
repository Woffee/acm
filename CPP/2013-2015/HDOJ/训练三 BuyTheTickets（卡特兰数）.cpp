/*
Buy The Tickets 卡特兰数
又一个经典的卡特兰数的应用：50元的数量永远不小于100元的数量，m和n最大均为100，第200位卡特兰数是373位

f(m,n)=c(m+n,n)-c(m+n,m+1)  再乘以m!和n!,化简后为(m+n)!*(m-n+1)/(m+1)
*/
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
int a[201][501],b[501];

int main()
{
    int i,j,s,sort,m,n,u;

    memset(a,0,sizeof(a));
    a[0][0]=1;
    a[1][0]=1;
    int temp,k=0;

    for(i=2; i<201; i++)             //预处理阶乘
    {
        for(j=0,s=0; j<501; j++)
        {
            temp=i*a[i-1][j]+s;
            a[i][j]=temp%10;
            s=temp/10;
        }
    }

    sort=0;
    while(scanf("%d%d",&m,&n)!=EOF&&(m||n))
    {
        printf("Test #%d:\n",++sort);
        if(m<n)
        {
            printf("0\n");
            continue;
        }
        //cout<<"(m+n)!*(m-n+1)/(m+1) = ";
        //cout<<f(m,n)<<endl;

        i=m-n+1;
        memset(b,0,sizeof(b));
        for(j=0,s=0; j<501; j++)
        {
            temp=i*a[m+n][j]+s;
            b[j]=temp%10;
            s=temp/10;
        }
        k=500;

        while(k>=0&&b[k]==0) k--;
        for(j=k,s=0,u=0; j>=0; j--)
        {
            temp=s*10+b[j];
            if(u==0)
            {
                if(temp/(m+1)>0)                 //对于第1次输出要谨慎，防止先输出0
                {
                    u=1;
                    printf("%d",temp/(m+1));
                }
            }
            else printf("%d",temp/(m+1));
            s=temp%(m+1);
        }
        printf("\n");
    }
    return 0;
}
