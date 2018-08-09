/*
Pipe 
Time Limit : 1000/1000ms (Java/Other)   Memory Limit : 32768/32768K (Java/Other)
Total Submission(s) : 4   Accepted Submission(s) : 2
Font: Times New Roman | Verdana | Georgia 
Font Size: ← →
Problem Description
经过激烈的争夺，Lele终于把那块地从Yueyue的手里抢了回来。接下来，Lele要开始建造他的灌溉系统。

通过咨询Lele的好友——化学系的TT，Lele决定在田里挖出N条沟渠，每条沟渠输送一种肥料。

每条沟渠可以看作是一条折线，也就是一系列线段首尾连接而成(除了第一条线段开头和最后一条线段的结尾)。由于沟渠很细，你可以忽略掉它的宽度。

由于不同的肥料之间混合会发生化学反应，所以修建的沟渠与沟渠之间不能相交。

现在TT给Lele画了一些设计图，Lele请你判断一下设计图中的沟渠与沟渠之间是否有相交。

Input
本题目包含多组测试，请处理到文件结束(EOF)。
每组测试的第一行有一个正整数N(0<N<30)，表示管道的数目。接下来给出这N条管道的信息。
对于每条管道，第一行是一个正整数K(0<K<100)，表示这条管道是由K个端点组成。
接下来的K行给出这K个端点信息。每个端点占一行，用两个整数X和Y(0<X,Y<1000)分别表示这个端点的横坐标和纵坐标的值。

Output
对于每组测试，如果该测试管道与管道之间有相交的话，输出"Yes"，否则输出"No"。


Sample Input
2
2
0 0
1 1
2
0 1
1 0
2
2
0 0
1 1
2
1 0
2 1
2
3
0 0
1 1
2 1
2
2 0
3 0


Sample Output
Yes
No
No

Author
Linle 
Source
ACM程序设计期末考试——2008-01-02（3 教417） 
原创！！
*/

#include <iostream>     
#include <string.h>

using namespace std; 


struct point  
{  
    double x,y;  
};  
struct segment  
{  
    point begin,end;
    int father;  
};  
double min(double x,double y)  
{  
    return x<y?x:y;  
}  
double max(double x,double y)  
{  
    return x>y?x:y;  
}  
bool onsegment(point pi,point pj,point pk) //判断点pk是否在线段pi pj上   
{  
    if(min(pi.x,pj.x)<=pk.x&&pk.x<=max(pi.x,pj.x))  
    {  
        if(min(pi.y,pj.y)<=pk.y&&pk.y<=max(pi.y,pj.y))  
        {  
            return true;  
        }  
    }  
    return false;  
}  
double direction(point pi,point pj,point pk) //计算向量pkpi和向量pjpi的叉积   
{  
    return (pi.x-pk.x)*(pi.y-pj.y)-(pi.y-pk.y)*(pi.x-pj.x);  
}  
bool judge(point p1,point p2,point p3,point p4,int father1,int father2) //判断线段p1p2和p3p4是否相交   
{  
    if(father1==father2)
        return false;
    double d1 = direction(p3,p4,p1);  
    double d2 = direction(p3,p4,p2);  
    double d3 = direction(p1,p2,p3);  
    double d4 = direction(p1,p2,p4);  
    if(d1*d2<0&&d3*d4<0)  
        return true;  
    if(d1==0&&onsegment(p3,p4,p1))  
        return true;  
    if(d2==0&&onsegment(p3,p4,p2))  
        return true;  
    if(d3==0&&onsegment(p1,p2,p3))  
        return true;  
    if(d4==0&&onsegment(p1,p2,p4))  
        return true;  
    return false;  
}  

segment seg[3005];
point temp[101]; 

int main()  
{   
    int n,count; //n是管道的数量，管道里可能有折点，count代表交点数
    int nn;//nn 代表没有折点的线段的数量 
     
    while(cin>>n&&n)  
    {  
        memset(seg,0,sizeof(seg));
        memset(temp,0,sizeof(temp));
        nn=0;
        count = 0;  
        for(int k=1; k<=n; k++)  //get data
        {   
            int p_num;//number of points
            cin>>p_num;
            for(int j=1;j<=p_num;++j)
            {
                cin>>temp[j].x>>temp[j].y;
            }
            for(int i=1;i<p_num;++i)
            {
                ++nn;
                seg[nn].begin.x=temp[i].x;//temp后的下标是i ，原来我不小心写成nn，结果调试半天
                seg[nn].begin.y=temp[i].y;
                seg[nn].end.x=temp[i+1].x;
                seg[nn].end.y=temp[i+1].y;
                seg[nn].father=k;
            }
        }  
        for(int i=1; i<nn; i++)  
        {
            for(int j=i+1; j<=nn; j++)  
            {  
                if(judge(seg[i].begin,seg[i].end,seg[j].begin,seg[j].end,seg[i].father,seg[j].father))  
                {  
                    count++;  
                }  
            }  
        }
        if(count)cout<<"Yes"<<endl;  
        else cout<<"No"<<endl;
    }  
    return 0;  
}
