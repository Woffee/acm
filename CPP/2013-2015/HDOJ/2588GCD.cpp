#include <iostream>
using namespace std;

int euler(int n)
{
    int res=n;
	int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res=res-res/i;
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        res=res-res/n;
    return res;
}

int main()
{
    int t;
	int ans;
    long n,m;
	
    cin>>t;
    while(t--)
    {
        ans=0;
		
        cin>>n>>m;
        
		for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(i>=m)
                    ans=ans+euler(n/i);
                if((n/i)!=i && (n/i)>=m)
                    ans=ans+euler(i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

//大意是先求出n的所有约数，再使用欧拉函数

/*
欧拉函数题，题目要求小于等于n且与n的最大公约数大于等于m的所有数的个数

欧拉函数只能求出小于等于n且与n互质的所有数的个数，但是无法求出最大公约数是否大于m

但是 我们可以这样想 设a为大于等于m的n的一个约数，那么euler(n/a)表示的就是所有小于a与a互质的数的个数，设任一个数为x，那么这些数再乘以a就有gcd(n,x*a) = a;

所以我们可以想到答案为所有n大于等于m的约数ai的euler(n/ai)之和

最后注意一下 m=1的时候答案就是n 直接加结果不对
*/

/*

注意：这些数是否会重复呢？答案是否定的

设a、b为两个不同的大于等于m的n的约数

假设存在重复 那么就有 a*x = b*y (x是小于等于n/a且与n/a互质的数，y是小于等于n/b且与n/b互质的数)

变形 得到 x*n/b = y*n/a 由于x和n/a互质 所以 x是y的约数（因为两边分解质因数的时候n/a不能分出x的约数 只能是y来分）

不妨设 y = kx（k>1）  则 n/b = k(n/a)

由于y和n/b互质 则kx和n/b互质 但是n/b有个k作为约数 所以他们有公约数k 这显然推出k = 1 于是产生a==b矛盾！

所以不会产生重复
*/


















