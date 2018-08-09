//À´Ô´ÍøÉÏ
#include<stdio.h>
#include<string.h>
int next[10005];
int s[1000005],p[10005];
int n,m;
void getNext(int p[])
{
    int i=0,j=-1,len=m-1;
    next[0]=-1;
    while(i<len)
    {
        if(j==-1||p[i]==p[j])
        {
            i++,j++;
            next[i]=j;
        }
        else j=next[j];
    }
}
int kmp(int n,int m)
{
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(j==-1||s[i]==p[j])
            i++,j++;
        else j=next[j];
    }
    if(j==m)return i-j+1;
    else return -1;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
            scanf("%d",&s[i]);
        for(j=0; j<m; j++)
            scanf("%d",&p[j]);
        getNext(p);
        printf("%d\n",kmp(n,m));
    }
    return 0;
}
