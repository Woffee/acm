#include <iostream>  
   
using namespace std;  
struct point  
{  
    double x,y;  
};  
struct segment  
{  
    point begin,end;  
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
int main()  
{  
    int n,count;  
    segment seg[101];  
    while(cin>>n&&n)  
    {  
        count = 0;  
        for(int i=1; i<=n; i++)  
        {  
            cin>>seg[i].begin.x>>seg[i].begin.y>>seg[i].end.x>>seg[i].end.y;  
        }  
        for(int i=1; i<n; i++)  
            for(int j=i+1; j<=n; j++)  
            {  
                if(judge(seg[i].begin,seg[i].end,seg[j].begin,seg[j].end))  
                {  
                    count++;  
                }  
            }  
            cout<<count<<endl;  
    }  
    return 0;  
}
