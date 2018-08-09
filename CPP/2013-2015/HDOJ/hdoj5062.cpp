#include <iostream>
#include <cstdio>
int num[]={1,9,18,54,90,174,258};
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",num[n] );
	}
}