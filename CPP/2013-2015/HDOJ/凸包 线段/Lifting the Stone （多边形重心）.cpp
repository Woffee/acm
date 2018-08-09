/*
Lifting the Stone 

计算多边形重心方法：
（1）划分多边形为三角形：
以多边形的一个顶点V为源点（V可取输入的第一个顶点），作连结V与所有非相邻顶点的线段，即将原N边形或分为（N-2）个三角形；
（2）求每个三角形的重心和面积：
设某个三角形的重心为G（cx，cy），顶点坐标分别为A1（x1，y1），A2（x2，y2），A3（x3，y3），则有cx = (x1 + x2 + x3)/3.同理求得cy。求面积的方法是s =  ( (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) ) / 2，当A1,A2,A3顺时针排列时取-，否则取正（此定理不证）。事实上，在求每个三角形时不需要辨别正负，之后有方法抵消负号，见下述。
（3）求原多边形的重心：
公式：cx = (∑ cx[i]*s[i]) / ∑s[i];  cy = (∑ cy[i]*s[i] ) / ∑s[i];其中（cx[i], cy[i]）, s[i]分别是所划分的第i个三角形的重心坐标和面积。由题“ connect the points in the given order”知每个s[i]的正负号相同，故而∑ cx[i]*s[i]能与∑s[i]消号，所以根本不需要在第（2）步判断每个s[i]的正负。另外，在（2）中求每个重心坐标时要除以3，实际上不需要在求每个三角形坐标时都除以3，只需要求出∑ cx[i]*s[i]后一次性除以3即可。即是多边形重心坐标变为：cx = (∑ cx[i]*s[i]) / （3*∑s[i]）;  cy = (∑ cy[i]*s[i] ) / （3*∑s[i]）;

总结：
每个三角形重心：cx = x1 + x2 + x3；cy同理。
每个三角形面积：s =  ( (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) ) / 2；
多边形重心：cx = (∑ cx[i]*s[i]) / （3*∑s[i]）;  cy = (∑ cy[i]*s[i] ) / （3*∑s[i]）;
*/

#include <iostream>
#include <cstdio>
using namespace std;

int T, N, x[3], y[3];
double sumx, sumy, sumarea;

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        sumx = sumy = sumarea = 0.0;
        scanf("%d", &N);
        
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
        printf("%.2lf %.2lf\n", sumx / sumarea / 3, sumy / sumarea / 3);
    }
    return 0;
}
