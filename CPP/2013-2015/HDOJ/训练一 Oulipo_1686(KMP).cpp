/*
Oulipo KMP
    string 类型的输入要加<string>头文件
    不然C++编译不过
    另：此题G++ Time Limited Exceeded
*/

#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int next[10005];
int wordlen,textlen;
int ans;

void getnext(string word)
{
    int i=0;
    int j=-1;
    next[0]=-1;
    while(i<wordlen)
    {
        if(j==-1||word[i]==word[j])
        {
            ++i;++j;
            if(word[i]!=word[j])
                next[i]=j;
            else
                next[i]=next[j];
        }
        else
            j=next[j];
    }
}

void kmp(string text,string word)
{

    int i=0;
    int j=0;
    while(i<textlen&&j<wordlen)
    {
        if(j==-1||text[i]==word[j])
        {
            ++i;++j;
        }
        else
        {
             j=next[j];
        }
        if(j==wordlen)
        {
            ++ans;
            j=next[j];
        }
    }
}
int main()
{
    string word,text;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>word;
        cin>>text;
        ans=0;
        wordlen = word.length();
        textlen = text.length();
        getnext(word);
        kmp(text,word);
        cout<<ans<<endl;
    }

    return 0;
}
