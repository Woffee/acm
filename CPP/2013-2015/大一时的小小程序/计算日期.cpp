#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

class cDate
{
public:
    void get()//输入起始年，月，日
    {
        allday=0;
        cout<<"Date:\n";
        cin>>year_1>>month_1>>day_1;
        cin>>year_2>>month_2>>day_2;
    }
    void all()//计算
    {
        if(year_1==year_2)
        {
            if(month_1==month_2)
            {
                allday+=(day_2-day_1);

                return;
            }
            else
            {
                for(int i=month_1+1; i<=month_2-1; i++)
                    yue(i);
                dangyue_1();
                dangyue_2();
            }
            return ;
        }
        if(year_2 - year_1 > 1)
        {
            for(int i=year_1+1 ; i<year_2 ; i++)
            {
                if(isrun_(i)) allday+=366;
                else allday+=365;
            }
        }
        for(int i=month_1+1; i<=12; i++) //ji suan qi shi nian de tian shu
            yue(i);
        for(int i=1; i<=month_2-1; i++) //ji suan zui zhong nian de tian shu
            yue(i);
        dangyue_1();
        dangyue_2();
    }
    int isrun_(int year)//是否为闰年
    {
        if(year%4==0 && year%100!=0 || year%400==0)
            return 1;
        return 0;
    }
    void yue(int i)//加上i月的天数
    {
        if( isyue_31(i) )
            allday+=31;
        if( isyue_30(i) )
            allday+=30;
        if(i==2)
        {
            if(isrun_(year_1))
                allday+=29;
            else
                allday+=28;
        }
    }
    void dangyue_1()//加上day_1后当月的天数
    {
        for(int i=month_1;;)
        {
            if( isyue_31(i) )
                allday+=31-day_1;
            if( isyue_30(i) )
                allday+=30-day_1;
            if(i==2)
            {
                if(isrun_(year_1))
                    allday+=29-day_1;
                else
                    allday+=28-day_1;
            }
            break;
        }
    }
    void dangyue_2()//加上day_2
    {
        allday+=day_2;
    }
    int isyue_31(int i)//该月是否有31天
    {
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            return 1;
        return 0;
    }
    int isyue_30(int i)//该月是否有30天
    {
        if(i==4||i==6||i==9||i==11)
            return 1;
        return 0;
    }
    void restart()//重置数据
    {
        allday=0;
        year_1=0;
        month_1=0;
        day_1=0;
        year_2=0;
        month_2=0;
        day_2=0;
    }
    void kong(int i)//打印i个空格
    {
        for(int n=1; n<=i; n++)
            cout<<" ";
    }
    void print()//输出结果
    {
        kong(17);
        cout<<"┌────────────────────┐\n";
        kong(17);
        cout<<"│              "<<"共:"<<setw(6)<<allday<<"  天             │"<<endl;
        kong(17);
        cout<<"└────────────────────┘\n\n\n";
    }
private:
    int year_1,month_1,day_1;//起始年，月，日
    int year_2,month_2,day_2;//末尾年，月，日
    int allday;//天数
};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main()
{
    cDate nian;
    nian.get();
    nian.all();
    nian.print();
    system("pause");
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>







