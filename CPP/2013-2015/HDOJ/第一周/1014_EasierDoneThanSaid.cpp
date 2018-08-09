#include<iostream>
#include<string>
int rule1=0,rule2=1,rule3=1;
using namespace std;
string str;
int is_yuan(int i)
{
    if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
        return 1;
    return 0;
}
int doit()
{

    while(1)
    {
        if(str.find('a')!=string::npos)
            break;
        if(str.find('e')!=string::npos)
            break;
        if(str.find('i')!=string::npos)
            break;
        if(str.find('o')!=string::npos)
            break;
        if(str.find('u')!=string::npos)
            break;
        return 0;
    }
    if(str.length()==1)return 1;
    for(int i=0; i<str.length()-2; i++)
        if(is_yuan(i)==is_yuan(i+1) && is_yuan(i)==is_yuan(i+2))
            return 0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]==str[i+1])
        {
            if(str[i]=='e'||str[i]=='o')
                break;
            else
                return 0;
        }
    }
    return 1;
}
int main()
{
    int rule1=0,rule2=1,rule3=0;
    while(cin>>str)
    {
        if(str=="end")return 0;
        if(doit())cout<<"<"<<str<<"> is acceptable."<<endl;
        else cout<<"<"<<str<<"> is not acceptable."<<endl;
    }
}
