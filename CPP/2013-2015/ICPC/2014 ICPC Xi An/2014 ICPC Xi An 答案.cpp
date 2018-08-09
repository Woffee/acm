1001


1002
//SA求不同子串个数
//输入一些字符串，用$分开，求出不同的子串个数
//call makesa();lcp();getsum();
//s=sbuff,n=strlen(s)+1;
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef __int64 LL;
#define min(x,y) ( (x)<(y)?(x):(y) )
#define max(x,y) ( (x)<(y)?(y):(x) )
const int N=111000;
char s[N]; // N > 256
int n, sa[N], height[N], _rank[N], tmp[N], top[N];
void makesa(){ // O(N * log N)
    int i, j, len, na;
    na = (n < 256 ? 256 : n);
    memset(top, 0, na * sizeof(int));
    for (i = 0; i < n ; i++) top[ _rank[i] = s[i] & 0xff ]++;
    for (i = 1; i < na; i++) top[i] += top[i - 1];
    for (i = 0; i < n ; i++) sa[ --top[ _rank[i] ] ] = i;
    for (len = 1; len < n; len <<= 1) {
        for (i = 0; i < n; i++) {
            j = sa[i] - len; if (j < 0) j += n;
            tmp[ top[ _rank[j] ]++ ] = j;
        }
        sa[ tmp[ top[0] = 0 ] ] = j = 0;
        for (i = 1; i < n; i++) {
            if (_rank[ tmp[i] ] != _rank[ tmp[i-1] ] ||
            _rank[ tmp[i]+len ]!=_rank[ tmp[i-1]+len ])
            top[++j] = i;
            sa[ tmp[i] ] = j;
        }
        memcpy(_rank, sa , n * sizeof(int));
        memcpy(sa , tmp, n * sizeof(int));
        if (j >= n - 1) break;
    }
}
void lcp(){ // O(4 * N)
int i, j, k;
for (j = _rank[height[i=k=0]=0]; i < n - 1; i++, k++)
    while (k >= 0 && s[i] != s[ sa[j-1] + k ])
        height[j] = (k--), j = _rank[ sa[j] + 1 ];
}
LL f[N];
int main()
{
    while( scanf("%s", s)!=EOF ){
        n = strlen(s)+1;
        int len = n-1;
        makesa();
        lcp();
        for (int i=0; i<n; i++){
            //cout<<height[ i ]<<endl;
        }
        for (int i=1; i<n; i++){
            f[i] = f[i-1] + (len-sa[i]) - height[i];
//            cout<< s+sa[i]  <<endl;
//            cout<<f[i]<<endl;
        }
        LL l=0, r=0;
        int Q;
        scanf("%d", &Q);
        while(Q--){
            LL v,k;
            scanf("%I64d", &v);
            k = (v^l^r) + 1;
            LL idx = lower_bound(f+1, f+n, k) - f;
            //cout<<idx<<endl;
            int tl = sa[idx], tr = len - ( f[idx]-k + 1 );
            l=tl, r=tr;
            int tlen = tr-tl+1;

//                cout<<"idx: "<<idx<<endl;
//                cout<<"height: "<<height[idx+1]<<endl;
//                cout<<"tlen: "<<tlen<<endl;
            while( idx+1<n && height[idx+1]>=tlen ){
                idx++;
                tl = sa[idx], tr = tl+tlen-1;
                l = min(l, tl), r=min(r, tr);
            }

            l++, r++;
            if ( idx>=n ){
                //cout<<"out"<<endl;
                l=r=0;
            }
            printf("%I64d %I64d\n", l, r);
        }
    }
    return 0;
}

1003
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

#define newnode ++wmt

const int maxn=50010;

int n,wmt,last[maxn],f[maxn],root[maxn],y[maxn],x[maxn],w[maxn],cnt[300][maxn],front[300],num[300];

bool cmp(int a,int b)
{
    return y[a]<y[b];
}

