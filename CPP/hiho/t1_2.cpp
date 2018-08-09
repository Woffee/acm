#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int N=505, M=100000;
bool edge[N][N];   // �����¼�����Ƿ���ڱ�
bool visit[N];  // ��Ǹýڵ��Ƿ���ʹ�

bool DFS_check(int x, int y=-1)
{
    if (visit[x])
        return false;

    visit[x] = true;
    int i;
    for (i=0; i<N; i++)
        if (edge[x][i] && i!=y)
            if (visit[i])
                return false;
            else if (!DFS_check(i, x))
                return false;

    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);

        memset(edge,false,sizeof(edge));
        int i,x,y;
        for (i=0; i<m; i++)
        {
            scanf("%d%d",&x,&y);
            edge[x-1][y-1] = true;
            edge[y-1][x-1] = true;
        }

        memset(visit,false,sizeof(visit));
        bool result = DFS_check(0);
        if (result)
            for (i=0; i<n; i++)
                if (!visit[i])
                    result = false;
        if (result)
            printf("YES\n");
        else
            printf("NO\n");
    }


    //system("pause");
    return 0;
}
