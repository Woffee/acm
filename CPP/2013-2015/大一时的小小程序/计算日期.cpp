#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

class cDate
{
public:
    void get()//������ʼ�꣬�£���
    {
        allday=0;
        cout<<"Date:\n";
        cin>>year_1>>month_1>>day_1;
        cin>>year_2>>month_2>>day_2;
    }
    void all()//����
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
    int isrun_(int year)//�Ƿ�Ϊ����
    {
        if(year%4==0 && year%100!=0 || year%400==0)
            return 1;
        return 0;
    }
    void yue(int i)//����i�µ�����
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
    void dangyue_1()//����day_1���µ�����
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
    void dangyue_2()//����day_2
    {
        allday+=day_2;
    }
    int isyue_31(int i)//�����Ƿ���31��
    {
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            return 1;
        return 0;
    }
    int isyue_30(int i)//�����Ƿ���30��
    {
        if(i==4||i==6||i==9||i==11)
            return 1;
        return 0;
    }
    void restart()//��������
    {
        allday=0;
        year_1=0;
        month_1=0;
        day_1=0;
        year_2=0;
        month_2=0;
        day_2=0;
    }
    void kong(int i)//��ӡi���ո�
    {
        for(int n=1; n<=i; n++)
            cout<<" ";
    }
    void print()//������
    {
        kong(17);
        cout<<"��������������������������������������������\n";
        kong(17);
        cout<<"��              "<<"��:"<<setw(6)<<allday<<"  ��             ��"<<endl;
        kong(17);
        cout<<"��������������������������������������������\n\n\n";
    }
private:
    int year_1,month_1,day_1;//��ʼ�꣬�£���
    int year_2,month_2,day_2;//ĩβ�꣬�£���
    int allday;//����
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







