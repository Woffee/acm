/*
uva537
WA经历:由于复制粘贴，忘记把P改成U及I。
已AC
*/
  
#include <fstream>     
#include <string.h>
#include <stdio.h>

char str[1000]; 
double P=0,U=0,I=0;
void f(const char *str){

	P=0;U=0;I=0;
	int len=strlen(str);

	for(int i=0;i<len;++i){

		if(str[i]=='='){
			int pos=i-1;//pos of P or U or I

			//search the number
			double num=0;
			double temp=1;
			i++;
			while( str[i]!='.' && str[i]>='0' && str[i]<='9' ){
				num=num*10+str[i]-'0';
				i++;
			}
			if(str[i]=='.'){
				i++;
				while(str[i]>='0' && str[i]<='9'){
					temp*=0.1;
					num+= temp * ( str[i]-'0' );
					i++;
				}
			}
			if(str[i]=='m')  
                num*=0.001;  
            if(str[i]=='k')  
                num*=1000;  
            if(str[i]=='M')  
                num*=1000000;  

            //P U I ?
            if(str[pos]=='P')P=num;
            else if(str[pos]=='U')U=num;
            else if(str[pos]=='I')I=num;
		}
	}
	//printf("P=%.2lf U=%.2lf I=%.2lf\n", P,U,I);
	if(P==0)printf("P=%.2lfW\n",1.0*U*I);
	if(U==0)printf("U=%.2lfV\n",1.0*P/I);
	if(I==0)printf("I=%.2lfA\n",1.0*P/U);
}
int main()
{
	freopen("in.txt","r",stdin);
    int n,i;
    scanf("%d%*c",&n);
    for(i=0;i<n;i++)
    {
        gets(str);
		printf("Problem #%d\n",i+1);
        f(str);
		printf("\n");
    }
    return 0;
	//freopen("in.txt","r",stdin);
	//printf("Time used = %.2lf s \n",(double)clock()/CLOCKS_PER_SEC );
}