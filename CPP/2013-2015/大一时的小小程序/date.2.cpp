#include<iostream>
using namespace std;

class Date
{
public:
    Date();
    Date(int y,int m,int d){
        year=y;
        month=m;
        day=d;}
    Date(Date& s){
        year=s.year;
        month=s.month;
        day=s.day;}
    void Set(int y,int m,int d){
        year=y;
        month=m;
        day=d;}
    void Daypp(){
        day++;}
    void Input(){
        cin>>year>>month>>day;}
    void Print(){
        cout<<year<<"-"<<month<<"-"<<day<<endl;}
private:
    int day;
    int month;
    int year;
};

int main()
{
    Date d1(2001,1,1);
    d1.Print();
    Date d2(2002,2,2);
    d2.Print();
    Date d3(2003,3,3);
    d3.Print();
}
