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
