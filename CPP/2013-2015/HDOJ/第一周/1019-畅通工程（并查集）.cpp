#include<iostream>
using namespace std;
int parent[1005],rank[1005],mymax;
void make_set()
{
	int i;
	for(i=1;i<1005;i++)
	{
		parent[i]=i;
		rank[i]=1;
	}
}
int find(int x)
{
	if(x!=parent[x])
		parent[x]=find(parent[x]);
	return parent[x];
}
void union_set(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y)
	{
	    --mymax;
		if(rank[x]<rank[y])
		{
			parent[x]=y;
			rank[y]+=rank[x];
		}
		else
		{
			parent[y]=x;
			rank[x]+=rank[y];
		}
	}
}
int main()
{
	int i,n,m,a,b;
	while(cin>>n>>m&&n)
	{
	    make_set();
	    mymax=n-1;
	    for(i=1;i<=m;i++)
	    {
	        cin>>a>>b;
	        union_set(a,b);
	    }
		cout<<mymax<<endl;
	}
	return 0;
}

