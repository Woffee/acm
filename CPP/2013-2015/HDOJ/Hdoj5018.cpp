//Hdoj 5018-Revenge of Fibonacci（模拟）
//WA原因见14行
//data:2014.10.28
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int CASE;
	double a,b,c;
	scanf("%d",&CASE);
	while(CASE--){
		scanf("%lf %lf %lf",&a,&b,&c);
		if(c==a || c==b){printf("Yes\n");continue;} 
		bool ok=false;
		double i=a,j=b,t=a+b;
		while(t<=c){
			//printf("%.0lf ",t );
			if(t==c){
				printf("Yes\n");
				ok=true;
				break;
			}
			a=b;
			b=t;
			t=a+b;
		}
		if(!ok)printf("No\n");

	}
	return 0;
}