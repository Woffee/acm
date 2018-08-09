/*
Problem :
Status  :AC

By wf,
*/

#include "algorithm"
#include "iostream"
#include "cstring"
#include "cstdio"
#include "string"
#include "stack"
#include "cmath"
#include "queue"
#include "set"
#include "map"

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

typedef long long ll;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1e5+5;

#define MAX 26
struct Trie
{
    Trie *next[MAX];
    int v;   //根据需要变化

    Trie()
    {
        v=0;
        for(int i=0; i<MAX; ++i)
        {
            next[i]=NULL;
        }
    }
};

Trie *root;

void Insert(char *str)
{
    //printf("insert:%s\n",str);
    int len = strlen(str);
    Trie *p = root, *q;
    for(int i=0; i<len; ++i)
    {
        int id = str[i]-'a';
        if(p->next[id]==NULL)
            p->next[id]=new Trie();
        p=p->next[id];
        p->v++;
    }
}
int Search(char *str)
{
    //printf("search:%s\n",str);
    int len = strlen(str);
    Trie *p = root;
    for(int i=0; i<len; ++i)
    {
        int id = str[i]-'a';
        p = p->next[id];
        if(p == NULL)   //若为空集，表示不存以此为前缀的串
            return 0;

        //printf("%c v:%d\n",str[i],p->v);
    }
    return p->v;
}
void Delete(char * str)
{
    //printf("delete:%s\n",str);
    int len = strlen(str);

    //取删除单词的个数
    int num = Search(str);

    Trie *p = root;
    for(int i=0; i<len; ++i)
    {
        int id = str[i]-'a';
        p = p->next[id];
        if(p == NULL)   //若为空集，表示不存以此为前缀的串
            return ;
        //printf("->%c ",str[i]);
        p->v -= num;
        if(p->v ==0)
        {
            for(int i=0; i<26; ++i)
            {
                p->next[i]=NULL;
            }
            p=NULL;
            return;
        }
    }
    return ;
}



int main()
{
    //freopen("in_c.txt","r",stdin);
    int n;
    scanf("%d",&n);
    char cmd[20],str[5000];
    int len;
    root = new Trie();
    while(n--)
    {
        //cin>>cmd>>str;
        scanf("%s %s",&cmd,&str);
        switch( cmd[0] )
        {
        case 'i':
            Insert(str);
            break;
        case 'd':
            Delete(str);
            break;
        case 's':
            if( Search(str) )
            {
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
            break;
        }
    }

    return 0;
}
