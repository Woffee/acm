#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
using namespace std;
ofstream myf("d:\\xyz.txt");
class Employee
{
public:
    void print();
    Employee(char* n,int y,char* i,double m)
    {
        strncpy(name,n,sizeof(name));
        year=y;
        strncpy(id,i,sizeof(id));
        money=m;
    }
private:
    char name[20];
    int year;
    char id[20];
    double money;
};

int main()
{
    Employee one("张明丽",29,"111-22-333",425.00);
    Employee two("李楷楷",27,"333-22-111",350.00);
    Employee three("钟  静",41,"11-11-0000",650.00);

    myf<<"名字     年龄        编号          工资"<<endl;
    one.print();
    two.print();
    three.print();
    cout<<"成功写入到D:\\xyz.txt\n";
}
void Employee::print()
{
    myf<<setw(6)<<name
    <<setw(6)<<year
    <<setw(16)<<id
    <<setw(12)<<setiosflags(ios::fixed)<<setprecision(2)<<money<<endl;
}
