//8_3

#include <iostream>
#include <stdlib.h>
#include <string.h>//����strcmp()��strlen()����
using namespace std;

int CompStrLen(const void* a, const void* b);

int main()
{
  char* str[]={"enter","number","size","begin","of","cat",
               "case","program","certain","a"};
  int strnum=sizeof(str)/sizeof(*str);
  cout <<"\n����ǰ:\n";
  for(int i=0; i<strnum; i++)
    cout <<str[i] <<" ";
  cout <<endl;

  qsort(str,strnum,sizeof(*str), CompStrLen);

  cout <<"�����:\n";
  for(int i=0; i<strnum; i++)
    cout <<str[i] <<" ";
  cout <<endl;
}
int CompStrLen(const void* a, const void* b)
{
  if(strlen(*(char**)a)==strlen(*(char**)b))
    return strcmp(*(char**)a, *(char**)b);
  return strlen(*(char**)a) - strlen(*(char**)b);
}

