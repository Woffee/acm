/*
 * hdoj 2054
 * 字符串题 要考虑各种情况，题目中没有说明两个数是什么样的数
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
 a.erase(a.begin()+k+1, a.end());//erase(a,b) 代表抹去a到b之间的元素
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

