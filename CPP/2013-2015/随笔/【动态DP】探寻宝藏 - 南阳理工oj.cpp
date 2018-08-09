/*
title:探 寻 宝 藏 - 南阳理工oj
date :2015.1.23
双线dp - 即同时考虑两条不相交的线，使其线上的和最大
显然我们需要记录每一步时两个线同时往前走的位置(这样可以容易的控制其不相交).
状态：dp[k,(x1,y1),(x2,y2)] 在第k步，双线里一线在(x1,y1) 二线在(x2,y2) 的最大和

d[k][i][j]表示第k步,第一条线在i行,第二条线在j行时收集的宝藏 
由于每次仅走一步，所以第一条线坐标(i, k-i),第二条线坐标(j, k-j)

转移：dp[k,(x1,y1),(x2,y2)] = max(dp[k-1,(x1-1,y1),(x2-1,y2)],
                                  dp[k-1,(x1,y1-1),(x2-1,y2)],
                                  dp[k-1,(x1-1,y1),(x2,y2-1)],
                                  dp[k-1,(x1,y1-1),(x2,y2-1)]) + A[x1][y1] + A[x2][y2];
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[110][55][55], A[55][55];

int K, M, N;
bool ok(int s, int x1, int x2) {
    if (x1 == x2) return false;
    if (s-x1 < 1 || s-x1 > N || s-x2 < 1 || s-x2 > N)
        return false;
    return true;
}

int main() {    
    scanf("%d", &K);
    while (K--) {
        scanf("%d%d", &M, &N);
        for (int i = 1; i <= M; ++i)
            for (int j = 1; j <= N; ++j)
                scanf("%d", &A[i][j]);
        int S = M+N;
        dp[2][1][1] = A[1][1];
        for (int s = 3; s <= S; ++s)
            for (int x1 = 1; x1 <= M; ++x1)
                for (int x2 = 1; x2 <= M; ++x2) {
                    if (!ok(s, x1, x2)) continue;                    
                    int _max = max(dp[s-1][x1-1][x2-1], dp[s-1][x1-1][x2]);
                    int _max2 = max(dp[s-1][x1][x2-1], dp[s-1][x1][x2]);
                    dp[s][x1][x2] = max(_max, _max2)+A[x1][s-x1]+A[x2][s-x2];
                }
        int ret = max(dp[S-1][M-1][M], dp[S-1][M][M-1])+A[M][N];
        printf("%d\n", ret);
    }

    return 0;
}