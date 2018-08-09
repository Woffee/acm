/*
	uva127: "Accordian" Patience
	model by http://blog.csdn.net/mobius_strip/article/details/12622859
	2014.10.14
*/

#include <cstring>
#include <iostream>  
#include <cstdlib>  
#include <cstdio>  
using namespace std;  
  
char Card[54][54][3];  
int  Top[54];  
int  sum;//The number of merged

int match(char*a,char*b){
	return (a[0]==b[0] || a[1]==b[1]);
}

int is_move(int now,int s){
	//if can move s
	int count =0,temp=now;
	while(temp>=0 && count<s){
		if(Top[--temp]>=0)count++;
	}
	//is equal
	if(temp>=0 && match(Card[now][Top[now]],Card[temp][Top[temp]])){
		Top[temp]++;
		Card[temp][Top[temp]][0]=Card[now][Top[now]][0];
		Card[temp][Top[temp]][1]=Card[now][Top[now]][1];
		if(--Top[now]<0)sum++;
		return temp;
	}
	else return -1;
}
int main()
{
	freopen("in.txt","r",stdin);
	while ( scanf("%s",Card[0][0]) && Card[0][0][0] != '#' ){

		//init
		//memset(Card,0,sizeof(Card)); //Can not memset !
		for(int i=0;i<52;++i)
			Top[i]=0;
		sum=0;

		//get data
		for(int i=1;i<52;i++)
			scanf("%s",Card[i][0]);
		
		//doit
		for(int now=1;now<52;){
			while(Top[now]<0)now++;
			//move left 3
			int temp=is_move(now,3);
			if(temp>=0)
				now=temp;
			else{
				//move left 1
				temp=is_move(now,1);
				if(temp>=0)now=temp;
				else now++;
			}
		}

		//output
		if(52-sum==1)
			printf("1 pile remaining:");
		else
			printf("%d piles remaining:",52-sum);

		for(int i=0;i<52;++i){
			if(Top[i]>=0)printf(" %d",Top[i]+1 );
		}
		printf("\n");
	}
	return 0;
	//fclose(stdin);
	//printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );
}