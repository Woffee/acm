#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

int low[10010],dfn[10010];
int SPFNumber[50010];//�����������������ȥ�����ֳɶ�����ͨ��
bool boo[50010];//Ⱦɫ��� ����Ƿ���ջ��
int id[50010] ;// ���  ����  ��һ����ͨ��
int id_un[10005] ;//(����ͼ)���  ����  ��һ��˫��ͨ��
int degree[10005] ;// ����洢֮����� �Ķ�

int deep;//��ͼ�����е㰴�ձ���˳���ţ�ÿ����ı�Ų��ؼ� 
int bridge;//���ŵ����� 
int scc;// ��ͨ��֧�ĸ���
int m ,n;//n �ڵ�����m ����
stack<int> z ;
//�ڽӱ� 
int start[10005],test=0;// start���൱�� head
int tail;//��Ӧ�ߵĿ����±�
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

//�������ѵı�Ƿ������� 
void tarjan(int u,int father)
{
	z.push(u) ;    
	int son;
	//����һ��û�б�ǵ��µ�      
	boo[u] = true;
     low[u] = dfn[u] = id_un[u] = ++deep;
     //��ʼ��lowֵΪ��ǰ���depֵ 
     for (int i = start[u] ; i != -1 ; i = edge[i].next)
     {
         son = edge[i].point;

         //�õ㲻�ܷ��ʸ��׽ڵ㣬�������š��������Ե��lowֵ������ڸ��׽ڵ��dep 
         //if (son == father) continue; // ���� �� , ��ǿ��ͨ��֧��ʱ�� ����仰ע�͵�


         //���̽�����ĵ��Ѿ�����ǣ����������ǽ�������� 
		 if(!dfn[son])
		 {
			 //���̽�����ĵ�û�б���ǣ�����һ����һ���µ�          
			 tarjan(son,u);
			 //�ö��ӵ��lowֵ�����Լ���lowֵ�����ӵ����������������ȣ��Լ�Ҳ������ 
			 low[u] = low[u]<low[son]?low[u]:low[son];
			 //�жϸ 
			 if (low[son] >= dfn[u]) SPFNumber[u] ++;
			 //�ж��� 
			 if (low[son] > dfn[u]) bridge ++;
		 }else if (boo[son])
		 {
              low[u] = low[u]<dfn[son]?low[u]:dfn[son];
              //continue;
		 }
//		  low[u] = low[u]<dfn[son]?low[u]:dfn[son];//������ �ŵ�ʱ���õ�(��Ӱ�������),��������ͼ ǿ��ͨʱ ע�͵�
         id_un[u] = id_un[u]<id_un[son]?id_un[u]:id_un[son];
     }
	 
	 if(low[u] == dfn[u])//��������ô��Ҫ�����һ��ǿ��ͨ����      
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

bool map[5050][5050] ;// ��ֹ �ڽӱ�ʱ ���� ���ر�
