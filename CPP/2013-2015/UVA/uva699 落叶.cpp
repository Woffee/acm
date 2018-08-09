/*
	uva699: The Falling Leaves 
	http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=19244
	Originality and succeeded the first time.
	2014.10.14
*/

#include <cstdio>
#include <cstring>
int a[80];

void f(int p){
	int num;
	scanf("%d",&num);
	if(num!=-1){
		a[p-1]+=num;
		f(p-1);
	}
	scanf("%d",&num);
	if(num!=-1){
		a[p+1]+=num;
		f(p+1);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	int num,t=1;
	while( scanf("%d",&num) && num!=-1){
		for(int i=0;i<80;++i)a[i]=0;
		a[40]=num;
		f(40);

		//output
		bool first=true;
		printf("Case %d:\n",t++);
		for(int i=0;i<80;++i){
			if(a[i]!=0){
				if(first){printf("%d",a[i] );first=false;}
				else printf(" %d",a[i] );
			}
		}
		printf("\n\n");
	}
	//fclose(stdin);
	//printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );
}