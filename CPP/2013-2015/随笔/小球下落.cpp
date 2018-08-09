//小球下落
//题目来源：算法竞赛入门经典p99
//这个代码运算量太大，带有技巧的代码键p101
#include <algorithm>   
#include <iostream>
#include <iomanip>     
#include <fstream>     
#include <cstring>
#include <string>
#include <cstdio>
#include <time.h>
#include <cmath>
#include <stack>
#include <map>  
    
using namespace std; 

int tree[1<<20];
int main()
{
	int d,n;
	int maxn;
	while(scanf("%d%d",&d,&n)==2){
		memset(tree,0,sizeof(tree));
		maxn=(1<<d)-1;
		int step=1;
		for (int i = 0; i <n; ++i)
		{
			step=1;
			for(;;){
				
				tree[step] = !tree[step];
				if( !tree[step] )
					step=step*2+1;
				else
					step*=2;
				if(step>maxn)break;

			}
			
		}
		printf("%d\n", step/2);//出界之前的step

	}
	printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );
	
}