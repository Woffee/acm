/*
连连看
wf原创
Time Limit: 20000/10000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 17244    Accepted Submission(s): 4472


Problem Description
“连连看”相信很多人都玩过。没玩过也没关系，下面我给大家介绍一下游戏规则：在一个棋盘中，放了很多的棋子。如果某两个相同的棋子，可以通过一条线连起来（这条线不能经过其它棋子），而且线的转折次数不超过两次，那么这两个棋子就可以在棋盘上消去。不好意思，由于我以前没有玩过连连看，咨询了同学的意见，连线不能从外面绕过去的，但事实上这是错的。现在已经酿成大祸，就只能将错就错了，连线不能从外围绕过。
玩家鼠标先后点击两块棋子，试图将他们消去，然后游戏的后台判断这两个方格能不能消去。现在你的任务就是写这个后台程序。

 

Input
输入数据有多组。每组数据的第一行有两个正整数n,m(0<n<=1000,0<m<1000)，分别表示棋盘的行数与列数。在接下来的n行中，每行有m个非负整数描述棋盘的方格分布。0表示这个位置没有棋子，正整数表示棋子的类型。接下来的一行是一个正整数q(0<q<50)，表示下面有q次询问。在接下来的q行里，每行有四个正整数x1,y1,x2,y2,表示询问第x1行y1列的棋子与第x2行y2列的棋子能不能消去。n=0,m=0时，输入结束。
注意：询问之间无先后关系，都是针对当前状态的！

 

Output
每一组输入数据对应一行输出。如果能消去则输出"YES",不能则输出"NO"。

 

Sample Input
3 4
1 2 3 4
0 0 0 0
4 3 2 1
4
1 1 3 4
1 1 2 4
1 1 3 3
2 1 2 4
3 4
0 1 4 3
0 2 4 1
0 0 0 0
2
1 1 2 4
1 3 2 3
0 0
 

Sample Output
YES
NO
NO
NO
NO
YES
 

Author
lwg
 

Recommend
We have carefully selected several similar problems for you:  1180 1072 1016 1026 1010 

*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
int q,x1,y1,x2,y2,m,n;
const int N=1001;
int a[N][N];
bool line(int x1,int y1,int x2,int y2)
{
    int s,e;
    bool temp;
    if(x1==x2)
    {
        s=y1<y2?y1:y2;
        e=y1>y2?y1:y2;
        temp=true;
        for(int i=s+1;i<=e-1;i++)
            if(a[x1][i]!=0)temp=false;
        return temp;
    }
    if(y1==y2)
    {
        s=x1<x2?x1:x2;
        e=x1>x2?x1:x2;
        temp=true;
        for(int i=s+1;i<=e-1;i++)
            if(a[i][y1]!=0)temp=false;
        return temp;
    }
    return false;
}
bool check2(int x1,int y1,int x2,int y2)//二级检验，即一个折点
{
    if(x1!=x2 && y1!=y2)//只有一个拐点时，两点肯定不能同行同列
    {
        if(a[x2][y1]==0)
        {
            if(line(x1,y1,x2,y1)&&line(x2,y2,x2,y1))
                {
                    return true;
                }
        }
        if(a[x1][y2]==0)
        {
            if(line(x1,y1,x1,y2)&&line(x2,y2,x1,y2))
			{
                return true;
			}
        }
        return false;
    }
    return false;
}
int ok(int x1,int y1,int x2,int y2)
{
    if (x1==x2 && y1==y2) return 0;          //is right 
    if (a[x1][y1]==0 || a[x2][y2]==0) return 0;
    if (a[x1][y1]!=a[x2][y2]) return 0;

    if(line(x1,y1,x2,y2))return 1;//一级检验
    if(check2(x1,y1,x2,y2))return 1;//二级检验
    int px,py;                   //以下四个循环为三级检验，即两个折点，
                                //依次判断与点x1,y1能直线连接的点能否与x2,y2构成一个折点连接

    for(px=x1-1,py=y1;px>0;--px)//如果这个点不符合上述条件，判断上面的点 //up
    {
        if(a[px][py]==0)
        {
            if(check2(px,py,x2,y2))
            	return 1;
        }
        else {
            		break;
             }
    }
    for(px=x1+1,py=y1;px<m;++px)//down
    {
        if(a[px][py]==0)
        {
            if(check2(px,py,x2,y2))return 1;
        }
        else {
            		break;
             }
    }
    for(px=x1,py=y1-1;py>0;--py)//left
    {
        if(a[px][py]==0)
        {
            if(check2(px,py,x2,y2))return 1;
        }
        else {
            		break;
             }
    }
    for(px=x1,py=y1+1;py<n;++py)//right
    {
        if(a[px][py]==0)
        {
            if(check2(px,py,x2,y2))return 1;
        }
        else {
            		break;
             }
    }
    return 0;       
}

int main()
{
    while (scanf("%d%d",&m,&n)!=EOF)
    {
         if (0==m && 0==n) break;
         for (int i=1;i<=m;i++)//get 
             for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);

         scanf("%d",&q);
         while (q--)
         {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

            if ( ok(x1,y1,x2,y2) ) printf("YES\n");
             else printf("NO\n");
         }
    }
	return 0;
}
