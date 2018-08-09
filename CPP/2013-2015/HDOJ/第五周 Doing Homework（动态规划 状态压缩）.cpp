/*
Doing Homework

大意：给出每项作业， 有它的截止时间和完成它要花的时间， 如果在截止时间后完成， 要扣学分，
让找出最佳的做作业顺序，使扣得学分最少。

思路：          
		用2进制表示作业的完成情况， 0代表未完成， 1代表完成，共有n个作业， 
		那么所有作业完成的情况就是2的n次方减1（000~111）

		声明两个结构数组，一个用来存储给出的数据，不用说
		另一个是dp数组，每个结构就是一个状态,包括：  
						总共花的时间
						减少的学分
						前一项作业号码
						当前做的课程名

		然后从状态000到状态111遍历，嵌套一个for循环遍历作业，判断当前状态是否完成该作业
		如果完成就跳过，否则就完成它，记录花的时间和扣的分数

		如果完成后的状态前面已经处理过，就取扣的学分少的那个

		最后输出就可以了

		课程名要逆着输出，可以用栈，也可以递归
*/


#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std; 
struct  
{  
    int cost;//总共花的时间  
    int reduce;//减少分数  
    int pre;//记录前一个  
    char name[102];  //当前状态最后完成的作业
}dp[32769];  
struct  
{  
    int time;  
    int cost;  
    char name[102];  
}e[16];  
void print(int i)  
{  
    if(dp[i].pre == -1)  
        return;  
    print(dp[i].pre);  //逆序输出刚好正确
    printf("%s\n",dp[i].name);  
}  
int main()  
{  
    int i = 0, j = 0, n = 0, t = 0, total = 0, cur = 0, all_time = 0, visit[32769];  
    int cost = 0,  reduce = 0;  
    scanf("%d",&t);  
    while(t--)  
    {  
        memset(visit, 0, sizeof(visit));  
        all_time = 0;  
        scanf("%d",&n);  
        total = 1<<n;  
        getchar();  
        dp[0].cost = dp[0].reduce = 0;  
        dp[0].pre = -1;  
        for(i = 0; i<n; i++)  
        {  
            scanf("%s %d %d",e[i].name, &e[i].time, &e[i].cost);  
        }  
        for(i = 0; i<total; i++)  
        {  
            for(j = 0; j<n; j++)  
            {  
                cur = 1<<j; //用2进制表示作业的完成情况,这里cur依次等于001,010,100

                if(!(i&cur))//按位与运算，i&cur == 0表示当前第j个作业未完成 
                {  
                    cur = i|cur;//按位或运算，cur为完成了作业j的状态  
                    cost = dp[i].cost+e[j].cost;//当前一共花了多少时间  
                    reduce = cost-e[j].time;//这回扣了多少分  
                    if(reduce<0)  
                        reduce = 0;  
                    reduce += dp[i].reduce;//这回的扣分加上以前的扣分为总扣得分数  
                    if(visit[cur])//如果cur这个状态曾经处理过，就取扣分少的  
                    {  
                        if(reduce<dp[cur].reduce)  
                        {  
                            dp[cur].cost = cost;  
                            dp[cur].reduce = reduce;  
                            dp[cur].pre = i;  
                            strcpy(dp[cur].name, e[j].name);  
                        }  
                    }  
                    else  
                    {  
                        visit[cur] = 1;  //标记为处理过
                        dp[cur].cost = cost;  
                        dp[cur].reduce = reduce;  
                        dp[cur].pre = i;  
                        strcpy(dp[cur].name, e[j].name);  
                    }  
                }  
            }  
        }  
        printf("%d\n",dp[total-1].reduce);  
        print(total-1);  
    }  
    return 0;  
}  