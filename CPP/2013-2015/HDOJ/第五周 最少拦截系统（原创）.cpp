/*
��������ϵͳ

http://acm.hdu.edu.cn/showproblem.php?pid=1257

���⣺
	���㵼�����˷����ĸ߶ȣ�ÿ����������ϵͳ���صĸ߶Ȳ��ܴ�����һ�������߶�
	����������е�������Ҫ�䱸���������ֵ�������ϵͳ.

˼·:
	���ȴ洢���е����߶ȣ�Ȼ�����α���ÿ���߶�
	����ÿ�������߶ȣ�����ұ����߶�С�ĵ�������ô��Щ������������һ��ϵͳ���أ�
	�������Ǳ��Ϊ0��������ʱ���Թ�����
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
