/*
×î´ó×Ó¾ØÕó

2014.8.27
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std; 

const int INF=0x3f3f3f3f;

int m,n,x,y;
int a[1111][1111];
int b[1111];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d%d%d",&m,&n,&x,&y);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        }

        int maxn=-100;
        for(int i=1;i<=m;i++)
        {
            int xx=i+x-1;
            	if(xx>n) continue;

            memset(b,0,sizeof(b));

            for(int j=1;j<=n;j++)
	            for(int k=i;k<=xx;k++)
	            {
	                b[j]+=a[k][j];
	            }
 
            for(int j=1;j<=n;j++)
            {
               int yy=j+y-1;
                   if(yy>n) continue;
               int sum=0;
               for(int k=j;k<=yy;k++)
               {
                   sum+=b[k];
               }

               maxn=max(maxn,sum);

            }

        }

        printf("%d\n",maxn);

    }
}


/*#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;

int num[1001][1001];
int dp[1001][1001];
int m,n,x,y;
int ca(int a,int b){
	int sum=0;
	for(int i=a;i<a+x;i++){
		for(int j=b;j<b+y;j++){
			sum+=num[i][j];
		}
	}
	return sum;
}
int main()
{
	int t;
	
	cin>>t;
	while(t--){
		cin>>m>>n>>x>>y;
		int max=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&num[i][j]);
			}
		}
		for(int i=1;i<=(m-x+1);i++){
			for(int j=1;j<=(n-y+1);j++){
				dp[i][j]=ca(i,j);
				if(dp[i][j]>max)
					max=dp[i][j];
			}
		}
		cout<<max<<endl;
	}
}*/