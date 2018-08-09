#include<iostream>
using namespace std;
void swap(char &ap,char &bp);
int main()
{
    char *ap="hello", *bp="how are you?";
    cout<<"a="<<ap<<",b="<<bp<<endl;
    swap(ap,bp);
    cout<<"a="<<ap<<",b="<<bp<<endl;
}
void swap(char &ap,char &bp)
{
    char temp;
    temp=ap; ap=bp; bp=temp;
    cout<<"a="<<ap<<",b="<<bp<<endl;
}

