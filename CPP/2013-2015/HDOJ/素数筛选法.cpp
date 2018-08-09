  
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
const int MAXN=1000000;
bool isprime[MAXN+5];
using namespace std; 

int main()
{
	int n,ans;
	for(int i=0;i<MAXN;i+=2){
		isprime[i]=false;
		isprime[i+1]=true;
	}
	isprime[2]=true;
	for(int i=3; i<=sqrt(MAXN); i+=2 ){   
		if(isprime[i])
          for(int j=i+i; j<=MAXN; j+=i ) isprime[j]=false;
    }
	for(int i=1;i<100;i++)if(isprime[i])cout<<i<<" ";
		cout<<endl;
	while(cin>>n){
		ans=0;
		for(int i=1;i<=n/2;i++){
			if(n%i==0 && isprime[n/i]){
				ans=i;
				break;
			}
		}
		printf("%d\n",ans );
	}
}