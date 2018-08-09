/*
类似ACM的 比赛排名
2014.8.30
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
#include <time.h>      
using namespace std; 
struct S{
	string name;
	char numberame[10];
	int num;
	int time;
};
S s[200];

int cmp(const S &a,const S &b)  
{  
     if (a.num == b.num)  
     return a.time < b.time ? 1 : 0;  
     else return a.num > b.num ? 1 : 0;  
}  
int main()
{
	int number,lost_time;
	string str;
	int player=0;
	cin>>number>>lost_time;
	while(cin>>str){
		s[player].name=str;
		s[player].num=0;
		s[player].time=0;
		for(int i=1;i<=number;i++){
			string data;
			cin>>data;
			if(data[0]=='-' || data[0]=='0')
				continue;
			s[player].num++;
			int len=data.length();

			int a=0,b=0;  //例如 输入"101(3)" ,经过下面for循环,a=101,b=3
			for(int j=0;j<len;j++){
				if(data[j]!='(')
					a=a*10+data[j]-'0';
				else {
					for(int k=j+1;k<len;k++){
						if(data[k]==')')
							break;
						b=b*10+data[k]-'0';
					}
					break;
				}
			}

			s[player].time +=(a+b*lost_time);
		}
		player++;
	}
	sort(s,s+player,cmp);
	for(int i=0;i<player;i++){
		
		int temp=s[i].name.length();
		for(int j=0;j<temp;j++){
			s[i].numberame[j]=s[i].name[j];
		}
		printf("%-10s %2d %4d\n", s[i].numberame, s[i].num, s[i].time);

	}
}