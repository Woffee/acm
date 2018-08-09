/*
VirtualFriends 并查集
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;
const int MAX=100005;
int parent[MAX],sum[MAX];
int number;
map<string,int>fri;

int find(int x)
{
    if(x!=parent[x])
        parent[x]=find(parent[x]);
    return parent[x];
}
void union_set(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
    {
        parent[x]=y;
        sum[y]+=sum[x];
    }
}

int main()
{
    int t,n;
    string a,b;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            number=0;
            fri.clear();
            scanf("%d",&n);
            while(n--)
            {
                cin>>a>>b;
                if(fri.find(a)==fri.end())
                {
                    number++;
                    fri[a]=number;
                    parent[number]=number;
                    sum[number]=1;

                }
                if(fri.find(b)==fri.end())
                {
                    number++;
                    fri[b]=number;
                    parent[number]=number;
                    sum[number]=1;
                }
                union_set(fri[a],fri[b]);
                int ans=find(fri[b]);
                printf("%d\n",sum[ans]);
            }
        }
    }
    return 0;
}


/*
    Oulipo KMP
    string 类型的输入要加<string>头文件
    不然C++编译不过
    另：此题G++ Time Limited Exceeded
*/

#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int next[10005];
int wordlen,textlen;
int ans;

void getnext(string word)
{
    int i=0;
    int j=-1;
    next[0]=-1;
    while(i<wordlen)
    {
        if(j==-1||word[i]==word[j])
        {
            ++i;++j;
            if(word[i]!=word[j])
                next[i]=j;
            else
                next[i]=next[j];
        }
        else
            j=next[j];
    }
}

void kmp(string text,string word)
{

    int i=0;
    int j=0;
    while(i<textlen&&j<wordlen)
    {
        if(j==-1||text[i]==word[j])
        {
            ++i;++j;
        }
        else
        {
             j=next[j];
        }
        if(j==wordlen)
        {
            ++ans;
            j=next[j];
        }
    }
}
int main()
{
    string word,text;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>word;
        cin>>text;
        ans=0;
        wordlen = word.length();
        textlen = text.length();
        getnext(word);
        kmp(text,word);
        cout<<ans<<endl;
    }

    return 0;
}
/*
最大三角形  凸包

给定二维的平面上n个不同的点，要求在这些点里寻找三个点，使他们构成的三角形拥有的面积最大。
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

typedef struct 
{
        double x , y ;
}POINT ;
POINT result[50005] ;// 模拟堆栈S，保存凸包上的点
POINT tree[50005] ;
int n , top ;
double Distance ( POINT p1 , POINT p2 ) 
{
       return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ) ;
}
double Multiply(POINT p1 , POINT p2 , POINT p3) // 叉积 //direction
{
       return ( (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x) ) ;
}
int cmp ( const void *p1 , const void *p2 )
{
    POINT *p3,*p4;
    double m;
    p3 = (POINT *)p1; 
    p4 = (POINT *)p2; 
    m = Multiply(tree[0] , *p3 , *p4) ;// !!
    if(m < 0) return 1;
    else if(m == 0 && (Distance(tree[0] , *p3) < Distance(tree[0],*p4)))
        return 1;
    else return -1;
}
void Tubao ()
{
     int i ; 
     //初始时P[0]、P[1]、P[2]进栈
     result[0].x = tree[0].x;
     result[0].y = tree[0].y;
     result[1].x = tree[1].x;
     result[1].y = tree[1].y;
     result[2].x = tree[2].x;
     result[2].y = tree[2].y;
     top = 2;
     //对于P[3..n]的每个点
     for ( i = 3 ; i <= n ; ++ i )
     {
          //若栈顶的两个点与它不构成“向左转”的关系，则将栈顶的点出栈，
          //直至没有点需要出栈以后将当前点进栈；
          //所有点处理完之后栈中保存的点就是凸包了。
         while (Multiply(result[top - 1] , result[top] , tree[i]) <= 0 )
               top -- ;                          //出栈
          result[top + 1].x = tree[i].x ;
          result[top + 1].y = tree[i].y ;
          top ++ ;
     }

}
int main ()
{
    int pos ;
    double len , temp , px , py ;
    while ( cin>>n )
    {
          py = -1 ;
          for ( int i = 0 ; i < n ; ++ i )
          {

              scanf ( "%lf%lf" , &tree[i].x , &tree[i].y ) ;
              
          }
          if ( n == 3 )
          {
               double s= ((tree[1].x - tree[0].x) * (tree[2].y - tree[0].y ) -(tree[2].x - tree[0].x) * (tree[1].y - tree[0].y ))/2.0;
               s=s<0?-s:s;
               printf ( "%.2lf\n",s ) ;
               continue ;
          }
          for ( int i = 0 ; i < n ; ++ i )
          {
              if(py == -1 || tree[i].y < py)
                  {
                       px = tree[i].x;
                       py = tree[i].y;
                       pos = i;
                  }
                  else if(tree[i].y == py && tree[i].x < px)
                  {
                       px = tree[i].x;
                       py = tree[i].y;
                       pos = i;
                  }
          }
          temp = tree[0].x ;                      // 找出y最小的点 
          tree[0].x = tree[pos].x ;
          tree[pos].x = temp ;
          temp = tree[0].y ;
          tree[0].y = tree[pos].y ;
          tree[pos].y = temp ;
          qsort(&tree[1],n - 1,sizeof(double) * 2,cmp);
          tree[n].x = tree[0].x;
          tree[n].y = tree[0].y;
          Tubao();
          
          double maxarea=0.0;
          for(int i=0;i<top-2;++i)
          {
            for(int j=i+1;j<top-1;++j)
            {
              for(int k=j+1;k<top;++k)
              {
                //double s = ((x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0])) / 2.0;
                double s=((result[j].x - result[i].x) * (result[k].y - result[i].y ) -(result[k].x - result[i].x) * (result[j].y - result[i].y ))/2.0;
                //cout<<"S:"<<s<<endl;
                if(s>=maxarea) maxarea=s;
              }
            }
          }
          printf("%.2lf\n",maxarea);
   
    }
    return 0 ;
}

/*
改革春风吹满地 多边形面积
*/
#include <iostream>
#include <cstdio>
using namespace std;

