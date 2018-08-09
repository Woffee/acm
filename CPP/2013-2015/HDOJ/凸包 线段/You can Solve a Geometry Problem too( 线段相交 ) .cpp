/*You can Solve a Geometry Problem too 
Time Limit : 2000/1000ms (Java/Other)   Memory Limit : 65536/32768K (Java/Other)
Total Submission(s) : 10   Accepted Submission(s) : 6
Font: Times New Roman | Verdana | Georgia 
Font Size: ← →
Problem Description
Many geometry（几何）problems were designed in the ACM/ICPC. And now, I also prepare a geometry problem for this final exam. According to the experience of many ACMers, geometry problems are always much trouble, but this problem is very easy, after all we are now attending an exam, not a contest :)
Give you N (1<=N<=100) segments（线段）, please output the number of all intersections（交点）. You should count repeatedly if M (M>2) segments intersect at the same point.

Note:
You can assume that two segments would not intersect at more than one point. 

Input
Input contains multiple test cases. Each test case contains a integer N (1=N<=100) in a line first, and then N lines follow. Each line describes one segment with four float values x1, y1, x2, y2 which are coordinates of the segment’s ending. 
A test case starting with 0 terminates the input and this test case is not to be processed.

Output
For each case, print the number of intersections, and one line one case.

Sample Input
2
0.00 0.00 1.00 1.00
0.00 1.00 1.00 0.00
3
0.00 0.00 1.00 1.00
0.00 1.00 1.00 0.000
0.00 0.00 1.00 0.00
0

Sample Output
1
3

Author
lcy */

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
bool judge(point p1,point p2,point p3,point p4) //判断线段p1p2和p3p4是否相交   
{  
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

int main()  
{   
    int n,count; //n是线段的数量，，count代表交点数
    while(cin>>n && n)  
    {  
        memset(seg,0,sizeof(seg));
        count = 0;  
        for(int i=1; i<=n; i++)  //get data
        {
        	cin>>seg[i].begin.x>>seg[i].begin.y>>seg[i].end.x>>seg[i].end.y;
        }  
        for(int i=1; i<n; i++)  
        {
            for(int j=i+1; j<=n; j++)  
            {  
                if(judge(seg[i].begin,seg[i].end,seg[j].begin,seg[j].end))  
                {  
                    count++;  
                }  
            }  
        }
        cout<<count<<endl;
    }  
    return 0;  
}
