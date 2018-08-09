/*
统计难题 字典树
*/
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

struct WordNode{
    //num可以表示一个字典树到此有多少相同前缀的数目，这里根据需要应当学会自由变化。
    int num ;
    //next是表示每层有多少种类的数，如果只是小写字母，则26即可，
    //若改为大小写字母，则是52，若再加上数字，则是62了，这里根据题意来确定。
    WordNode * nextNode[26];
};

WordNode wordNode[10000000];
int index ;
WordNode * ip ;

void insertNode(char str[11])
{
    ip = wordNode ;
    for(int i = 0; i < strlen(str);i ++)
    {
        if(ip->nextNode[str[i] - 'a'] != 0)
        {
            ip->nextNode[str[i] - 'a']->num ++ ;
        }
        else
        {
            index ++ ;
            ip->nextNode[str[i] - 'a'] = wordNode + index ;
            ip->nextNode[str[i] - 'a']->num = 1 ;
        }
        ip = ip->nextNode[str[i] - 'a'] ;
    }
    
}
int search(char str[11])
{
    ip = wordNode ;
    for(int  i = 0; i < strlen(str); i ++)
    {
        if(ip->nextNode[str[i] - 'a'] != NULL)
            ip = ip->nextNode[str[i] - 'a'] ;
        else
            return 0 ;
    }
    return ip->num ;

}
int main()
{
    char temp[11];
    
    while(gets(temp)) 
    {
        if(strlen(temp)==0)
            break;
        insertNode(temp) ;
    }

    while(gets(temp) != NULL)
    {
        cout<<search(temp)<<endl;
    }
    
    return 0;
}