int T, N, x[3], y[3];
double sumx, sumy, sumarea;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        sumx = sumy = sumarea = 0.0;
        N=n;
        
        cin>>x[0]>>y[0]>>x[1]>>y[1];//scanf("%d %d %d %d", x, y, x+1, y+1);
        N -= 2;
        while(N--)
        {
            cin>>x[2]>>y[2];//scanf("%d %d", x+2, y+2);
            //求新添加的三角形的面积
            double s = ((x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0])) / 2.0;
            //求∑x[i]*s[i]和∑y[i]*s[i]
            sumx += ((x[0] + x[1] + x[2]) * s);
            sumy += ((y[0] + y[1] + y[2]) * s);
            //求总面积
            sumarea += s;

            x[1] = x[2];
            y[1] = y[2];
        }
        printf("%.1lf\n", sumarea);
    }
    return 0;
}
/*
Buy The Tickets 卡特兰数
又一个经典的卡特兰数的应用：50元的数量永远不小于100元的数量，m和n最大均为100，第200位卡特兰数是373位

f(m,n)=c(m+n,n)-c(m+n,m+1)  再乘以m!和n!,化简后为(m+n)!*(m-n+1)/(m+1)
*/
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
int a[201][501],b[501];

int main()
{
    int i,j,s,sort,m,n,u;

    memset(a,0,sizeof(a));
    a[0][0]=1;
    a[1][0]=1;
    int temp,k=0;

    for(i=2; i<201; i++)             //预处理阶乘
    {
        for(j=0,s=0; j<501; j++)
        {
            temp=i*a[i-1][j]+s;
            a[i][j]=temp%10;
            s=temp/10;
        }
    }

    sort=0;
    while(scanf("%d%d",&m,&n)!=EOF&&(m||n))
    {
        printf("Test #%d:\n",++sort);
        if(m<n)
        {
            printf("0\n");
            continue;
        }
        i=m-n+1;
        memset(b,0,sizeof(b));
        for(j=0,s=0; j<501; j++)
        {
            temp=i*a[m+n][j]+s;
            b[j]=temp%10;
            s=temp/10;
        }
        k=500;

        while(k>=0&&b[k]==0) k--;
        for(j=k,s=0,u=0; j>=0; j--)
        {
            temp=s*10+b[j];
            if(u==0)
            {
                if(temp/(m+1)>0)                 //对于第1次输出要谨慎，防止先输出0
                {
                    u=1;
                    printf("%d",temp/(m+1));
                }
            }
            else printf("%d",temp/(m+1));
            s=temp%(m+1);
        }
        printf("\n");
    }
    return 0;
}

/*
敌兵布阵 树状数组
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 50005
int a[N],c[N];
int n;
int lowbit(int x)
{
    return x&(x^(x-1));
}
void update(int p,int x)
{
    while(p<=n)
    {
        c[p]+=x;
        p+=lowbit(p);
    }
}
int sum(int p) //前p相的和
{
    int sum=0;
    while(p>0)
    {
        sum+=c[p];
        p-=lowbit(p);
    }
    return sum;
}
int main()
{
    int t,i,m,k;
    int a1,a2;
    char str[10];
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++)    //初值为0
        {
            scanf("%d",&m);
            a[i]+=m;
            update(i,m);
        }
        printf("Case %d:\n",k);
        while(scanf("%s",str),strcmp(str,"End"))
        {
            if(strcmp(str,"Add")==0)
            {
                scanf("%d%d",&a1,&a2);
                a[a1]+=a2;
                update(a1,a2);
            }
            else if(strcmp(str,"Sub")==0)
            {
                scanf("%d%d",&a1,&a2);
                a[a1]-=a2;
                update(a1,-a2);
            }
            else if(strcmp(str,"Query")==0)
            {
                scanf("%d%d",&a1,&a2);
                printf("%d\n",sum(a2)-sum(a1-1));
            }
        }
    }
    return 0;
}
/*
统计难题 字典树
*/
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

struct WordNode{
    //num可以表示一个字典树到此有多少相同前缀的数目，这里根据需要应当学会自由变化。
    int num ;
    //next是表示每层有多少种类的数，如果只是小写字母，则26即可，
    //若改为大小写字母，则是52，若再加上数字，则是62了，这里根据题意来确定。
    WordNode * nextNode[26];
};

