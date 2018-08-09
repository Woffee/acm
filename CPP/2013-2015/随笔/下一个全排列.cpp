#include <algorithm>   
#include <iostream>
#include <iomanip>     
#include <fstream>     
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <time.h>      
using namespace std; 

int main()
{
	int n,p[10];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	sort(p,p+n);
	do{
		for(int i=0;i<n;i++)
			printf("%d ",p[i]);
		printf("\n");
	}while(next_permutation(p,p+n)); //求下一个排列

	printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );
	return 0;
}