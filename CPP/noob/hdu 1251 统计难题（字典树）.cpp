#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

struct WordNode{
	//num���Ա�ʾһ���ֵ��������ж�����ͬǰ׺����Ŀ�����������ҪӦ��ѧ�����ɱ仯��
	int num ;
	//next�Ǳ�ʾÿ���ж���������������ֻ��Сд��ĸ����26���ɣ�
	//����Ϊ��Сд��ĸ������52�����ټ������֣�����62�ˣ��������������ȷ����
	WordNode * nextNode[26];
};

WordNode wordNode[10000000];
int index ;
WordNode * ip ;

void insertNode(char str[11])
{
	ip = wordNode ;
	for(int i = 0; i < strlen(str);i ++)
	{
		if(ip->nextNode[str[i] - 'a'] != 0)
		{
			ip->nextNode[str[i] - 'a']->num ++ ;
		}
		else
		{
			index ++ ;
			ip->nextNode[str[i] - 'a'] = wordNode + index ;
			ip->nextNode[str[i] - 'a']->num = 1 ;
		}
		ip = ip->nextNode[str[i] - 'a'] ;
	}
	
}
int search(char str[11])
{
	ip = wordNode ;
	for(int  i = 0; i < strlen(str); i ++)
	{
		if(ip->nextNode[str[i] - 'a'] != NULL)
			ip = ip->nextNode[str[i] - 'a'] ;
		else
			return 0 ;
	}
	return ip->num ;

}
int main()
{
	char temp[11];
	
	while(gets(temp)) 
	{
		if(strlen(temp)==0)
			break;
		insertNode(temp) ;
	}

	while(gets(temp) != NULL)
	{
		cout<<search(temp)<<endl;
	}
	
	return 0;
}