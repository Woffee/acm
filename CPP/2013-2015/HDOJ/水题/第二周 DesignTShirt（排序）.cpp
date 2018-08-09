/*
Design T-Shirt 

Sample Input
3 6 4
2 2.5 5 1 3 4
5 1 3.5 2 2 2
1 1 1 1 1 10
3 3 2
1 2 3
2 3 1
3 1 2

Sample Output
6 5 3 1
2 1

参考
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct element
{
	int id;
	double score;
}ele[10000];
int cmp(const void *a,const void *b){  
    return (*(element*)a).score>(*(element*)b).score?-1:1;  
}  
int cmp2(const void *a,const void *b){  
    return (*(element*)b).id-(*(element*)a).id;  
}  
int main()
{
	freopen("input.txt","r",stdin);
	int N,M,K;
	double x;
	while(cin>>N>>M>>K)
	{
		for(int i=0;i<10000;i++){  
            ele[i].score=0;  
            ele[i].id=i+1;  
        }  
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<M;++j)
				{cin>>x;ele[j].score+=x;}
		}
		//paixu
			qsort(ele,M,sizeof(ele[0]),cmp);  //先排满意度
	        qsort(ele,K,sizeof(ele[0]),cmp2);//再排序号
			for(int i=0;i<K-1;++i)
			{
				cout<<ele[i].id<<" ";
			}
			cout<<ele[K-1].id<<endl;
		
	}
	fclose(stdin);
	return 0;
}