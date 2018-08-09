/*
Identity Card
一次性通过。。。真简单
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	int t;
	cin>>t;
	while(t--){
		cin>>str;
		cout<<"He/She is from ";
		if(str[0]=='3' && str[1]=='3')
			cout<<"Zhejiang";
		else if(str[0]=='1' && str[1]=='1')
			cout<<"Beijing";
		else if(str[0]=='7' && str[1]=='1')
			cout<<"Taiwan";
		else if(str[0]=='8' && str[1]=='1')
			cout<<"Hong Kong";
		else if(str[0]=='8' && str[1]=='2')
			cout<<"Macao";
		else if(str[0]=='5' && str[1]=='4')
			cout<<"Tibet";
		else if(str[0]=='2' && str[1]=='1')
			cout<<"Liaoning";
		else 
			cout<<"Shanghai";

		cout<<",and his/her birthday is on ";
		cout<<str[10]<<str[11]<<","<<str[12]<<str[13]<<","<<str[6]<<str[7]<<str[8]<<str[9];
		cout<<" based on the table."<<endl;
	}
}