WordNode wordNode[10000000];
int index ;
WordNode * ip ;

void insertNode(char str[11])
{
    ip = wordNode ;
    for(int i = 0; i < strlen(str);i ++)
    {
        if(ip->nextNode[str[i] - 'a'] != 0)
        {
            ip->nextNode[str[i] - 'a']->num ++ ;
        }
        else
        {
            index ++ ;
            ip->nextNode[str[i] - 'a'] = wordNode + index ;
            ip->nextNode[str[i] - 'a']->num = 1 ;
        }
        ip = ip->nextNode[str[i] - 'a'] ;
    }
    
}
int search(char str[11])
{
    ip = wordNode ;
    for(int  i = 0; i < strlen(str); i ++)
    {
        if(ip->nextNode[str[i] - 'a'] != NULL)
            ip = ip->nextNode[str[i] - 'a'] ;
        else
            return 0 ;
    }
    return ip->num ;

}
int main()
{
    char temp[11];
    
    while(gets(temp)) 
    {
        if(strlen(temp)==0)
            break;
        insertNode(temp) ;
    }

    while(gets(temp) != NULL)
    {
        cout<<search(temp)<<endl;
    }
    
    return 0;
}

/*
Bone Collector    

http://acm.hdu.edu.cn/showproblem.php?pid=2602

赤裸裸的 01背包问题
*/
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>  
using namespace std;

int value[1005],dp[1005],volume[1005]; 

int main()
{
    int t;
    int n,v;
    int i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>v;
        for(i = 1; i<=n; i++)
            scanf("%d",&value[i]);
        for(i = 1; i<=n; i++)
            scanf("%d",&volume[i]);
        
        memset(dp,0,sizeof(dp));

        for (i=1;i<=n;i++)
        {
            for (j=v;j>=volume[i];j--)
                dp[j]=max(dp[j],dp[j-volume[i]]+value[i]);
        }
        printf("%d\n",dp[v]); 
    }
    return 0;
}


/*
Coins
http://acm.hdu.edu.cn/showproblem.php?pid=2844

题目大意：给你钱币的价值和数量，求能组成的方案数，有上限约束
模版题：
*/

#include <stdio.h>
#include <algorithm>
#include <string.h>
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

