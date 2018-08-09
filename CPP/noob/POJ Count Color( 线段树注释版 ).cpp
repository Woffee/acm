/*
Count Color
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 8388		Accepted: 2351
Description

Chosen Problem Solving and Program design as an optional course, you are required to solve all kinds of problems. Here, we get a new problem. 

There is a very long board with length L centimeter, L is a positive integer, so we can evenly divide the board into L segments, and they are labeled by 1, 2, ... L from left to right, each is 1 centimeter long. Now we have to color the board - one segment with only one color. We can do following two operations on the board: 

1. "C A B C" Color the board from segment A to segment B with color C. 
2. "P A B" Output the number of different colors painted between segment A and segment B (including). 

In our daily life, we have very few words to describe a color (red, green, blue, yellow…), so you may assume that the total number of different colors T is very small. To make it simple, we express the names of colors as color 1, color 2, ... color T. At the beginning, the board was painted in color 1. Now the rest of problem is left to your. 
Input

First line of input contains L (1 <= L <= 100000), T (1 <= T <= 30) and O (1 <= O <= 100000). Here O denotes the number of operations. Following O lines, each contains "C A B C" or "P A B" (here A, B, C are integers, and A may be larger than B) as an operation defined previously.
Output

Ouput results of the output operation in order, each line contains a number.
Sample Input

2 2 4
C 1 1 2
P 1 2
C 2 2 2
P 1 2
Sample Output

2
1
Source

POJ Monthly--2006.03.26,dodo
*/
//北大2777线段树注释版
#include <stdio.h>
#include <string.h>
#define LC(x) (x<<1)// 2*x 计算左子树idx
#define RC(x) (x<<1|1)//2*x+1 计算右子树idx
struct Tree
{
	int left;
	int right;
	int cover;      //cover记录颜色  
}tree[270000];
int l,t,o,arr[31];//arr数组存储
char c;
void build(int left,int right,int idx)//建树函数，left为线段左坐标，right为线段右坐标，idx为在数组存储的位置下标
{
	int mid;
	tree[idx].left=left;
	tree[idx].right=right;
	tree[idx].cover=-1;
	if(left==right)//表示到达叶子节点
		return ;
	mid=(left+right)>>1;//取线段中点
	build(left,mid,LC(idx));//构建左半线段
	build(mid+1,right,RC(idx));//构建右半线段
}

void insert(int left,int right,int idx,int color)
{
	int mid;
	if(tree[idx].left>=left&&tree[idx].right<=right)//找到对应的区间(赋上颜色值)
	{
		tree[idx].cover=color;
		return ;
	}
	if(tree[idx].left!=tree[idx].right)//如果不是叶子节点
	{
		if(tree[idx].cover!=-1)//若该线段已有颜色值，则将左右孩子的颜色cover赋值为父节点idx的cover(避免子区间的颜色丢失)
		{
			tree[RC(idx)].cover=tree[LC(idx)].cover=tree[idx].cover;
			tree[idx].cover=-1;//然后将父节点idx的cover赋值为-1(即表示没有涂色)
		}

		//之后便又是对区间的判断啊。。。

		mid=(tree[idx].left+tree[idx].right)>>1;
		if(right<=mid)
			insert(left,right,LC(idx),color);
		else if(left>mid)
			insert(left,right,RC(idx),color);
		else
		{
			insert(left,mid,LC(idx),color);
			insert(mid+1,right,RC(idx),color);
		}
	}
}
void count(int left,int right,int idx)
{
	if(tree[idx].cover!=-1)
	{
		arr[tree[idx].cover]=1;//若该线段已经有颜色值，就把对应颜色的arr[]值置为1
		return ;
	}
	if(tree[idx].left!=tree[idx].right)//就是还没有到达叶子节点
	{
		int mid=(tree[idx].left+tree[idx].right)>>1;

		//判断查找的区间是在mid的左边、右边，还是横跨mid

		if(right<=mid)	//左边		
			count(left,right,LC(idx));

		else if(left>mid)	//右边
			count(left,right,RC(idx));
		else  //横跨mid
		{
			count(left,mid,LC(idx));
			count(mid+1,right,RC(idx));
		}
	}
}
int main()
{
	int x,y,z,ans,i;
	while(scanf("%d%d%d",&l,&t,&o)!=EOF)
	{
		build(1,l,1);
		tree[1].cover=1;//初始化是整个长度都是图上1这种颜色
		while(o--)
		{
			getchar();//消除换行符
			c=getchar();//接收操作类型"C"还是"P"
			if(c=='C')
			{
				scanf("%d%d%d",&x,&y,&z);
				if(x<=y)//谁也某说x一定大于y
				{
					insert(x,y,1,z);
				}
				else
				{
					insert(y,x,1,z);
				}
			}
			else
			{
				scanf("%d%d",&x,&y);
				memset(arr,0,sizeof(arr));
				ans=0;
				if(x<=y)//谁也某说x一定大于y
				{
					count(x,y,1);
				}
				else
				{
					count(y,x,1);
				}
				for(i=1;i<31;++i)
				{
					if(arr[i]) ++ans;//对颜色数组进行遍历，因为用到的第i种颜色对应的arr[i]==1
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}

