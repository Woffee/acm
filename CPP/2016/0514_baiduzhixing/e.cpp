/*
Problem :
Status  :

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

struct node
{
    string name;
    int l,r;
} var[50005];

struct node2
{
    int num;
    int varid[50];
    bool flag;
} p[1005];

map<string,int>mp;

bool iskong(int l1,int r1,int l2,int r2)
{
    if( l2>r1 || l1>r2 )return 1;
    return 0;
}

int main()
{
    //freopen("in_e.txt","r",stdin);
    string str;
    int n;
    cin>>n;
    getchar();
    int id = 1;
    for(int ii=0; ii<n; ii++)
    {
        getline(cin,str);
        //cout<<str<<endl;
        int i=0,j,len = str.length();
        p[ii].num=0;
        p[ii].flag=false;

        while(i<len)
        {
            while(i<len && str[i]==' ' )i++;
            if( isalpha(str[i]) )
            {
                //获取变量名
                j=i+1;
                while(j<len && isalpha(str[j]) )++j;
                var[id].name = str.substr(i,j-i);
                i=j;

                //获取运算符
                int ops=0;
                while(i<len && str[i]==' ' )i++;
                if( str[i]=='<' && str[i+1]!='=' )
                {
                    ops=1;
                    i++;
                }
                else if( str[i]=='>' && str[i+1]!='=' )
                {
                    ops=2;
                    i++;
                }
                else if( str[i]=='<' && str[i+1]=='=' )
                {
                    ops=3;
                    i+=2;
                }
                else if( str[i]=='>' && str[i+1]=='=' )
                {
                    ops=4;
                    i+=2;
                }
                else if( str[i]=='=' && str[i+1]=='=' )
                {
                    ops=5;
                    i+=2;
                }

                //获取数字
                int num=0;
                while(i<len && str[i]==' ')i++;
                if( isdigit(str[i]) )
                {
                    num = str[i]-'0';
                    j=i+1;
                    while(j<len && isdigit(str[j]) )
                    {
                        num = num*10 + str[j] - '0';
                        j++;
                    }
                    i=j;
                }

                //处理
                switch(ops)
                {
                case 1: //<
                    var[id].l = -10000;
                    var[id].r = num-1;
                    break;
                case 2: //>
                    var[id].l = num+1;
                    var[id].r = 10000;
                    break;
                case 3: //<=
                    var[id].l = -10000;
                    var[id].r = num;
                    break;
                case 4: //>=
                    var[id].l = num;
                    var[id].r = 10000;
                    break;
                case 5: //==
                    var[id].l = num;
                    var[id].r = num;
                    break;
                }

                //判断这个条件是否为空
                //printf("dangqian num:%d\n",p[ii].num);
                for(int t=0; t<p[ii].num; t++)
                {
                    int tid = p[ii].varid[t];
                    //cout<<"name1:"<<var[id].name<<" name2:"<<var[tid].name<<endl;
                    if( var[id].name == var[tid].name && iskong(var[tid].l,var[tid].r,var[id].l,var[id].r) )
                    {
                        p[ii].flag=1;
                        //printf("debug\n");
                    }else
                    {
                        var[id].l = max( var[id].l , var[tid].l );
                        var[tid].l = var[id].l;
                        var[id].r = min( var[id].r , var[tid].r );
                        var[tid].r = var[id].r;
                    }
                }


                //处理完毕
                //cout<<name<<" ops=="<<ops<<" num=="<<num<<" l=="<<var[id].l<<" r=="<<var[id].r<<" flag=="<<p[ii].flag<<endl;

                p[ii].varid[ p[ii].num++]=id;
                id++;

                while(i<len && str[i]==' ')i++;
                if( i<len && str[i]==',' )
                {
                    i++;
                }

            }
            else i++;
        }

        if( p[ii].flag )
        {
            cout<<"unique"<<endl;
            continue;
        }

        bool isUnique=true;
        bool first = 1;

        for(int jj=0; jj<ii; ++jj)
        {
            bool isThisOk =1;
            if( p[jj].flag )continue;
            else
            {
                for(int k1 = 0; k1<p[ii].num; k1++)
                {
                    for(int k2 = 0; k2<p[jj].num; k2++)
                    {
                        if(!isThisOk )break;
                        int tid1 = p[ii].varid[k1];
                        int tid2 = p[jj].varid[k2];

                        //printf("[%d,%d] [%d,%d]\n",var[tid1].l,var[tid1].r,var[tid2].l,var[tid2].r);
                        //cout<<"name1:"<<var[tid1].name<<" name2:"<<var[tid2].name<<endl;
                        if( var[tid1].name == var[tid2].name && iskong(var[tid1].l,var[tid1].r,var[tid2].l,var[tid2].r) )
                        {
                            isThisOk=0;
                            //printf("ok\n");
                            break;
                        }
                    }
                }
            }

            if( isThisOk )
            {
                isUnique=false;
                if(first)first=0;
                else cout<<" ";
                cout<<jj+1;
            }

        }
        if( isUnique )cout<<"unique"<<endl;
        else cout<<endl;

        //cout<<endl;
    }
    return 0;
    return 0;
}

