/*
畅通工程再续
*/

#include <iostream>
#include <cmath>

using namespace std;

#define MAX 100010
#define LEN 105

double dis[LEN];
double map[LEN][LEN];
bool vis[LEN];

//点的结构体
struct Point{
	double x;
	double y;
};

//初始化
void init(){
	int i,j;
	for(i=0;i<LEN;i++){
		for(j=0;j<LEN;j++){
			if(i==j) map[i][j]=0;   //对a[][]进行初始化，一般都要；
			map[i][j]=MAX;
		}
	}
}

//计算两点距离
double length(Point a,Point b){
	double len;
	len=sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
	return len;

}

//prim算法
double prim(int n){
	int i,j,min,pos;
	double sum=0;
	memset(vis,false,sizeof(vis));

	//初始化
	for(i=1;i<=n;i++){
		dis[i]=map[1][i];
	}

	//从1开始
	vis[1]=true;
	dis[1]=MAX;

	//找到权值最小点并记录下位置
	for(i=1;i<n;i++){
		min=MAX;

		for(j=1;j<=n;j++){
			if(!vis[j] && dis[j]<min){
				min=dis[j];
				pos=j;
			}
		}	
		if(min==MAX){
			return -1;

		}
		sum+=dis[pos];//加上权值
		vis[pos]=true;

		//更新权值
		for(j=1;j<=n;j++){
			if(!vis[j] && dis[j]>map[pos][j]){
				dis[j]=map[pos][j];
			}
		}
	}	
	return sum;
}

int main(){
	Point p[105];
    int i,j,n,nCase;
	cin>>nCase;
	double result;//总价
	while(nCase--){
		cin>>n;
		init();	//初始化
		for(i=1;i<=n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		for(i=1;i<n;i++){
            for(j=i+1;j<=n;j++){  
				double len;
                len=length(p[i],p[j]);
				if(len>=10 && len<=1000){//长度有限制
					map[i][j]=map[j][i]=100*len;//要*100  
				}  
            }
		}
		result=prim(n);
		if(result==-1){
			cout<<"oh!"<<endl;
		}
		else{
			printf("%.1lf\n",result);
		}
	}
	 return 0;
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
#define MAX 100010  

int t,c,x,y;
int i,j,k;
bool vis[101];
double dis[101];
double map[101][101];
bool flag;
struct Point{
	int x,y;
}e[101];

//初始化  
void init(){  
	flag=true;
    int i,j;  
    for(i=1;i<=c;i++){  
        for(j=1;j<=c;j++){  
            if(i==j) map[i][j]=0;    
            map[i][j]=MAX;  
        }  
    }  
}  

//计算两点距离  
double len(Point a,Point b){  
    double ans;  
    ans=sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));  
    return ans;  
} 

//Prim
double prim(int n){
	int min,pos;
	double sum=0;
	memset (vis,false,sizeof(vis));

	//init
	for(i=1;i<=n;i++){
		dis[i]=map[1][i];
	}

	//start from 1
	vis[1]=true;
	dis[1]=MAX;
	
	//find min and Record the position
	for(i=1;i<n;i++){
		min=MAX;
		for(j=1;j<=n;j++){
			if(!vis[j] && dis[j]<min){
				min=dis[j];
				pos=j;
			}
		}
		if(min==MAX)
			return -1;
		sum+=dis[pos];
		vis[pos]=true;

		//update
		for(j=1;j<=n;j++){
			if(!vis[j] && dis[j]>map[pos][j])
				dis[j]=map[pos][j];
		}
	}
	return sum;
}
int main()
{
	cin>>t;
	while(t--){
		cin>>c;
		for(i=1;i<=c;i++){
			cin>>e[i].x>>e[i].y;
		}
		double temp;
		for(i=1;i<=c;i++){
			for(j=i+1;j<=c;j++){
				temp=len(e[i],e[j]);
				if(temp>=10 && temp<=1000){ 
                    map[i][j]=map[j][i]=100*temp; 
                }    
			}
		}
		double result;
		result = prim(c);
		if(result==-1 || result ==0)
			cout<<"oh!"<<endl;
		else 
			printf("%.1lf\n",result); 

	}	
	return 0;
}*/