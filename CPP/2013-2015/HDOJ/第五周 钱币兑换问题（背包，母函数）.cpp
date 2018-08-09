/*
钱币兑换问题
http://acm.hdu.edu.cn/showproblem.php?pid=1284

在一个国家仅有1分，2分，3分硬币，
将钱N兑换成硬币有很多种兑法。
请你编程序计算出共有多少种兑法。

*/


//方法一：（完全背包  DP）


#include <stdio.h>
int dp[35000];
int main()
{
    int i,j;
    dp[0]=1;
    for(i=1; i<=3; i++)
        for(j=i; j<=35000; j++)
            dp[j]+=dp[j-i];
    int n;
    while(scanf("%d",&n)!=EOF)//用while(cin>>)出错
    {
        printf("%d\n",dp[n]);
    }
    return 0;
}




/*
方法2：
转：
思路：首先看能兑换多少个三分硬币的，然后当三分硬币分别为1，2，3，.... n时有多少个2分硬币的，为什么要这样确定了？因为只要还可以兑换出三分硬币和二分硬币的那么剩下的价值一定可以让价值为1的硬币塞满。开头为什么s为N/3+1呢？因为可以这样想，假设N=7，那么只包含3分硬币和1分硬币的组合方式为：3，3，1； 3，1，1，1，1；所以N/3是实际上可以容纳三分硬币的个数。而增加1是因为可以全部换成1分的硬币。有人会疑问，那么t = (N-3*i)/2不是会重复吗？这是不可能的，因为硬币的价值是递增的，只有当i的值为N/3时，t的值可以为0或者1。所以不会重复。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
        using namespace std;
int N;
int main()
{
    while(~scanf("%d", &N))
    {
        int s = N/3+1;
        for(int i = 0 ; i <= N/3 ; i++)
        {
            int t = (N-3*i)/2;
            s += t;
        }
        printf("%d\n", s);
    }
    return 0;
}

方法3：（母函数）
题目的意思就是说给你三种面值的币分别是1分、2分、3分，
那么问你一个钱数n有几种方案可以拼凑得到这个钱数n？

这道题还是比较好看的，我们根据母函数的定义，
以及多项式的每一项和系数所表示的含义，我们可以定义母函数
G(x)=(1+x+x^2+x^3-----)*(1+x^2+x^4+x^6+x^8-----)*(1+x^3+x^6+x^9------)，
那么我们使用母函数的额展开式对应的指数就是能表示的钱币数，
系数就是表示该钱币数的方案数。
所以问题就是求出对应的n的系数就可以了，这个比较简单，
就是模拟手工多项式的展开


#include <cstring>
#include <cstdlib>
#include <cstdio>
        using namespace std;
const int Max=32769;
int ans[Max];
int tans[Max];
int main()
{
    int i,j,n;
    for(int i=0; i<Max; i++)
        ans[i]=1;
    memset(tans,0,sizeof(tans));
    for(int k=2; k<=3; k++)
    {
        for(i=0; i<Max; i++)
        {
            for(j=0; i+j<Max; j+=k)
            {
                tans[i+j]+=ans[i];
            }
        }
        for(i=0; i<Max; i++)
        {
            ans[i]=tans[i];
            tans[i]=0;
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",ans[n]);
    }
    return 0;
}
*/