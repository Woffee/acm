#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

int low[10010],dfn[10010];
int SPFNumber[50010];//求割顶被求次数，用来求去掉割顶后分成多少联通块
bool boo[50010];//染色标记 标记是否在栈中
int id[50010] ;// 结点  属于  哪一个连通块
int id_un[10005] ;//(有向图)结点  属于  哪一个双连通块
int degree[10005] ;// 计算存储之后的树 的度

int deep;//给图上所有点按照遍历顺序标号，每个点的标号不重记 
int bridge;//求桥的数量 
int scc;// 连通分支的个数
int m ,n;//n 节点数，m 边数
stack<int> z ;
//邻接表 
int start[10005],test=0;// start就相当于 head
int tail;//对应边的开辟下标
struct Edge
{
    int point;
    int next;

}edge[50010];

void init()
{
	scc = 0 ;
	tail = 0;
	memset(start,-1,sizeof(start));
	memset(SPFNumber,-1,sizeof(SPFNumber));
	memset(boo,false,sizeof(boo));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(id,0,sizeof(id));
}
void insert(int a,int b)
{
     
     edge[tail].point = b;
     edge[tail].next = start[a];
     start[a] = tail;
	 tail++;
}

//基于深搜的标记法求割顶与桥 
void tarjan(int u,int father)
{
	z.push(u) ;    
	int son;
	//发现一个没有标记的新点      
	boo[u] = true;
     low[u] = dfn[u] = id_un[u] = ++deep;
     //初始化low值为当前点的dep值 
     for (int i = start[u] ; i != -1 ; i = edge[i].next)
     {
         son = edge[i].point;

         //让点不能访问父亲节点，用于求桥。否则所以点的low值都会等于父亲节点的dep 
         //if (son == father) continue; // 用于 桥 , 在强连通分支的时候 把这句话注释掉


         //如果探索到的点已经被标记，则它可能是较早的祖先 
		 if(!dfn[son])
		 {
			 //如果探索到的点没有被标记，则它一定是一个新点          
			 tarjan(son,u);
			 //用儿子点的low值更新自己的low值，儿子点能碰到的最早祖先，自己也能碰到 
			 low[u] = low[u]<low[son]?low[u]:low[son];
			 //判断割顶 
			 if (low[son] >= dfn[u]) SPFNumber[u] ++;
			 //判断桥 
			 if (low[son] > dfn[u]) bridge ++;
		 }else if (boo[son])
		 {
              low[u] = low[u]<dfn[son]?low[u]:dfn[son];
              //continue;
		 }
//		  low[u] = low[u]<dfn[son]?low[u]:dfn[son];//用于求 桥的时候用到(不影响割点情况),用于有向图 强连通时 注释掉
         id_un[u] = id_un[u]<id_un[son]?id_un[u]:id_un[son];
     }
	 
	 if(low[u] == dfn[u])//如果相等那么就要输出这一个强连通分量      
	 {  
		 scc ++ ;
		 int temp ;
		 do  
		 { 
			 temp = z.top() ;
			 //dist[temp]=0;  
			 boo[temp] = false ;
			 z.pop() ;
			 id[temp] = scc ;
		 }  
		 while(temp != u);  
	 }
}

bool map[5050][5050] ;// 防止 邻接表时 输入 有重边
