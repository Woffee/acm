/*
how many tables
²¢²é¼¯
*/
#include <iostream>
#include <queue>
#include <fstream>
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
  
	int num_of_case;
	cin>>num_of_case;
	int num,n;
        while( num_of_case-- )
        {
           cin>>num>>n;
           make_set( ); 
	   int a,b;
           for( int i=0 ; i<n ; i++ ){
                cin>>a>>b;
                union_set( a,b );
           }
           mymax = num;
           for( int i=1 ; i<=num ; i++ )
           if( parent[i] != i )
                mymax--;
           cout<<mymax<<endl;
        }        
        return 0;
}

