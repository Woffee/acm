/*
反转字符串
*/
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	int n;
    char ch;
	scanf("%d",&n);
	getchar(); /*吸收回车符*/
	while(n--)
	{
		stack<char> s;
		while(1)
		{
			ch=getchar();
            if(ch==' '||ch=='\n'||ch==EOF)
			{
				while(!s.empty())
				{
					printf("%c",s.top());
					s.pop();
				}
				if(ch=='\n'||ch==EOF)
					break;
				printf(" ");
			}
			else
				s.push(ch);
		}
		printf("\n");
	}
	return 0;
}
