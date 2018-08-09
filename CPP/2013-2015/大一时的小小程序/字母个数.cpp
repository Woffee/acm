#include<iostream>
#include <string>
using namespace std ;
int main()
{
	string Str;
	char ch ;
	int i=0,num=0;
	getline(cin , Str );
	for ( i=0;i<Str.length();i++ )
	{
		  if ( Str[i] >='a' && Str[i]<='z'  ||  Str[i] >='A' && Str[i]<='Z' )
			  num++;
	}
	cout << "×ÖÄ¸¸öÊý£º" << num <<endl ; 
	return 0;
}
