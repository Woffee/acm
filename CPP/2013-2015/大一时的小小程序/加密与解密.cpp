//8_4

#include <iostream>
#include <string>
using namespace std;

void jiami(const char* str,int len);
void jiemi(const char* str,int len);
const char key[]={4,9,6,2,8,7,3};

int main()
{
  char s[]="the result of 3 and 2 is not 8";
  int slen=sizeof(s)/sizeof(char)-1;
  cout <<"\nԭ��Ϊ: \n" <<s <<endl;
  jiami(s,slen);                         //���ܺ����е����˽���
  cout<<endl<<endl;
}

void jiami(const char* str,int len)
{
  char result[len];
  for(int i=0,j=0; i<len; i++,j=(j+1)%7)
  {
    result[i] = str[i]+key[j];
    if(result[i]>122)
      result[i]-=90;
  }
  cout<<"\n\n���ܺ�\n";
  for(int i=0;i<len;i++)cout<<result[i];
  cout<<endl;
  jiemi(result,len);
}

void jiemi(const char* str,int len)
{
  char result[len];
  for(int i=0,j=0; i<len; i++,j=(j+1)%7){
    result[i] = str[i]-key[j];
    if(result[i]<32)
      result[i]+=90;
  }
  cout<<"\n\n���ܺ�\n";
  for(int i=0;i<len;i++)cout<<result[i];
  cout<<endl;
}






