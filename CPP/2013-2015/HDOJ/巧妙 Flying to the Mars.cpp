/*
Flying to the Mars
http://acm.hdu.edu.cn/showproblem.php?pid=1800
很巧妙的一种方法
2014.8.27
*/
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int i;
        map<int,int> mp;
        int max=INT_MIN;
        for(i=0;i<n;i++)
        {
            int level;
            scanf("%d",&level);
            mp[level]++;
            if(mp[level]>max)
            {
                max=mp[level];                     
            }
        }
        printf("%d\n",max);
    }
    return 0;
} 