//给出一个整数n，求最小的m满足（n/m）为质数。

//显然N/M应该是N的最大质因子，这样才能使得M最小。暴力找到最大质因子后用N除就能算出M了。唯一无解的情况是N=1。


//引理：一个数n至多有一个不大于sqrt（n）的质因子，所以把n从2到sqrt（n）全部试除一次，
//剩下一个数如果不等于1，那么他就是最大的质因子
//如果为1的话，则试除过程中最后一个除数就是最大质因子


#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
    int n,i,j,k,t,Max;
    while(scanf("%d",&n)==1)
    {
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        k=sqrt(n); t=n;
        Max=1;
        for(i=2;i<=k;i++)
        {
            while(t%i==0)
            {
                t=t/i;
                Max=i;
            }
        }
        Max=max(Max,t);
        printf("%d\n",n/Max);
    }
    return 0;
}
