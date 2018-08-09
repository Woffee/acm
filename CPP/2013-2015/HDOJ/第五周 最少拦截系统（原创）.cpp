/*
最少拦截系统

http://acm.hdu.edu.cn/showproblem.php?pid=1257

大意：
	给你导弹依此飞来的高度，每个导弹拦截系统拦截的高度不能大于上一个导弹高度
	输出拦截所有导弹最少要配备多少套这种导弹拦截系统.

思路:
	首先存储所有导弹高度，然后依次遍历每个高度
	对于每个导弹高度，向后找比它高度小的导弹，那么这些导弹都可以用一个系统拦截，
	并把它们标记为0，遍历的时候略过它们
*/
#include <iostream>
using namespace std;

int hight[1000];
int vis[1000];

int main()
{
    int n;
    while(cin >> n)
    {
        int i,cnt = 0;
        for(i = 0; i<n; i++)
        {
            cin >> hight[i];
            vis[i] = 1;
        }
        for(i = 0; i<n; i++)
        {
            if(vis[i])
            {
                int flag = hight[i];
                for(int j = i+1; j<n; j++)
                {
                    if(vis[j] && hight[j]<=flag)
                    {
                        vis[j] = 0;
                        flag =hight[j];
                    }
                }
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
