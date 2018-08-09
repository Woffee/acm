#include<stdio.h>
#include <iostream>
#include <queue>
#include <fstream>
#include <string.h>
using namespace std;
int time=0,i,n,rp,mymax[10]={0};
struct job
{
    int pos;
    int rp;
};
int getmax()
{
    int j;
    for(j=9;j>=0;j--)
    {
	if(mymax[j])
	    return j;
    }
    return 0;
}
    
queue<job>qjob;
job jo;


int main()
{
    scanf("%d",&n);
    while(n--)
    {
	int num,index;
	scanf("%d %d",&num,&index);
	for(i=0;i<9;i++)mymax[i]=0;  
	for(i=0;i<num;i++)//get data
	{
	    scanf("%d",&jo.rp);
	    jo.pos=i;
	    mymax[jo.rp]++;
	    qjob.push(jo);
	}
	while(1)
	{
	    if(qjob.front().rp==getmax())
	    {
		if(qjob.front().pos==index){time++;break;}
		qjob.pop();
		mymax[getmax()]--;
		time++;
	    }
	    else {qjob.push(qjob.front());qjob.pop();}
	}
	printf("%d\n",time);
	time=0;
	while(!qjob.empty())qjob.pop();
	  
    }
    return 0;
}


