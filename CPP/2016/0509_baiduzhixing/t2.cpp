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

int t,key;
int len;
string pwd;



int main()
{
    freopen("in_2.txt","r",stdin);
    cin>>t;
    getchar();
    for(int tt = 1;tt<=t;++tt)
    {
        printf("Case #%d:\n",tt);

        getline(cin,pwd);
        cin>>key;
        getchar();

        len = pwd.length();

        //获取完整的行数、列数、以及剩余一行的个数
        int rows = len/key;
        int cols = key;

        int last = len%key;
        int allrows = rows;
        if(last)allrows ++;

        int flag = last;
        int index = 0;
        //printf("cols==%d,last==%d\n",cols,last);
        int printnum=0;
        for(int i=0;i<allrows;++i)
        {
            index = i;
            for(int j=0;j<last && index <len && printnum<len;++j)
            {
                printf("%c",pwd[index]);
                printnum++;
                index += allrows;
            }

            int num = cols - last;
            while(num-- && index <len && printnum<len)
            {
                printf("%c",pwd[index]);
                printnum++;
                index += rows;
            }
        }
        printf("\n");

    }
    return 0;
}


