/*
Problem :
Status  :

方法二，考虑动态规划 F[i] 代表以第 i 个字符为结尾的平衡串个数，

预处理出每个与右括号匹配的左括号 j，

如果存在的话， 那么 f[i]=f[j]+1; 复杂度也是 O(n)。

By wf,
*/

#include "algorithm"
#include "iostream"
#include "cstring"
#include "cstdio"
#include "string"
#include "stack"
#include "cmath"
#include "queue"
#include "set"
#include "map"

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

typedef long long ll;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1e5+5;

int dp[maxn];
int st[maxn];
char s[maxn];
int main()
{
    freopen("in_a.txt","r",stdin);


    return 0;
}