int main()
{
    while (~scanf("%d",&n))
    {
        y[0]=-1;
        for (int a=1;a<=n;a++)
        {
            scanf("%d",&y[a]);
            if (y[a]==y[a-1])
            {
                n--;
                a--;
            }
        }
        for (int a=1;a<=n;a++)
            x[a]=a;
        sort(x+1,x+n+1,cmp);
        int cx=0;
        for (int a=1;a<=n;a++)
            if (y[x[a]]==y[x[a-1]]) w[a]=cx;
            else w[a]=++cx;
        for (int a=1;a<=n;a++)
            y[x[a]]=w[a];
        int size=0;
        for (;size*size<=n;size++);
        if ((long long)cx*cx>n) size=10;
        for (int a=1;a<=size;a++)
        {
            front[a]=num[a]=0;
            for (int b=1;b<=cx;b++)
                cnt[a][b]=0;
        }
        for (int a=1;a<=n;a++)
        {
            f[a]=f[a-1]+1;
            for (int b=1;b<=size;b++)
            {
                cnt[b][y[a]]++;
                if (cnt[b][y[a]]==1)
                {
                    num[b]++;
                    if (num[b]>b)
                    {
                        for (;;)
                        {
                            cnt[b][y[front[b]++]]--;
                            if (cnt[b][y[front[b]-1]]==0) break;
                        }
                        num[b]--;
                    }
                }
                f[a]=min(f[a],f[front[b]-1]+b*b);
            }
        }
        printf("%d\n",f[n]);
    }

    return 0;
}

