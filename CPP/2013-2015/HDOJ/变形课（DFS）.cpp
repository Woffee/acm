/*
变形课（DFS）
http://acm.hdu.edu.cn/showproblem.php?pid=1181

Harry已经将他所会的所有咒语都列成了一个表,他想让你帮忙计算一下他是否能完成老师的作业,将一个B(ball)变成一个M(Mouse)
根据样例，Harry 可以念这个咒语:"big-got-them".

用数字表示字母，0-25对应A-Z
原创
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
bool ok=false;
int word[26][26]={0};//word[a][b]代表有一个单词是a...b,中间字母不用考虑
int vis[26]={0};// visited

void DFS(int start){
	//cout<<"dfs : "<<start<<endl;
	if(ok)return;
	if(start==12){ //12代表M
		cout << "Yes." << endl;
		ok=true;
		return;
	}
	for(int i=0;i<26;i++){
		if(word[start][i]==1 && !vis[i]){
			vis[i] = 1; //该节点已走过
			DFS(i);
			vis[i] = 0;//还原
		}
	}
	
}
int main()
{
	string str;
	char head,end;
	while(cin>>str){
		if(str[0]=='0'){
			DFS(1); //1代表B
			if(!ok)
				cout<<"No."<<endl;
			ok=false;
			memset(word,0,sizeof(word));
			memset(vis,0,sizeof(vis));
			continue;
		}
		int len=str.length();

		head=str[0];
		end=str[len-1];
		int h=head-'a';
		int e=end-'a';

		word[h][e]=1; //从h节点能够到e节点
	}
}