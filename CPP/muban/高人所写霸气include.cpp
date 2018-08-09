// C
/*------------二分图染色+dfs-----------------*/
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define rep(i,j,k) for(int i=(int)j;i<(int)k;++i)
#define per(i,j,k) for(int i=(int)j;i>(int)k;--i)
#define lowbit(a) a&-a
#define Max(a,b) a>b?a:b
#define Min(a,b) a>b?b:a
#define mem(a,b) memset(a,b,sizeof(a))

typedef long long LL;
typedef unsigned long long LLU;
typedef double db;
const int N=1e5+100;
const int inf=0x3f3f3f3f;

char str[N];

int dir4[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
int dir8[8][2]= {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
int movv[5][2]= {{1,0},{0,1},{0,0},{-1,0},{0,-1}};

int head[N];
int vall[N],okk[10];
int idd;

inline LL read()
{
    int c=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        c=c*10+ch-'0';
        ch=getchar();
    }
    return c*f;
}
vector<int> G[N];
int vis[N];
int one,two;
int maxx,minn;

bool dfs(int u,int t)///当前结点，当前节点要染的颜色
{
    if(vis[u]){
        if(vis[u]==t) return true;
        return false;
    }
    if(t==1) one++;
    else two++;
    vis[u]=t;
    for(int i=0; i< G[u].size(); ++i){
        int v = G[u][i];
        if(!dfs(v,-t)) return false;
    }
    return true;
}
int main()
{
    int T,u,v,n,m;
    T=read();
    while(T--){
        n=read();
        m=read();
        for(int i=0; i<=n; ++i) G[i].clear();
        while(m--){
            u=read(),v=read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        if(n<2){
            puts("Poor wyh");
            continue;
        }
        
        mem(vis,0);
        bool flag=true;
        one=two=maxx=minn=0;
        for(int i=1; i<=n; ++i){
            if(!vis[i]){
                maxx+=max(one,two);
                minn+=min(one,two);
                one=two=0;
                if(!dfs(i,1))
                {
                    flag=false;
                    break;
                }
            }
        }
        maxx+=max(one,two);
        minn+=min(one,two);
        
        if(flag){
            if(minn==0) minn++,maxx--;
            printf("%d %d\n",maxx,minn);
        }
        
        else puts("Poor wyh");
    }
    return 0;
}


/*
Sample Input
2
8 5
3 4
5 6
1 2
5 8
3 5
5 4
2 3
4 5
3 4
2 4

Sample Output
5 3
Poor wyh

*/