1004
//#pragma comment (linker,"/STACK:102400000,102400000")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cmath>
#include<complex>
#define pb push_back
#define mp make_pair
typedef long long big;
using namespace std;
const int L = 10, r = 6, c = 8;
const int HASHSIZE = 262143;
int id[L][L];
pair<int, int> place[L * L];
int places = 0, nutplace;
int n1, n2, n;
char graph[L][L];
struct node {
    int val;
    int d, nxt;
    int pre;
} q[3000000];
int head[HASHSIZE + 1];
int h, tail;
node S;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int getval(int a[]) {
    static int i;
    static int val;
    val = 0;
    for (i = 0; i < n; i++)
        val *= places, val += a[i];
    return val;
}
void clear() {
    memset(id, -1, sizeof(id));
    places = 0;
}
void add(const node &t) {
    static int i, key;
    key = t.val & HASHSIZE;
    for (i = head[key]; i; i = q[i].nxt) {
        if (q[i].val == t.val) {
            return;
        }
    }
    q[++tail] = t;
    q[tail].nxt = head[key];
    head[key] = tail;
}
void init() {
    int i, j;
    int tmp[20];
    place[places++] = mp(0, 0);
    id[0][0] = 0;
    for (i = 1; i <= r; i++)
        for (j = 1; j <= c; j++)
            if (graph[i][j] != 'N' && graph[i][j] != '#') {
                place[places] = mp(i, j);
                id[i][j] = places;
                places++;
            }
    S.val = 0;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++)
            if (graph[i][j] == 'S') {
                S.val *= places;
                S.val = id[i][j];
                graph[i][j] = '.';
            }
    }
    n1 = 0;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++)
            if (graph[i][j] == 'M') {
                tmp[n1++] = id[i][j];
                graph[i][j] = '.';
            }
    }
    sort(tmp, tmp + n1);
    for (i = 0; i < n1; i++)
        S.val = S.val * places + tmp[i];
    n2 = 0;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++)
            if (graph[i][j] == 'P') {
                tmp[n2++] = id[i][j];
                graph[i][j] = '.';
            }
    }
    sort(tmp, tmp + n2);
    for (i = 0; i < n2; i++)
        S.val = S.val * places + tmp[i];

    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++)
            if (graph[i][j] == 'N') {
                nutplace = id[i][j];
            }
    }

    n = n1 + n2 + 1;
}
bool canmove(int x, int y) {
    return x >= 1 && x <= r && y >= 1 && y <= c && graph[x][y] == '.';
}
void move(int type, int &x, int &y, int d) {
    static int k;
    while (canmove(x + dx[d], y + dy[d])) {
        x = x + dx[d];
        y = y + dy[d];
        if (type <= 1) {
            for (k = 0; k < 4; k++)
                if (graph[x + dx[k]][y + dy[k]] == 'P'
                        || graph[x + dx[k]][y + dy[k]] == 'N')
                    return;
        } else if (type == 2) {
            for (k = 0; k < 4; k++)
                if (graph[x + dx[k]][y + dy[k]] == 'S'
                        || graph[x + dx[k]][y + dy[k]] == 'M'
                        || graph[x + dx[k]][y + dy[k]] == 'N')
                    return;
        }
    }
}
void decode(const node &t, int a[]) {
    static int i;
    static int val;
    val = t.val;
    for (i = n - 1; i >= 0; i--)
        a[i] = val % places, val /= places;
}
inline int dist(int place1, int place2) {
    static int x, y;
    x = abs(place[place1].first - place[place2].first);
    y = abs(place[place1].second - place[place2].second);
    return x + y;
}
inline int getx(int place1) {
    return place[place1].first;
}
inline int gety(int place1) {
    return place[place1].second;
}
bool ckwin(const node &t) {
    static int a[L];
    decode(t, a);
    return a[0] && dist(a[0], nutplace) == 1;
}
void getgraph(int a[L]) {
    static int i;
    graph[getx(a[0])][gety(a[0])] = 'S';
    for (i = 1; i <= n1; i++)
        if (a[i])
            graph[getx(a[i])][gety(a[i])] = 'M';
    for (; i < n; i++)
        if (a[i])
            graph[getx(a[i])][gety(a[i])] = 'P';
}
void backgraph(int a[L]) {
    static int i;
    graph[getx(a[0])][gety(a[0])] = '.';
    for (i = 1; i <= n1; i++)
        if (a[i])
            graph[getx(a[i])][gety(a[i])] = '.';
    for (; i < n; i++)
        if (a[i])
            graph[getx(a[i])][gety(a[i])] = '.';
}
bool ckdie(int type, int x, int y) {
    if (type == 2)
        return false;
    static int k;
    for (k = 0; k < 4; k++)
        if (graph[x + dx[k]][y + dy[k]] == 'P')
            return true;
    return false;
}
bool ckeatnut(int x, int y) {
    static int k;
    for (k = 0; k < 4; k++)
        if (graph[x + dx[k]][y + dy[k]] == 'N')
            return true;
    return false;
}
void cpy(int b[], int a[]) {
    static int i;
    for (i = 0; i < n; i++)
        b[i] = a[i];
}
void normalize(int a[]) {
    sort(a + 1, a + 1 + n1);
    sort(a + 1 + n1, a + n);
}
void pri() {
    int i;
    for (i = 1; i <= r; i++)
        puts(graph[i] + 1);
    puts("");
}
int bfs() {
    int i, k, d, a[L], b[L], x, y, xx, yy, dis;
    h = 1;
    tail = 0;
    memset(head, 0, sizeof(head));
    S.d = 0;
    add(S);
    if (ckwin(S))
        return 0;
    node s, v;
    while (h <= tail) {
        s = q[h++];
        dis = s.d;
        decode(s, a);
        x = getx(a[0]);
        y = gety(a[0]);
        getgraph(a);

//        pri();

        for (d = 0; d < 4; d++) {
            cpy(b, a);
            xx = x;
            yy = y;
            move(0, xx, yy, d);
            if (ckdie(0, xx, yy))
                continue;
            else if (ckeatnut(xx, yy)) {
                backgraph(a);
                return dis + 1;
            }
            b[0] = id[xx][yy];
            v.val = getval(b);
            v.d = dis + 1;

            v.pre = h - 1;

            add(v);
        }

        for (i = 1; i <= n1; i++)
            if (a[i]) {
                x = getx(a[i]);
                y = gety(a[i]);
                for (d = 0; d < 4; d++) {
                    xx = x;
                    yy = y;
                    cpy(b, a);
                    move(1, xx, yy, d);
                    if (ckdie(1, xx, yy)) {
                        b[i] = 0;
                    } else if (ckeatnut(xx, yy))
                        continue;
                    else
                        b[i] = id[xx][yy];
                    normalize(b);
                    v.val = getval(b);
                    v.d = dis + 1;

                    v.pre = h - 1;

                    add(v);
                }
            }

        for (i = n1 + 1; i < n; i++) {
            x = getx(a[i]);
            y = gety(a[i]);
            for (d = 0; d < 4; d++) {
                cpy(b, a);
                xx = x;
                yy = y;
                move(2, xx, yy, d);
                if (ckeatnut(xx, yy))
                    continue;
                if (dist(b[0], id[xx][yy]) == 1)
                    continue;
                for (k = 1; k <= n1; k++)
                    if (dist(b[k], id[xx][yy]) == 1)
                        b[k] = 0;
                b[i] = id[xx][yy];
                normalize(b);
                v.val = getval(b);
                v.d = dis + 1;

                v.pre = h - 1;

                add(v);
            }
        }
        backgraph(a);
    }

    return 0x3f3f3f3f;
}
void Print() {
    int i;
    int a[L];
    int stack[200], top = 0;
    for (i = h - 1; i; i = q[i].pre) {
        stack[++top] = i;
    }
    reverse(stack + 1, stack + 1 + top);
    for (i = 1; i <= top; i++) {
        decode(q[stack[i]], a);
        getgraph(a);
        pri();
        backgraph(a);
    }
}
int main() {
    int i, j, k, x, y;
    while (~scanf("%s", graph[1] + 1)) {
        for (i = 2; i <= r; i++)
            scanf("%s", graph[i] + 1);
        clear();
        init();
        printf("%d\n", bfs());
//        Print();
    }
}

