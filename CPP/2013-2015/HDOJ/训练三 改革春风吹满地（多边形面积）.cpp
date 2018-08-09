/*
改革春风吹满地 多边形面积
*/
#include <iostream>
#include <cstdio>
using namespace std;

int T, N, x[3], y[3];
double sumx, sumy, sumarea;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        sumx = sumy = sumarea = 0.0;
        N=n;
        
        cin>>x[0]>>y[0]>>x[1]>>y[1];//scanf("%d %d %d %d", x, y, x+1, y+1);
        N -= 2;
        while(N--)
        {
            cin>>x[2]>>y[2];//scanf("%d %d", x+2, y+2);
            //求新添加的三角形的面积
            double s = ((x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0])) / 2.0;
            //求∑x[i]*s[i]和∑y[i]*s[i]
            sumx += ((x[0] + x[1] + x[2]) * s);
            sumy += ((y[0] + y[1] + y[2]) * s);
            //求总面积
            sumarea += s;

            x[1] = x[2];
            y[1] = y[2];
        }
        printf("%.1lf\n", sumarea);
    }
    return 0;
}
