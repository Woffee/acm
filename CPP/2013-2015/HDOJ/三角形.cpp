//1、BigNums；2、LCA；3、Shortest Path；4、Math Theory；
//5、Search；6、Sorting；7、Deduce；
//8、Dynamic Programming；9、Math
//2014.11.20
#include <iostream>
#include <cstring>
int num[10001];
using namespace std;

int main(){
	num[1]=2;
	for(int i=2;i<10001;i++){
		num[i]=num[i-1]+6*(i-1);
	}
	int t,a;
    cin>>t;
    while(t--){
    	cin>>a;
    	cout<<num[a]<<endl;
    }
}