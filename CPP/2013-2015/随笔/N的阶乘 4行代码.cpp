#include<stdio.h> //雨中飞燕之作
#define N 5 //要计算的N
long s[N]= {1},n=10000,t=2,a,b,m;
main()
{
    for(;a<=m||++t<=N&&(a=b=0,1);m==a++&&b&&m++)
        s[a]=(b+=s[a]*t)%n,b/=n;
    for(printf("%d",s[m]); m--;)printf("%04d",s[m]);
}
