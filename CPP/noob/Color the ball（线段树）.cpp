#include<iostream>
#include<stdio.h>
using namespace std;
#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
struct Seg_tree
{
	int left;
	int right;
	int yanse;
	int calmid()
	{
		return (left+right)>>1;
	}
}tree[300000];
int arr[100010];

void build(int left,int right,int idx)
{
	tree[idx].left=left;
	tree[idx].right=right;
	tree[idx].yanse=0;
	if(left==right)
		return;
	int mid=tree[idx].calmid();
	build(left,mid,LC(idx));
	build(mid+1,right,RC(idx));
}

int update(int left,int right,int idx)
{
	if(left<=tree[idx].left && tree[idx].right <= right)
	{
		tree[idx].yanse++;
		return 0;
	}
	if(tree[idx].yanse>0)
	{
		tree[LC(idx)].yanse+=tree[idx].yanse;
		tree[RC(idx)].yanse+=tree[idx].yanse;
		tree[idx].yanse=0;
	}
	int mid=tree[idx].calmid();
	if(right<=mid)
		update(left,right,LC(idx));
	else if(left>mid)
		update(left,right,RC(idx));
	else
	{
		update(left,mid,LC(idx));
		update(mid+1,right,RC(idx));
	}
}

void question(int idx)
{
	if(tree[idx].left==tree[idx].right)
	{
		arr[tree[idx].left]=tree[idx].yanse;
		return ;
	}
	tree[LC(idx)].yanse+=tree[idx].yanse;
	tree[RC(idx)].yanse+=tree[idx].yanse;
	question(LC(idx));
	question(RC(idx));
}

int main()
{
	int N;
	while(scanf("%d",&N)==1)
	{
		if(N==0)
			break;
		build(1,N,1);
		int a,b,i;

		/*for(i=1;i<=6;i++)
			cout<<tree[i].left<<" "<<tree[i].right<<" "<<tree[i].yanse<<endl;*/
		for(i=1;i<=N;i++)
		{
			scanf("%d%d",&a,&b);
			update(a,b,1);
			/*for(int ij=1;ij<=6;ij++)
				cout<<tree[ij].left<<" "<<tree[ij].right<<" "<<tree[ij].yanse<<endl;
			cout<<endl;*/
		}
		question(1);
		for(i=1;i<N;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("%d\n",arr[i]);
	}
}
