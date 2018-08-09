/*
HDOJ-1709 The Balance(母函数) 

题意：
 给出一些砝码，可以放在天秤的两边，问有[1,sum]中有哪些重量是不可称出来的
题解:
母函数，这里比较特殊的一点是砝码可以放在天枰的左右两端，我们可以在c2[j+k]+=c1[j]
后加多一句c2[abs(j-k)]+=c[j]...即可,假设原来的砝码都放在右端，则可以把新加的砝码放在左端，得到新重量。
*/
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int c1[10005], c2[10005];

int main()
{
    int n, sum;
    int a[105];
    while(~scanf("%d", &n))
    {
        sum = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        memset(c1, 0, (sum+1)*sizeof(int));
        memset(c2, 0, (sum+1)*sizeof(int));
        c1[0] = c1[a[0]] = 1;
        int end = a[0];
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 0; j <= end; ++j)
            {
                for(int k = 0; k <= a[i-1] && j+k <= sum; k += a[i-1])
                {
                    c2[j+k] += c1[j];
                    c2[abs(j-k)] += c1[j];
                }
            }
            end += a[i-1];
            for(int j = 0; j <= end; ++j)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        int cnt = 0;
        for(int j = 0; j <= sum; ++j)
        {
            if(c1[j] == 0)
                c2[cnt++] = j;
        }
        if(cnt == 0)
            printf("0\n");
        else
        {
            printf("%d\n", cnt);
            for(int i = 0; i < cnt-1; ++i)
                printf("%d ", c2[i]);
            printf("%d\n", c2[cnt-1]);
        }
    }
    return 0;
}