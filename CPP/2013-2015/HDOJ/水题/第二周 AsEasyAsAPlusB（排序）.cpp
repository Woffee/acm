/*HENU第二周练习题目1006
Title:As easy as A + B
Sample Input
2
3 2 1 3
9 1 4 7 2 5 8 3 6 9

Sample Output
1 2 3
1 2 3 4 5 6 7 8 9
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int cmp(const void *a,const void *b)
{
 return *(int *)a-*(int *)b; 
}

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	while(n--)
	{
		int Num[1005];
		int m;
		cin>>m;
		int i=0;
		while(i<m)
		{
			cin>>Num[i];
			++i;
		}
		qsort(Num,m, sizeof(Num[0]),cmp);
		i=0;
		while(i<m)
		{
			if(i!=m-1)
				cout<<Num[i]<<" ";
			else
				cout<<Num[i]<<endl;
			++i;
		}
	}
	fclose(stdin);
	return 0;
}

