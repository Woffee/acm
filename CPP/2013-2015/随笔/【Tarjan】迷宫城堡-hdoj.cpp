// 迷宫城堡

/*
    Low(u)为u或u的子树能够追溯到的最早的栈中节点的次序号

    我也想不懂为什么反向边要用前面的点的DFN值而不是LOW值更新呢?
    确实算出来的LOW[2]无法理解
        因为。。还在栈中的话LOW值还没有计算出来啊

    横插边：连接到已经出栈的节点的边；
    后向边：连接到已在栈中节点的边；
    树枝边:在搜索树中的边。
*/
    
//#include <stdafx.h>
#include<iostream>
#include<stdio.h>
#include<memory.h>
#include<fstream>
using namespace std;
int n,m;
struct edge{            //临接表存储方式
    int start,end;      //边所邻接的两个顶点
                        //边的权值
    int last;           //边指针，指向上一条边的内存池地址
};                      // 静态内存池，用于分配边
int head[10005];        // 表头  代表里面有几条边  如果为-1说明没有以i点为顶点的边
int  num;               // 边内存池的指针
edge e[100005];
int stack[10005];       //模拟栈
bool instack[10005];       //标记知否在栈中
int dfn[10005];         //节点u搜索的序号（时间戳）
int low[10005];         //u和u的子树能够追溯到的最早栈中的节点的序号（时间戳）
int mycount;            //连通分量的个数
int index;              //序号（时间戳）
int top;                //栈顶
void addEdge(int s,int en)
{
    e[++num].start=s;//这个点可以不存
    e[num].end=en;
    //e[num].w=w;
    e[num].last=head[s];
    head[s]=num;
}

void tarjan(int u){
    int v;
    dfn[u]=low[u]=++index;
    instack[u]=1;
    stack[++top]=u;
    for(int i=head[u];i!=-1;i=e[i].last){
        v=e[i].end;
        if(!dfn[v]){
            tarjan(v);
            if(low[v]<low[u])
                low[u]=low[v];
        }
        else
            if(instack[v] && dfn[v]<low[u])
                low[u]=dfn[v];
    }
    if(dfn[u]==low[u]){
        mycount++;
        int j;
        do{
            j=stack[top--];
            instack[j]=0;
        }while(j!=u);
    }
}
void solve(){
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
}


int main()
{
    while(cin>>n>>m && (n || m)){
        memset(head,-1,sizeof(head));
        memset(instack,0,sizeof(instack));
        num=mycount=index=top=0;
        int a,b;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            addEdge(a,b);
        }
        solve();
        //cout<<mycount<<endl;
        if(mycount>1)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}