int main()
{
    int n;
    while(~scanf("%d%d",&n,&v),n+v)
    {
        int i;
        for(i = 0;i<n;i++)
            scanf("%d",&c[i]);
        for(i = 0;i<n;i++)
            scanf("%d",&w[i]);
        memset(dp,0,sizeof(dp));
        for(i = 0;i<n;i++)
        {
            MultiplePack(c[i],c[i],w[i]);
        }
        int sum = 0;
        for(i = 1;i<=v;i++)
        {
            if(dp[i]==i)
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}


/*
Dividing
http://acm.hdu.edu.cn/showproblem.php?pid=1059
题意：有一些被划分为1-6价值的石头，并已知每个价值有多少块，求可否将石头分成两份且价值相等。
思路：求出总价值，除2。转化为大小为（总价值/2）的背包可否恰好装满的问题。
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;
const int MAX=444444;
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

int main()
{
    int num[7]={0};
    int i,j,k;
    int num_case=1;
    while(1){
        v=0;
        for(i=1;i<=6;i++){
            cin>>num[i];
            v+=num[i]*i;
        }
        if(!v)break;
    if(v & 1){
        printf("Collection #%d:\n",num_case++);
        printf("Can't be divided.\n\n");
        continue;
    }

    memset(dp, 0, sizeof(dp));

        int halfv=v/2;
    
        for(i=1;i<=6;i++){
            MultiplePack(i,i,num[i]);
        }
        cout<<"Collection #"<<num_case++<<":"<<endl;
        if(dp[halfv]==halfv)cout<<"Can be divided."<<endl;
        else cout<<"Can't be divided."<<endl;
        cout<<endl;
    }
    return 0;
}


/*
Doing Homework

大意：给出每项作业， 有它的截止时间和完成它要花的时间， 如果在截止时间后完成， 要扣学分，
让找出最佳的做作业顺序，使扣得学分最少。

思路：          
        用2进制表示作业的完成情况， 0代表未完成， 1代表完成，共有n个作业， 
        那么所有作业完成的情况就是2的n次方减1（000~111）

        声明两个结构数组，一个用来存储给出的数据，不用说
        另一个是dp数组，每个结构就是一个状态,包括：  
                        总共花的时间
                        减少的学分
                        前一项作业号码
                        当前做的课程名

        然后从状态000到状态111遍历，嵌套一个for循环遍历作业，判断当前状态是否完成该作业
        如果完成就跳过，否则就完成它，记录花的时间和扣的分数

        如果完成后的状态前面已经处理过，就取扣的学分少的那个

        最后输出就可以了

        课程名要逆着输出，可以用栈，也可以递归
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
using namespace std; 
struct  
{  
    int cost;//总共花的时间  
    int reduce;//减少分数  
    int pre;//记录前一个  
    char name[102];  //当前状态最后完成的作业
}dp[32769];  
struct  
{  
    int time;  
    int cost;  
    char name[102];  
}e[16];  
void print(int i)  
{  
    if(dp[i].pre == -1)  
        return;  
    print(dp[i].pre);  //逆序输出刚好正确
    printf("%s\n",dp[i].name);  
}  
int main()  
{  
    int i = 0, j = 0, n = 0, t = 0, total = 0, cur = 0, all_time = 0, visit[32769];  
    int cost = 0,  reduce = 0;  
    scanf("%d",&t);  
    while(t--)  
    {  
        memset(visit, 0, sizeof(visit));  
        all_time = 0;  
        scanf("%d",&n);  
        total = 1<<n;  
        getchar();  
        dp[0].cost = dp[0].reduce = 0;  
        dp[0].pre = -1;  
        for(i = 0; i<n; i++)  
        {  
            scanf("%s %d %d",e[i].name, &e[i].time, &e[i].cost);  
        }  
        for(i = 0; i<total; i++)  
        {  
            for(j = 0; j<n; j++)  
            {  
                cur = 1<<j; //用2进制表示作业的完成情况,这里cur依次等于001,010,100

                if(!(i&cur))//按位与运算，i&cur == 0表示当前第j个作业未完成 
                {  
                    cur = i|cur;//按位或运算，cur为完成了作业j的状态  
                    cost = dp[i].cost+e[j].cost;//当前一共花了多少时间  
                    reduce = cost-e[j].time;//这回扣了多少分  
                    if(reduce<0)  
                        reduce = 0;  
                    reduce += dp[i].reduce;//这回的扣分加上以前的扣分为总扣得分数  
                    if(visit[cur])//如果cur这个状态曾经处理过，就取扣分少的  
                    {  
                        if(reduce<dp[cur].reduce)  
                        {  
                            dp[cur].cost = cost;  
                            dp[cur].reduce = reduce;  
                            dp[cur].pre = i;  
                            strcpy(dp[cur].name, e[j].name);  
                        }  
                    }  
                    else  
                    {  
                        visit[cur] = 1;  //标记为处理过
                        dp[cur].cost = cost;  
                        dp[cur].reduce = reduce;  
                        dp[cur].pre = i;  
                        strcpy(dp[cur].name, e[j].name);  
                    }  
                }  
            }  
        }  
        printf("%d\n",dp[total-1].reduce);  
        print(total-1);  
    }  
    return 0;  
}  



/*
LCS
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
    char y[]={"yABCBDAB"};
    char x[]={"xBDCABA"};

    int vis[10][10]={0};
    int C[10][10]={0};
    
    int i,j;
    int lx=sizeof(x)-1;
    int ly=sizeof(y)-1;

    for(i=1;i<lx;++i)
    {
        for(j=1;j<ly;++j)
        {
            if(x[i]==y[j])
            {
                vis[i][j]=1;
                C[i][j]=C[i-1][j-1]+1;
            }
            else 
                C[i][j]=max(C[i-1][j],C[i][j-1]);
        }
    }

    cout<<C[lx-1][ly-1]<<endl;
}

/*
Piggy-Bank

http://acm.hdu.edu.cn/showproblem.php?pid=1114

背包

给出n种面值的硬币，每种面值的硬币有一定的重量， 
给出存钱罐的净重和存钱罐装满的重量， 
要求求出存钱罐里最少有多少钱
注：必须装满存钱罐，否则输出 This is impossible.

*/
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

const int MAX = 10050;
int P[MAX],W[MAX];//P is the value of coins, W is the weight of coins
int dp[MAX];
int main()
{
    int t;
    int e,f,n,p,w,temp;
    cin>>t;
    while(t--)
    {
        cin>>e>>f>>n;
        for(int i=0;i<n;++i)
        {
            cin>>P[i]>>W[i];
        }//get data

        temp=f-e;

        dp[0]=0;
        for(int i=1;i<=temp;i++)  
        {  
            dp[i]=999999999;  
        } //reset

        for(int i=0;i<n;i++)  
            for(int m=W[i];m<=temp;m++)  
                if(dp[m-W[i]]+P[i]<dp[m])  
                    dp[m]=dp[m-W[i]]+P[i];
        
        if(dp[temp]==999999999)
            cout<<"This is impossible."<<endl;
        else 
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[temp]<<"."<<endl;
    }
    return 0;
}


/*
Watch The Movie
http://acm.hdu.edu.cn/showproblem.php?pid=3496

题意：输入N，M，V 从 N 个 movies 中选择 M 个movies 是使得价值最大。

背包问题
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
using namespace std;

const int MAX=1005;
int dp[MAX][MAX];
int c[MAX],w[MAX];
int inf=999999;
int main()
{
    int t;
    int n,m,l;
    int i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l;

        for(i=0;i<n;++i){
            cin>>c[i]>>w[i];
        }

        for(i=0;i<=m;i++)  
            for(j=0;j<=l;j++)  
            {  
                if(i==0)  
                    dp[i][j]=0;  
                else  
                    dp[i][j]=-inf; //注意初始化为负无穷，价值可能是负值  
            }  

        for(i=0;i<n;++i)
            for(j=m;j>=1;j--)
                for(k=l;k>=c[i];k--)
                    dp[j][k]=max(dp[j][k],dp[j-1][k-c[i]]+w[i]);
        if(dp[m][l]<0)  
            dp[m][l]=0;  
        printf("%d\n",dp[m][l]);  
    }
    return 0;
}


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
    while(scanf("%d",&n)!=EOF)
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

/*
最大连续子序列  动态规划

http://acm.hdu.edu.cn/showproblem.php?pid=1231

题意：给你一系列整数，选出所有 连续子序列 中 元素和最大 的一个子序列，
输出最大和、最大连续子序列的第一个和最后一个元素

思路见注释
*/


#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;
const int MAX=10005;

int a[MAX];

int main()
{
    int n;
    int flag,max,sum,start,end,temp;
    int i,j;
    while(cin>>n && n){
         flag=0;
         for(i=0;i<n;i++)
         {
             scanf("%d",&a[i]);
             if(a[i]>=0)
                 flag=1;
         }
         max=0;
         if(flag==0)
         {
             printf("%d %d %d\n",max,a[0],a[n-1]);
             continue;
         }
         else
         {
            sum=a[0];
            max=a[0];
            start=0;
            end=0;
            temp=0;  //临时起点
            for(i=1;i<n;++i)
            {
                if(sum<0) { //如果前几项和小于0，就从新开始记录
                    sum=0;
                    temp=i; //刷新临时起点
                }
                sum+=a[i];              
                if(sum>max){ //如果现在的sum大于原来的max,刷新数据
                    max=sum;
                    start=temp;
                    end=i;
                }
            }
            printf("%d %d %d\n",max,a[start],a[end]);
         }
    }
}

/*
最少拦截系统

http://acm.hdu.edu.cn/showproblem.php?pid=1257

大意：
    给你导弹依此飞来的高度，每个导弹拦截系统拦截的高度不能大于上一个导弹高度
    输出拦截所有导弹最少要配备多少套这种导弹拦截系统.

思路:
    首先存储所有导弹高度，然后依次遍历每个高度
    对于每个导弹高度，向后找比它高度小的导弹，那么这些导弹都可以用一个系统拦截，
    并把它们标记为0，遍历的时候略过它们
*/
#include <iostream>
using namespace std;

int hight[1000];
int vis[1000];

int main()
{
    int n;
    while(cin >> n)
    {
        int i,cnt = 0;
        for(i = 0; i<n; i++)
        {
            cin >> hight[i];
            vis[i] = 1;
        }
        for(i = 0; i<n; i++)
        {
            if(vis[i])
            {
                int flag = hight[i];
                for(int j = i+1; j<n; j++)
                {
                    if(vis[j] && hight[j]<=flag)
                    {
                        vis[j] = 0;
                        flag =hight[j];
                    }
                }
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}


/*
还是畅通工程

http://acm.hdu.edu.cn/showproblem.php?pid=1233

每行给出三个正整数，分别是两个村庄的编号，以及此两村庄间的距离。
对每个测试用例，在1行里输出最小的公路总长度。

本来是学到图才碰到的题目,结果还是用了并查集：
先按距离从小到大排序，然后合并村庄

*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std; 
const int MAX=1000005;
int ans=0;

int parent[MAX];
//int rank[MAX];

struct s
{
    int x;
    int y;
    int d;
}e[MAX];
bool cmp(const s &a,const s &b)  //此处借鉴他人
{  
      return b.d > a.d;//降序  
}  
void make_set()
{
    int i;
    for(i=1;i<MAX;i++){
        parent[i]=i;
        //rank[i]=1;
    }
}
int find(int x){
    if(x!=parent[x])
        parent[x]=find(parent[x]);
    return parent[x];
}
int union_set(int x,int y){
    x=find(x),y=find(y);
    if(x!=y){
            parent[x]=y;
            return 1;
    }
    return 0;
}
int main()
{
    int m,n;
    int i;

    while(cin>>m && m){
        make_set();
        ans=0;
        n=m*(m-1)/2;
        for(i=1;i<=n;i++){
            cin>>e[i].x>>e[i].y>>e[i].d;
        }
        sort(e+1,e+n+1,cmp);

        for(i=1;i<=n;i++){
            if(union_set(e[i].x,e[i].y))
                ans+=e[i].d;
        }
        cout<<ans<<endl;
    }
}



/*
六度分离  （Floyd）
http://acm.hdu.edu.cn/showproblem.php?pid=1869

六度分离:每两个人，只用6个人就可以将他们联系在一起
输入数据，判断是否符合六度分离

*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
using namespace std; 

const int MAX=150;
int d[MAX][MAX];
bool flag=true;
int m,n;
int a,b;
int i,j,k;

int main()
{
    while(cin>>m>>n){
        for( i=0; i<MAX; i++)  
                    for( j=0; j<MAX; j++) d[i][j] = 3000000;
            for( i=0; i<MAX; i++) d[i][i] = 0;      
        flag=true;
        for(i=1;i<=n;++i){
            scanf("%d%d", &a, &b);  
            d[a][b]=d[b][a]=1;
        }
        for(k=0;k<m;++k){          //注意此处是总人数m，不是n
            for(i=0;i<m;++i){
                for(j=0;j<m;++j){
                    if(d[i][k]+d[k][j]<d[i][j])
                        d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
        for(i=0;i<m;++i){
            for(j=0;j<m;++j)
                if(d[i][j]>7){
                    flag=false;
                    break;
                }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}


/*
迷宫城堡 （强联通）
http://acm.hdu.edu.cn/showproblem.php?pid=1269
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std; 
#define maxn 10001
struct Edge
{
       int v,next;
} e[maxn*10],re[maxn*10];
bool visit[maxn];
int t[maxn],n,head[maxn],size,rhead[maxn];
void AddEdge(int a,int b)
{
     e[size].v=b;
     e[size].next=head[a];
     head[a]=size;
     re[size].v=a;//建立反向图。
     re[size].next=rhead[b];
     rhead[b]=size;
     size++;
}
void DFS1(int u,int&cnt)
{
     visit[u]=true;
     for(int i=head[u]; i!=-1; i=e[i].next){
          int v=e[i].v;
          if( !visit[v])
              DFS1(v,cnt);
     }
     t[++cnt]=u;
}
void DFS2(int u)
{
     visit[u]=true;
     for(int i=rhead[u]; i!=-1; i=re[i].next){
             int v=re[i].v;
             if( !visit[v])
                 DFS2(v);
     }
}
int main()
{
    int cnt,m,a,b,i;
    while( scanf("%d%d",&n,&m)){
           if( n==0&&m==0) break; 
           
           memset(head,-1,sizeof(head));
           memset(rhead,-1,sizeof(rhead));
           memset(e,0,sizeof(e));
           size=0;
           
           while( m--){
                  scanf("%d%d",&a,&b);
                  AddEdge(a,b);
           }
           
           memset(visit,false,sizeof(visit));
           memset(t,0,sizeof(t));
           for(cnt=0,i=1; i<=n; i++){ //正向DFS
                if( !visit[i])
                    DFS1(i,cnt);
           } 
                
           memset(visit,false,sizeof(visit));
           for(cnt=0,i=n; i>=1; i--){ //反向DFS
                if( !visit[t[i]]){
                    DFS2(t[i]);
                    cnt++;
                }
           }
          
           if( cnt==1)
               printf("Yes\n");
           else
               printf("No\n"); 
    }
    return 0;
}


/*
确定比赛名次
http://acm.hdu.edu.cn/showproblem.php?pid=1285
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std; 

int map[505][505];
int indegree[505];
int ans[505];


void topological(int n)
{
    for(int i=1; i<=n; i++)
    {
        int j = 1 ;
        while(indegree[j])//find indegree==0
        j++ ;
        ans[i] = j ;
        indegree[j] = -1 ;
        for(int k=1; k<=n; k++)
        {
            if(map[j][k])
            indegree[k]-- ;
        }
    }

}
int main()
{
    int n,m;
    int a,b;
    int i,j,k;
    
    while(cin>>n>>m)
    {
        memset(map,0,sizeof(map));
        memset(indegree,0,sizeof(indegree));

        for(i=1;i<=m;i++){
            cin>>a>>b;
            
            if(!map[a][b]) //!
                indegree[b]++;

            map[a][b]=1;
        }
        topological(n);

        for(i=1;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<ans[n]<<endl;
    }

}



/*
最短路 (Floyd)
http://acm.hdu.edu.cn/showproblem.php?pid=2544
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std; 


const int MAX=105;
int d[MAX][MAX];
int m,road;
int a,b,c;
int i,j,k;

int main()
{
    while(cin>>m>>road && (m || road)){
        for( i=0; i<MAX; i++)  
                    for( j=0; j<MAX; j++) d[i][j] = 3000000;
            //for( i=0; i<MAX; i++) d[i][i] = 0;    

        for(i=1;i<=road;++i){
            scanf("%d%d%d", &a, &b,&c);  
            if(d[a][b]>c)d[a][b]=d[b][a]=c;//注意这个if条件
        }
        for(k=1;k<=m;++k){        
            for(i=1;i<=m;++i){
                for(j=1;j<=m;++j){
                    if(d[i][k]+d[k][j]<d[i][j])
                        d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
        cout<<d[1][m]<<endl;

    }
    return 0;
}


/*
最短路径问题
http://acm.hdu.edu.cn/showproblem.php?pid=3790

非原创
*/

#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
const int N = 1000 + 10;
const int MAX = 0xfffffff;
int map[N][N], cost[N][N];
int min_dis, min_cost;
 
void Dijkstra(int s, int t, int n)
{
    int dis[N], cost1[N];
    bool visit[N];
    memset(visit, false, sizeof(visit));
    for(int i = 1; i <= N; ++i)
    {
        dis[i] = map[s][i];
        cost1[i] = cost[s][i];
    }
    dis[s] = 0;
    visit[s] = true;
    for(int i = 1; i < n; ++i)
    {
        int min = MAX;
        int k;
        for(int j = 1; j <= n; ++j)
        {
            if(!visit[j] && min > dis[j])
            {
                min = dis[j];
                k = j;
            }
        }
        visit[k] = true;
        for(int j = 1; j <= n; ++j)
        {
            if(!visit[j] && dis[j] > min + map[k][j])
            {
                dis[j] = min + map[k][j];
                cost1[j] = cost[k][j] + cost1[k];
            }
            else if(!visit[j] && dis[j] == min + map[k][j] && cost1[j] > cost[k][j] + cost1[k])
            {
                cost1[j] = cost[k][j] + cost1[k];
            }
        }
        if(visit[t])
        {
            min_dis = dis[t];
            min_cost = cost1[t];
            return ;
        }
    }
    min_dis = dis[t];
    min_cost = cost1[t];
}
 
int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) && (m || n))
    {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <i; ++j)
            {
                map[i][j] = map[j][i] = MAX;
                cost[i][j] = cost[j][i] = MAX;
            }
        while(m--)
        {
            int a, b, d, p;
            scanf("%d%d%d%d", &a, &b, &d, &p);
            if(map[a][b] > d)
            {
                map[a][b] = map[b][a] = d;
                cost[a][b] = cost[b][a] = p;
            }
        }
        int s, t;
        scanf("%d%d", &s, &t);
        Dijkstra(s, t, n);
        printf("%d %d\n", min_dis, min_cost);
    }
    return 0;
}



/*
判断两条线段是否相交_模版
*/
#include <iostream>  
   
using namespace std;  
struct point  
{  
    double x,y;  
};  
struct segment  
{  
    point begin,end;  
};  
double min(double x,double y)  
{  
    return x<y?x:y;  
}  
double max(double x,double y)  
{  
    return x>y?x:y;  
}  
bool onsegment(point pi,point pj,point pk) //判断点pk是否在线段pi pj上   
{  
    if(min(pi.x,pj.x)<=pk.x&&pk.x<=max(pi.x,pj.x))  
    {  
        if(min(pi.y,pj.y)<=pk.y&&pk.y<=max(pi.y,pj.y))  
        {  
            return true;  
        }  
    }  
    return false;  
}  
double direction(point pi,point pj,point pk) //计算向量pkpi和向量pjpi的叉积   
{  
    return (pi.x-pk.x)*(pi.y-pj.y)-(pi.y-pk.y)*(pi.x-pj.x);  
}  
bool judge(point p1,point p2,point p3,point p4) //判断线段p1p2和p3p4是否相交   
{  
    double d1 = direction(p3,p4,p1);  
    double d2 = direction(p3,p4,p2);  
    double d3 = direction(p1,p2,p3);  
    double d4 = direction(p1,p2,p4);  
    if(d1*d2<0&&d3*d4<0)  
        return true;  
    if(d1==0&&onsegment(p3,p4,p1))  
        return true;  
    if(d2==0&&onsegment(p3,p4,p2))  
        return true;  
    if(d3==0&&onsegment(p1,p2,p3))  
        return true;  
    if(d4==0&&onsegment(p1,p2,p4))  
        return true;  
    return false;  
}  
int main()  
{  
    int n,count;  
    segment seg[101];  
    while(cin>>n&&n)  
    {  
        count = 0;  
        for(int i=1; i<=n; i++)  
        {  
            cin>>seg[i].begin.x>>seg[i].begin.y>>seg[i].end.x>>seg[i].end.y;  
        }  
        for(int i=1; i<n; i++)  
            for(int j=i+1; j<=n; j++)  
            {  
                if(judge(seg[i].begin,seg[i].end,seg[j].begin,seg[j].end))  
                {  
                    count++;  
                }  
            }  
            cout<<count<<endl;  
    }  
    return 0;  
}



/*
Lifting the Stone 

计算多边形重心方法：
（1）划分多边形为三角形：
以多边形的一个顶点V为源点（V可取输入的第一个顶点），作连结V与所有非相邻顶点的线段，即将原N边形或分为（N-2）个三角形；
（2）求每个三角形的重心和面积：
设某个三角形的重心为G（cx，cy），顶点坐标分别为A1（x1，y1），A2（x2，y2），A3（x3，y3），则有cx = (x1 + x2 + x3)/3.同理求得cy。求面积的方法是s =  ( (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) ) / 2，当A1,A2,A3顺时针排列时取-，否则取正（此定理不证）。事实上，在求每个三角形时不需要辨别正负，之后有方法抵消负号，见下述。
（3）求原多边形的重心：
公式：cx = (∑ cx[i]*s[i]) / ∑s[i];  cy = (∑ cy[i]*s[i] ) / ∑s[i];其中（cx[i], cy[i]）, s[i]分别是所划分的第i个三角形的重心坐标和面积。由题“ connect the points in the given order”知每个s[i]的正负号相同，故而∑ cx[i]*s[i]能与∑s[i]消号，所以根本不需要在第（2）步判断每个s[i]的正负。另外，在（2）中求每个重心坐标时要除以3，实际上不需要在求每个三角形坐标时都除以3，只需要求出∑ cx[i]*s[i]后一次性除以3即可。即是多边形重心坐标变为：cx = (∑ cx[i]*s[i]) / （3*∑s[i]）;  cy = (∑ cy[i]*s[i] ) / （3*∑s[i]）;

总结：
每个三角形重心：cx = x1 + x2 + x3；cy同理。
每个三角形面积：s =  ( (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) ) / 2；
多边形重心：cx = (∑ cx[i]*s[i]) / （3*∑s[i]）;  cy = (∑ cy[i]*s[i] ) / （3*∑s[i]）;
*/

#include <iostream>
#include <cstdio>
using namespace std;

int T, N, x[3], y[3];
double sumx, sumy, sumarea;

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        sumx = sumy = sumarea = 0.0;
        scanf("%d", &N);
        
        cin>>x[0]>>y[0]>>x[1]>>y[1];//scanf("%d %d %d %d", x, y, x+1, y+1);
        N -= 2;
        while(N--)
        {
            cin>>x[2]>>y[2];//scanf("%d %d", x+2, y+2);
            //求新添加的三角形的面积
            double s = ((x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0])) / 2.0;
            //求∑x[i]*s[i]和∑y[i]*s[i]
            sumx += ((x[0] + x[1] + x[2]) * s);
            sumy += ((y[0] + y[1] + y[2]) * s);
            //求总面积
            sumarea += s;

            x[1] = x[2];
            y[1] = y[2];
        }
        printf("%.2lf %.2lf\n", sumx / sumarea / 3, sumy / sumarea / 3);
    }
    return 0;
}



