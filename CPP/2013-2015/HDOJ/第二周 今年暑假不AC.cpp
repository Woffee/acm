#include <cstdio>
#include <algorithm>
using namespace std;
struct tv{
    int s,e;
}t[101];
bool cmp(tv a,tv b){  // ÉıĞò
    return (a.e-b.e)<0;
} 
int main(){
    int n;
    while(scanf("%d",&n) && n!=0 )
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&t[i].s,&t[i].e);
        }
        sort(t,t+n,cmp);
        int result=0,end=t[0].s;
        for(int i=0;i<n;i++)
        {
            if(t[i].s>=end)
            {
                result++;
                end=t[i].e;
            }
        }
        printf("%d\n",result);
    }    
    return 0;
}