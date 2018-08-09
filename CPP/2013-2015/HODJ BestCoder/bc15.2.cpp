//bestcoder15.1002
//2014.10.26
//你猜我为什么WA了9次？第八行的“DIV”打成了“DIV1”。 TAT
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char op[][5]={" ","ADD","SUB","DIV","MUL","MOVE","SET"};
void pt(int a){
	char x[6]="00000";
	int index=4;
	do{
		x[index--]='0'+ a%2;
		a=a/2;
	}while(a!=0);
	for(int i=0;i<5;++i)cout<<x[i];
}
void f1(int i,int a,int b){
	printf("0");
	pt(i);pt(a);pt(b);
	printf("\n");
}

void f2(char * a){
	int i = 0;  
    while(i<16){  
        if(a[i]!='0' && a[i]!='1'){
        	printf("Error!\n");
        	return ;
        }  
        i++;
    }
    if(i!=16){
    	printf("Error!\n");  
		return;
    }
	int n1=0,n2=0,n3=0;
	if(a[5]=='1')n1+=1;
	if(a[4]=='1')n1+=2;
	if(a[3]=='1')n1+=4;
	if(a[2]=='1')n1+=8;
	if(a[1]=='1')n1+=16;
	if(a[0]=='1')n1+=32;

	if(a[10]=='1')n2+=1;
	if(a[9]=='1')n2+=2;
	if(a[8]=='1')n2+=4;
	if(a[7]=='1')n2+=8;
	if(a[6]=='1')n2+=16;

	if(a[15]=='1')n3+=1;
	if(a[14]=='1')n3+=2;
	if(a[13]=='1')n3+=4;
	if(a[12]=='1')n3+=8;
	if(a[11]=='1')n3+=16;

	if(n1==0||n1>6||n2==0||(n3==0&&n1!=6||n3!=0&&n1==6)){
		printf("Error!\n");  
		return;
	}
	printf("%s",op[n1] );
	if(n1!=6)
		printf(" R%d,R%d\n",n2,n3 );
	else
		printf(" R%d\n",n2 );
}

int main()
{
	int type,a,b;
	while(cin>>type){

		char opera[20];

		if(type){
			cin>>opera;
			int i;
			for(i=1;i<=6;++i)
				if(strcmp(opera,op[i])==0)break;
			a=b=0;
			if(i<6)
				scanf(" R%d,R%d",&a,&b);
			else
				scanf(" R%d",&a);
			f1(i,a,b);
		}
		else{
			cin>>opera;
			f2(opera);
		}
	}
}