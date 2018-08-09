//2014.11.20
#include <iostream>
#include <cstring>
using namespace std;
int num[1005][300];
int main(){
	memset(num,0,sizeof num);
	num[1][0]=1;
	num[2][0]=1;
	
	for(int i=3;i<1001;i++){ 
	    for(int j=0;j<300;j++){  
            num[i][j]+=num[i-1][j]+num[i-2][j];  
            if(num[i][j]>=10){  
                num[i][j+1]=num[i][j]/10;  
                num[i][j]=num[i][j]%10;  
            }           
	    }  
	}
    int t,a;
    cin>>t;
    while(t--){
    	cin>>a;
    	//cout<<a<<":";
    	int flag=-1;
    	for(int i=250;i>=0;i--){
    		if(num[a][i]!=0){
    			flag=i;
    			break;
    		}
    	}
    	if(flag>=0){
    		//cout<<"flag "<<flag<<endl;
	    	while(flag>=0){
	    		cout<<num[a][flag];
	    		flag--;
	    	}
	    }
    	cout<<endl;
    }
}