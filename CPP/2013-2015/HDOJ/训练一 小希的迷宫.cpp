/*
Сϣ���Թ� ���鼯
http://acm.hdu.edu.cn/showproblem.php?pid=1272

��ȡһϵ�з���ţ�ÿһ�Է���Ŵ������ǿ�����ͨ����������������䶼���Ի��ൽ����ֻ��һ��·�ߣ����Yes

ÿ�ζ�ȡ�����ڵ㣬����������ڵ�ĸ��ڵ㲻��ͬ��ͬ���Ҽ���ֻ��һ�������Yes��

2014.8.25
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
const int MAX=100001;
int parent[MAX];
bool vis[MAX];
bool flag;
/*
int find(int x)
{
    if(x!=parent[x])
        parent[x]=find(parent[x]);
    return parent[x];
}*/
int find(int x) //����ύ����ע�͵�find�������� Runtime Error (STACK_OVERFLOW)
{
    while(x!=parent[x])
    x = parent[x] ;
    return x ;
}
void union_set(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
    {
        parent[x]=y;
    }
    else flag=false;
}

int main()
{
    int a,b;
    int i;
    while(cin>>a>>b && a!=-1 && b!=-1){
        if(a==0 && b==0){       //���ֻ��0 0 Ҳ�ǿ��Ե�
            cout<<"Yes"<<endl;
            continue;
        }
        int num=0;
        flag=true;
        for(i=1; i<MAX; i++){
            parent[i]=i;
            vis[i]=0;
        }

        union_set(a,b);
        vis[a]=vis[b]=1;
        while(cin>>a>>b && a!=0 && b!=0){
            union_set(a,b);
            vis[a]=vis[b]=1;
        }
        for(i=1; i<MAX; i++){
            if(parent[i]==i && vis[i])
                num++;
        }
        if(flag && num==1)
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
}