1005
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(void)
{

    int n,i,temp,ans;

    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            ans=ans^temp;
        }
        printf("%s\n",ans?"Win":"Lose");
    }

    return 0;
}

1006
    #include <stdio.h>
    #include <string.h>
    int r[25][7]={
    {    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    },
    {    0    ,    1    ,    2    ,    3    ,    4    ,    5    ,    6    },
    {    1    ,    2    ,    6    ,    3    ,    1    ,    5    ,    4    },
    {    1    ,    3    ,    2    ,    6    ,    4    ,    1    ,    5    },
    {    1    ,    4    ,    1    ,    3    ,    6    ,    5    ,    2    },
    {    1    ,    5    ,    2    ,    1    ,    4    ,    6    ,    3    },
    {    2    ,    2    ,    3    ,    1    ,    5    ,    6    ,    4    },
    {    2    ,    2    ,    5    ,    6    ,    3    ,    1    ,    4    },
    {    2    ,    3    ,    1    ,    2    ,    6    ,    4    ,    5    },
    {    2    ,    3    ,    6    ,    4    ,    1    ,    2    ,    5    },
    {    2    ,    4    ,    5    ,    1    ,    3    ,    6    ,    2    },
    {    2    ,    4    ,    3    ,    6    ,    5    ,    1    ,    2    },
    {    2    ,    5    ,    1    ,    4    ,    6    ,    2    ,    3    },
    {    2    ,    5    ,    6    ,    2    ,    1    ,    4    ,    3    },
    {    2    ,    6    ,    2    ,    5    ,    4    ,    3    ,    1    },
    {    2    ,    6    ,    4    ,    3    ,    2    ,    5    ,    1    },
    {    3    ,    1    ,    3    ,    4    ,    5    ,    2    ,    6    },
    {    3    ,    1    ,    5    ,    2    ,    3    ,    4    ,    6    },
    {    3    ,    2    ,    1    ,    5    ,    6    ,    3    ,    4    },
    {    3    ,    3    ,    4    ,    1    ,    2    ,    6    ,    5    },
    {    3    ,    4    ,    6    ,    5    ,    1    ,    3    ,    2    },
    {    3    ,    5    ,    4    ,    6    ,    2    ,    1    ,    3    },
    {    3    ,    6    ,    3    ,    2    ,    5    ,    4    ,    1    },
    {    3    ,    6    ,    5    ,    4    ,    3    ,    2    ,    1    },
    {    4    ,    1    ,    4    ,    5    ,    2    ,    3    ,    6    }





        };

        int a[10],b[10];
    int main()
    {

        while(scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&a[1],&a[6],&a[5],&a[3],&a[2],&a[4],&b[1],&b[6],&b[5],&b[3],&b[2],&b[4])!=EOF)
        {
            int ans=-1;
            for(int i=1;i<=24;i++)
            {
                int same=1;
                for(int j=1;j<=6;j++)
                    if(a[r[i][j]]!=b[j]){same=0;break;}
                if(same)ans=r[i][0];
                if(ans!=-1)break;
            }
            printf("%d\n",ans);
        }
        return 0;
    }

