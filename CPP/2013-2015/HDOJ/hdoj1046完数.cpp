#include <stdio.h>
#include <iostream>
using namespace std;
int isPerfect(int x)
{ 
    int flag=1,s=0,i;
    for(i=1;i<x;i++)
    {
        if(x%i==0)
            s=s+i;
    }
    if(s==x)  
        flag=1;
    else
        flag=0;
    return(flag); 
}
int main()
{
    int t,a,b,num=0;
    scanf("%d",&t);
    while(t--){
    	num=0;
    	scanf("%d %d",&a,&b);
    	if(a>b){
    		int temp;
    		temp=a;
    		a=b;
    		b=temp;
    	}
    	for(int i=a;i<=b;i++){
    		if(isPerfect(i)){
    			num++;
    		}
    	}
    	printf("%d\n",num );
    }
    return 0;
}
