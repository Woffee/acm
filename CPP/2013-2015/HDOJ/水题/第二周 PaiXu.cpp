/*HENU第二周练习题目1003
Title:排序
Sample Input
0051231232050775

Sample Output
0 77 12312320

WF原创
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cmath>
using namespace std;
char yuan[1005];
int  num[1005];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b; 
}

int main()
{
	//freopen("input.txt","r",stdin);
	while(cin>>yuan)
	{
		memset(num,0,1005);
		int len=strlen(yuan);
		int index_num=0;
		for(int i=len-1;i>=0;--i)
		{
			if(yuan[i]!='5')
			{
				int j=1;int temp;
				while(yuan[i]!='5'&&i>=0)
				{
					temp=(int)(yuan[i]-'0')*j;
				    num[index_num]+=temp;
				    --i;j*=10;
				}
				++index_num;
			}
		}
		qsort(num,index_num, sizeof(num[0]),cmp);
		for(int i = 0;i < index_num-1; i++)
            printf("%d ",num[i]);
        printf("%d\n",num[index_num-1]);
	}	
	//fclose(stdin);
	return 0;
}