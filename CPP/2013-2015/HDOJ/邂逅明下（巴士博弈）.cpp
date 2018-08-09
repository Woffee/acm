/*
邂逅明下    巴士博弈
http://acm.hdu.edu.cn/showproblem.php?pid=2897
题意：给出硬币的个数，每人轮流取，最少取p个，最多取q个，最后取的人就输了

这道题据说是博弈，但是本屌丝根本就还没看博弈，不知道是神马东东，于是就同规律来做

解法：最主要是判断最后剩下的硬币的个数就是了，由于是问是否有必胜的策略，所以当轮到A是剩下的硬币0<=K<=p则A胜

否则B胜利

得出方程如下

N = (p+q)*r+k

A胜：假设第一次A取T个，则以后每次B取X个，A就取(p+q-x)个，剩下的只要q<K<=p，那A必胜

B胜：取法是假设A每次取x,则B就每次取(p+q-x)个，剩下的只要0<K<=p，则B必胜

2014.9.1
*/
 
#include <algorithm>   //sort()
#include <iostream>
#include <iomanip>     //
#include <fstream>     //
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <time.h>      //
using namespace std; 

int main()
{
    int n,p,q;
    while(~scanf("%d%d%d",&n,&p,&q))
    {
        n = n%(p+q);
        if(n>0 && n<=p)
        printf("LOST\n");
        else
        printf("WIN\n");
    }

    return 0;
}
