/*
��������    ��ʿ����
http://acm.hdu.edu.cn/showproblem.php?pid=2897
���⣺����Ӳ�ҵĸ�����ÿ������ȡ������ȡp�������ȡq�������ȡ���˾�����

������˵�ǲ��ģ����Ǳ���˿�����ͻ�û�����ģ���֪���������������Ǿ�ͬ��������

�ⷨ������Ҫ���ж����ʣ�µ�Ӳ�ҵĸ��������ˣ����������Ƿ��б�ʤ�Ĳ��ԣ����Ե��ֵ�A��ʣ�µ�Ӳ��0<=K<=p��Aʤ

����Bʤ��

�ó���������

N = (p+q)*r+k

Aʤ�������һ��AȡT�������Ժ�ÿ��BȡX����A��ȡ(p+q-x)����ʣ�µ�ֻҪq<K<=p����A��ʤ

Bʤ��ȡ���Ǽ���Aÿ��ȡx,��B��ÿ��ȡ(p+q-x)����ʣ�µ�ֻҪ0<K<=p����B��ʤ

2014.9.1
*/
 
#include <algorithm>   //sort()
#include <iostream>
#include <iomanip>     //
#include <fstream>     //
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <time.h>      //
using namespace std; 

int main()
{
    int n,p,q;
    while(~scanf("%d%d%d",&n,&p,&q))
    {
        n = n%(p+q);
        if(n>0 && n<=p)
        printf("LOST\n");
        else
        printf("WIN\n");
    }

    return 0;
}
