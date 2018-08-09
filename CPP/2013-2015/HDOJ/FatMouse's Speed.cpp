/*
FatMouse's Speed ß∞‹
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

struct mouse
{
	int No;
	int fat;
	int speed;
	int pre;
	int num;
};
mouse mou[1010];

int cmp(const mouse &a,const mouse &b)  
{  
     if (a.fat == b.fat)  
     return a.speed > b.speed ? 1 : 0; 
     else return   a.fat < b.fat ?1:0;
} 
void print(int n)
{
	if(mou[n].pre==0)
		return;
	print(mou[n].pre);
	cout<<mou[n].No<<endl;
	//cout<<" "<<mou[n].fat<<" "<<mou[n].speed<<" pre:"<<mou[n].pre<<endl;
}
int main()
{
	int n=1;
	while(scanf("%d%d",&mou[n].fat,&mou[n].speed)!=EOF)
	{
		mou[n].No=n;
		mou[n].num=1;
		mou[n].pre=0;
		n++;
	}
	n--;
	sort(mou+1,mou+n,cmp);
	/*for (int i = 1; i <= n; i++)
	{
		printf("%d  %d  %d\n",mou[i].fat,mou[i].speed,mou[i].No);
	}*/
	for(int i=1;i<=n;i++){
		mou[i].pre=1;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(mou[i].speed>mou[j].speed && mou[i].fat<mou[j].fat){
				mou[j].pre=i;
				mou[j].num=mou[i].num+1;
			}
		}
	}
	int max=-1;
	int ttt;
	for(int i=1;i<=n;i++){
		//cout<<"mou   "<<mou[i].No<<mou[i].num<<" "<<mou[i].pre<<endl;
		if(mou[i].num>max){
			max=mou[i].num;
			ttt=mou[i].No;
		}
	}
	cout<<max<<endl;
	//cout<<"ttt "<<ttt<<endl;
	print(ttt);
/*	int temp;
	int len;
	int max=1;
	mouse lmou[n];
	for(int i=1;i<n;i++)
	{	
		temp=0;
		len=1;
		for(int j=1;j<i;j++)
		{
			if(temp<mou[j].speed)
				{
					temp=mou[j].speed;
					lmou[len]=mou[j];
					len++;
					
				}
			if(len>max)
				max=len;
		}
	}
	for(int i=1;i<=len;i++)
		cout<<lmou[i].No<<endl;
	cout<<max;*/
	return 0;
}