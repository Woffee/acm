/*
饭卡
http://acm.hdu.edu.cn/showproblem.php?pid=2546

**********************************************************************
模版题：
这个模版来自 http://blog.csdn.net/libin56842/article/details/9396649
我改过之后果然适合这道题，真是不错
**********************************************************************
一个商品,卡上的剩余金额大于或等于5元，就一定可以购买成功（即使购买后卡上余额为负），否则无法购买（即使金额足够）。食堂中有n种菜出售，每种菜可购买一次。已知每种菜的价格以及卡上的余额，问最少可使卡上的余额为多少。
先用5元买最贵的，然后再用背包
Sample Input
1
50
5
10
1 2 3 2 1 1 2 3 2 1
50
0
Sample Output
-45
32
*/

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;

const int MAX=100000;
int dp[MAX];
int c[MAX],w[MAX];
int v;

void ZeroOnePack(int cost,int wei)//01
{
    int i;
    for(i = v;i>=cost;i--)
    {
        dp[i] = max(dp[i],dp[i-cost]+wei);
    }
}

void CompletePack(int cost,int wei)//完全
{
    int i;
    for(i = cost;i<=v;i++)
    {
        dp[i] = max(dp[i],dp[i-cost]+wei);
    }
}

void MultiplePack(int cost,int wei,int cnt)//多重
{
    if(v<=cnt*cost)//如果总容量比这个物品的容量要小，那么这个物品可以直到取完，相当于完全背包
    {
        CompletePack(cost,wei);
        return ;
    }
    else//否则就将多重背包转化为01背包
    {
        int k = 1;
        while(k<=cnt)
        {
            ZeroOnePack(k*cost,k*wei);
            cnt = cnt-k;
            k = 2*k;
        }
        ZeroOnePack(cnt*cost,cnt*wei);
    }
}


int cmp(int a,int b)  
{  
    return a<b;  
}
int main()
{
    int n,money;
    int i,j;
    while(cin>>n && n)
    {
        
        for(i = 1; i<=n; i++)
            scanf("%d",&c[i]);
        cin>>money;
        
         
        if(money<5)
        {
            cout<<money<<endl;
            continue;
        }

        sort(c+1,c+1+n,cmp);  
        int MAX=c[n]; 

        memset(dp,0,sizeof(dp));
        money-=5;
        v=money;
        for (i=1;i<n;i++)
        {
            ZeroOnePack(c[i],c[i]);
        }
        printf("%d\n",money-dp[money]+5-MAX); 
    }
    return 0;

}

//以下是我最开始时的写法
/*
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>  
using namespace std;

int cost[1005],dp[1005]; 


int cmp(int a,int b)  
{  
    return a<b;  
}
int main()
{
    int n,money;
    int i,j;
    while(cin>>n && n)
    {
    	
        for(i = 1; i<=n; i++)
            scanf("%d",&cost[i]);
        cin>>money;
        
         
        if(money<5)
        {
        	cout<<money<<endl;
        	continue;
        }

        sort(cost+1,cost+1+n,cmp);  
        int MAX=cost[n]; 

        memset(dp,0,sizeof(dp));
        money-=5;
        for (i=1;i<n;i++)
        {
    		for (j=money;j>=cost[i];j--)
        		dp[j]=max(dp[j],dp[j-cost[i]]+cost[i]);
        }
		printf("%d\n",money-dp[money]+5-MAX); 
    }
    return 0;
}*/