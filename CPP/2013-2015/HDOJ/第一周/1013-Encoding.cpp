/*
Encoding

Sample Input
2
ABC
ABBCCC

Sample Output
ABC
A2B3C

*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i,sn;
    string str;
    cin>>n;
    while(n--)
    {
        cin>>str;
        sn=1;
        for(i=0; i<str.length(); i++)
        {
            if(str[i+1]!=str[i])
                cout<<str[i];
            else
            {
                while(str[i+1]==str[i])
                {
                    ++i;
                    ++sn;
                }
                cout<<sn<<str[i];
                sn=1;
            }
        }
        cout<<endl;
    }
}
