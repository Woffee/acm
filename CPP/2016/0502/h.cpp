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

map<string,int>a;

struct player
{
    char lang[5];
    char name[25];
    int score;
} p1,p2;


int getn(char ch[],char cmd1[])
{
    switch(ch[0])
    {
    case 'c':
        if(cmd1[0]=='K')return 0;
        else if(cmd1[0]=='N' )return 1;
        else if(cmd1[0]=='P')return 2;
        break;
    case 'f':
        if(cmd1[0]=='P')return 0;
        else if(cmd1[0]=='C' )return 1;
        else if(cmd1[0]=='F')return 2;
        break;
    case 'd':
        if(cmd1[0]=='S' && cmd1[1]=='t')return 0;
        else if(cmd1[0]=='S' && cmd1[1]== 'c')return 1;
        else if(cmd1[0]=='P')return 2;
        break;
    case 'h':
        if(cmd1[0]=='K')return 0;
        else if(cmd1[0]=='O' )return 1;
        else if(cmd1[0]=='P')return 2;
        break;
    case 'i':
        if(cmd1[0]=='S')return 0;
        else if(cmd1[0]=='F' )return 1;
        else if(cmd1[0]=='C')return 2;
        else if( cmd1[0]=='R' && cmd1[0]=='o' )return 0;
        else if ( cmd1[0]=='R' && cmd1[0]=='e' )return 2;
        break;
    case 'j':
        if(cmd1[0]=='G')return 0;
        else if(cmd1[0]=='C' )return 1;
        else if(cmd1[0]=='P')return 2;
        break;
    case 'p':
        if(cmd1[0]=='K')return 0;
        else if(cmd1[0]=='N' )return 1;
        else if(cmd1[0]=='P')return 2;
        break;
    case 'e':

        if( ch[1]=='n' )
        {
            if(cmd1[0]=='R')return 0;
            else if(cmd1[0]=='S' )return 1;
            else if(cmd1[0]=='P')return 2;
        }
        else
        {
            if(cmd1[0]=='P' && cmd1[1]=='i')return 0;
            else if(cmd1[0]=='P' && cmd1[1]=='a')return 2;
            else if(cmd1[0]=='T' )return 1;
        }
        break;
    }
    return -1;
}

string cmd1,cmd2;
int get(string s)
{
    return a[s];
}

void play()
{
    int n1,n2;
    n1 = get(cmd1);
    n2 = get(cmd2);

    if(n1==n2)return;

    if(n1==0)
    {
        if(n2==1)p1.score++;
        else p2.score++;
    }
    else if(n1==1)
    {
        if(n2==2)p1.score++;
        else p2.score++;
    }
    else
    {
        if(n2==0)p1.score++;
        else p2.score++;
    }
}



int main()
{
    //freopen("in.txt","r",stdin);
    a["Kamen"]=0;
    a["Nuzky"]=1;
    a["Papir"]=2;
    a["Rock"]=0;
    a["Scissors"]=1;
    a["Paper"]=2;
    a["Pierre"]=0;
    a["Ciseaux"]=1;
    a["Feuille"]=2;
    a["Stein"]=0;
    a["Schere"]=1;
    a["Papier"]=2;
    a["Ko"]=0;
    a["Koe"]=0;
    a["Ollo"]=1;
    a["Olloo"]=1;
    a["Papir"]=2;
    a["Sasso"]=0;
    a["Roccia"]=0;
    a["Forbice"]=1;
    a["Carta"]=2;
    a["Rete"]=2;
    a["Guu"]=0;
    a["Choki"]=1;
    a["Paa"]=2;
    a["Kamien"]=0;
    a["Nozyce"]=1;
    a["Papier"]=2;
    a["Piedra"]=0;
    a["Tijera"]=1;
    a["Papel"]=2;

    int tt=1;
    while( scanf("%s %s",&p1.lang,&p1.name)!=EOF )
    {
        scanf("%s %s",&p2.lang,&p2.name);
        p1.score=0;
        p2.score=0;
        //printf("p1:%s %s\np2:%s %s\n",p1.lang,p1.name,p2.lang,p2.name);


        while( cin>>cmd1)
        {
            if(cmd1[0]=='-' || cmd1[0]=='.')break;

            //scanf("%s",&cmd2);
            cin>>cmd2;

            //printf("%s %s\n",cmd1,cmd2);
            play();
        }

        printf("Game #%d:\n",tt++);
        if(p1.score==1)
        {
            printf("%s: 1 point\n",p1.name);
        }
        else printf("%s: %d points\n",p1.name,p1.score);

        if(p2.score==1)
        {
            printf("%s: 1 point\n",p2.name);
        }
        else printf("%s: %d points\n",p2.name,p2.score);

        if(p1.score==p2.score)
        {
            printf("TIED GAME\n");
        }
        else if(p1.score > p2.score)
        {
            printf("WINNER: %s\n",p1.name);
        }
        else
        {
            printf("WINNER: %s\n",p2.name);
        }
        printf("\n");
        if(cmd1[0]=='.')break;
    }

    return 0;
}