/*
Surround the trees 凸包模版
给你一些树木的坐标，用最短的绳子把小树林全部包住，求绳的长度。
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct 
{
        double x , y ;
}POINT ;
POINT result[110] ;// 模拟堆栈S，保存凸包上的点
POINT tree[110] ;
int n , top ;
double Distance ( POINT p1 , POINT p2 ) 
{
       return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ) ;
}
double Multiply(POINT p1 , POINT p2 , POINT p3) // 叉积 //direction
{
       return ( (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x) ) ;
}
int cmp ( const void *p1 , const void *p2 )
{
    POINT *p3,*p4;
    double m;
    p3 = (POINT *)p1; 
    p4 = (POINT *)p2; 
    m = Multiply(tree[0] , *p3 , *p4) ;// !!
    if(m < 0) return 1;
    else if(m == 0 && (Distance(tree[0] , *p3) < Distance(tree[0],*p4)))
        return 1;
    else return -1;
}
void Tubao ()
{
     int i ; 
     //初始时P[0]、P[1]、P[2]进栈
     result[0].x = tree[0].x;
     result[0].y = tree[0].y;
     result[1].x = tree[1].x;
     result[1].y = tree[1].y;
     result[2].x = tree[2].x;
     result[2].y = tree[2].y;
     top = 2;
     //对于P[3..n]的每个点
     for ( i = 3 ; i <= n ; ++ i )
     {
          //若栈顶的两个点与它不构成“向左转”的关系，则将栈顶的点出栈，
          //直至没有点需要出栈以后将当前点进栈；
          //所有点处理完之后栈中保存的点就是凸包了。
         while (Multiply(result[top - 1] , result[top] , tree[i]) <= 0 )
               top -- ;                          //出栈
          result[top + 1].x = tree[i].x ;
          result[top + 1].y = tree[i].y ;
          top ++ ;
     }

}
int main ()
{
    int pos ;
    double len , temp , px , py ;
    while ( scanf ( "%d" , &n ) != EOF , n )
    {
          py = -1 ;
          for ( int i = 0 ; i < n ; ++ i )
          {
              scanf ( "%lf%lf" , &tree[i].x , &tree[i].y ) ;

          }
          if ( n == 1 )
          {
               printf ( "0.00\n" ) ;
               continue ;
          }
          else if ( n == 2 )
          {
               printf ( "%.2lf\n" , Distance(tree[0] , tree[1]) ) ;
               continue ;
          }
          for ( int i = 0 ; i < n ; ++ i )
          {
              if(py == -1 || tree[i].y < py)
                  {
                       px = tree[i].x;
                       py = tree[i].y;
                       pos = i;
                  }
                  else if(tree[i].y == py && tree[i].x < px)
                  {
                       px = tree[i].x;
                       py = tree[i].y;
                       pos = i;
                  }
          }
          temp = tree[0].x ;                      // 找出y最小的点 
          tree[0].x = tree[pos].x ;
          tree[pos].x = temp ;
          temp = tree[0].y ;
          tree[0].y = tree[pos].y ;
          tree[pos].y = temp ;
          qsort(&tree[1],n - 1,sizeof(double) * 2,cmp);
          tree[n].x = tree[0].x;
          tree[n].y = tree[0].y;
          Tubao();
          len = 0.0;
          for(int i = 0 ; i < top ; i ++)
               len = len + Distance(result[i] , result[i+1]) ;
          printf("%.2lf\n",len);

    }
    return 0 ;
}
/*
Assistance Required
打表即可 ，很多网友说用链表模拟，我是直接用数组，效率也不低，140MS。
用一个数组ans储存3000个幸免参赛者的编号，设置布尔型数组que用以标记队伍中的哪些参赛者已经被征役去打杂，que[i] == false表明编号为i（注意第一个人的编号是2）的参赛者还未被征役，否则表明已经被选去洗碟子。
*/
#include <iostream>
#include <cstdio>
using namespace std;

int ans[3001] = {0};
bool que[40010] = {1, 1, 0};

int main()
{
    int k, i, j, cnt;
    for(k = 0; k < 3001; k++)
    {
        //这个for loop找到下一个未被选中的人
        for(i = ans[k-1]+1; que[i]; i++){}
        ans[k] = i;
        for(j = i+1, cnt = i; j < 40010; j++)
        {
            if(!que[j] && !--cnt)
            {
                que[j] = 1;
                cnt = i;
            }
        }
    }

    while(scanf("%d", &i) && i)
    {
        printf("%d\n", ans[i-1]);
    }
    return 0;
}
