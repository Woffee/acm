//题目：A Corrupt Mayor's Performance Art
//作者：宁波大学
/*
大意：把一面墙分成几段，“P 1 2 3”表示把1到2涂成“3”，“Q 1 5”询问从1到5有哪些颜色。
*/

#include<stdio.h>
#include<string.h>
typedef struct Node
{
    int s;
    int e;
    int c;
}node;
node v[200000],vv[200000],nn;
int color[33];
char str[10];
int main()
{
    int n,m,a,b,c,i,size,ssize,sum,num;
    char op;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        size=0;
        nn.s=1;
        nn.e=n;
        nn.c=2;
        v[size++]=nn;
        while(m--)
        {
            scanf("%s",str);
            if(str[0]=='Q')
            {
                scanf("%d%d",&a,&b);
                memset(color,0,sizeof(color));
                sum=0;
                for(i=0;i<size;i++)
                {
                    if(a>b)
                        break;
                    if(v[i].e>=a)
                    {
                        if(color[v[i].c]==0)
                            sum++;
                        color[v[i].c]=1;
                        a=v[i].e+1;
                    }
                }
                num=0;
                for(i=1;i<=30;i++)
                {
                    if(color[i]==1)
                    {
                        num++;
                        printf("%d",i);
                        if(num==sum)
                        {
                            printf("\n");
                            break;
                        }
                        else
                            printf(" ");
                    }
                }
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                ssize=0;
                for(i=0;i<size;i++)
                {
                    if(v[i].e<a)
                        vv[ssize++]=v[i];
                    else if(v[i].s>b)
                        vv[ssize++]=v[i];
                    else
                    {
                        if(v[i].s<a)
                        {
                            nn.s=v[i].s;
                            nn.e=a-1;
                            nn.c=v[i].c;
                            vv[ssize++]=nn;
                        }
                        if(b<v[i].e)
                        {
                            nn.s=a;
                            nn.e=b;
                            nn.c=c;
                            vv[ssize++]=nn;
                            nn.s=b+1;
                            nn.e=v[i].e;
                            nn.c=v[i].c;
                            vv[ssize++]=nn;
                        }
                        else if(b==v[i].e)
                        {
                            nn.s=a;
                            nn.e=b;
                            nn.c=c;
                            vv[ssize++]=nn;
                        }
                    }
                }
                for(i=0;i<ssize;i++)
                    v[i]=vv[i];
                size=ssize;
            }
        }
    }
    return 0;
}