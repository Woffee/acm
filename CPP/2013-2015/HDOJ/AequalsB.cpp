/*
 * hdoj 2054
 * �ַ����� Ҫ���Ǹ����������Ŀ��û��˵����������ʲô������
 * 2014.8.27
*/
#include <iostream>
#include <string>
using namespace std;

void func(string & a)
{
 int k = a.length()-1;
 while (a[k]=='0') k--;
 if (a[k] == '.') k--;
 a.erase(a.begin()+k+1, a.end());//erase(a,b) ����Ĩȥa��b֮���Ԫ��
}
int main()
{
 string str1, str2;
 int i;
 while (cin >> str1 >> str2) {
  if (str1.find(".") != string::npos) func(str1);
  if (str2.find(".") != string::npos) func(str2);
  //cout << str1 << endl << str2 << endl;
  if (str1 == str2) puts("YES");
  else puts("NO");
 }
 return 0;
}