1007
#include <cstdio>
#include <cstring>
#include <cmath>
long double f[16][17][17], g[16][17][17];
long double pr[16][16], h[16][16];
int n, m;
int main() {
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 0; i < m; i++) {
            pr[i][0] = 1;
            double t; scanf("%lf", &t), pr[i][1] = t;
            for (int j = 2; j < n; j++)
                pr[i][j] = pr[i][j-1] * pr[i][1];
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                double t; scanf("%lf", &t), h[i][j] = t;
            }
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        long double ans = 0;
        for (int j = 1; j < n; j++) {
            f[j][0][0] = 1;
            for (int k = 0; k < m; k++)
                for (int p = m; p >= 0; p--)
                    for (int q = p; q >= 0; q--) {
                        f[j][p][q] *= 1 - pr[k][j-1];
                        if (p > 0) f[j][p][q] += f[j][p-1][q] * pr[k][j-1] * (1-pr[k][1]);
                        if (p > 0 && q > 0) f[j][p][q] += f[j][p-1][q-1] * pr[k][j];
                        g[j][p][q] *= 1 - pr[k][j-1];
                        if (p > 0) g[j][p][q] += g[j][p-1][q] * pr[k][j-1] * (1-pr[k][1]);
                        if (p > 0 && q > 0) g[j][p][q] += g[j][p-1][q-1] * pr[k][j]
                            + f[j][p-1][q-1] * pr[k][j] * h[k][j];
                    }
            for (int p = 1; p <= m; p++)
                for (int q = 1; q <= p; q++)
                    ans += g[j][p][q] * ((double)q / p + 1);
        }
        for (int i = 0; i < m; i++)
            ans += h[i][0];
        printf("%.8lf\n", (double)ans);
    }
    return 0;
}

1008
#include"string.h"
#include"stdio.h"
#include"queue"
#include"stack"
#include"vector"
#include"algorithm"
#include"iostream"
#include"math.h"
#include"stdlib.h"
#define M 100009
#define inf 100000000
#define eps 1e-10
#define PI acos(-1.0)
using namespace std;
int a[M],vis[M],po[33],ans[M];
int fun(int n)
{
    int s=0;
    while(n)
    {
        n=n/2;
        s++;
    }
    return s;
}
int main()
{
    int n,i,j,m;
    po[0]=1;
    for(i=1;i<=20;i++)
        po[i]=po[i-1]*2;
    while(scanf("%d",&n)!=-1)
    {
        for(i=0;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(vis,-1,sizeof(vis));
        for(i=n;i>=0;)
        {
            int k=fun(i);
            int sum=po[k]-1;
            m=i^sum;
            for(j=i;j>=m;j--)
            {
                int kk=fun(j);
                int ss=po[kk]-1;
                int t=j^ss;
                //printf("%d %d\n",j,t);
                if(vis[j]==-1)
                {
                    ans[j]=t;
                    ans[t]=j;
                    vis[j]=1;
                    vis[t]=1;
                }

            }
            i=m-1;
        }
        __int64 nn=n;
        printf("%I64d\n",nn*(nn+1));
        for(i=0;i<=n;i++)
        {
            if(i==0)
                printf("%d",ans[a[i]]);
            else
                printf(" %d",ans[a[i]]);
        }
        printf("\n");
    }
}
