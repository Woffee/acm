#include<iostream>
#include<iomanip>
#include<windows.h>

using namespace std;


int year_1,month_1,day_1;//起始年，月，日
int year_2,month_2,day_2;//末尾年，月，日
int allday=0;//天数


void get();//输入起始年，月，日
int isright(int year,int month,int day);//判断日期是否正确
void all();//计算
int isrun_(int year);//判断日期是否是闰年
void dangyue_1();
void dangyue_2();
void yue(int i);
int isyue_31(int i);
int isyue_30(int i);
void restart();
void print();
void kong(int i);//打印空格

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main()
{
    year_1=1995;month_1=1;day_1=1;
    year_2=2014;month_2=4;day_2=15;
    all();
    restart();
    start:
    get();
    if(isright(year_1,month_1,day_1) && isright(year_2,month_2,day_2))
    {
	system("cls");
	all();
    }
    else cout<<"Error!\n\n";
    restart();
    goto start;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int isright(int year,int month,int day)
{
    int isrun=0;
    if(month>12||month<1)return 0;
    if(year%4==0 && year%100!=0 || year%400==0)isrun=1;
    if(isrun==1 && month==2)
	    if(day>29)return 0;	
    if(isrun==0 && month==2)
	    if(day>28)return 0;	
    if(isyue_31(month))
	    if(day>31)return 0;
    if(isyue_30(month))
	    if(day>30)return 0;
    return 1;
}
int isrun_(int year)
{
    if(year%4==0 && year%100!=0 || year%400==0)
	return 1;
    return 0;
}
void all()
{
    if(year_1==year_2)
    {
	if(month_1==month_2)
	{
	    allday+=(day_2-day_1);
	    print();
	    return;
	}
	else
	{
	    for(int i=month_1+1;i<=month_2-1;i++)
		yue(i);
	    dangyue_1();
	    dangyue_2();
	}
	print();
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
    for(int i=month_1+1;i<=12;i++)//ji suan qi shi nian de tian shu
	yue(i);
    for(int i=1;i<=month_2-1;i++) //ji suan zui zhong nian de tian shu
	yue(i);
    dangyue_1();
    dangyue_2();
    print();
}
void yue(int i)
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
void dangyue_1()
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
void dangyue_2()
{
    allday+=day_2;
}
void get()
{
    kong(25);
    cout<<"Date:\n";
    kong(25);
    cin>>year_1>>month_1>>day_1;
    kong(25);
    cin>>year_2>>month_2>>day_2;
}
int isyue_31(int i)
{
    if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
	return 1;
    return 0;
}
int isyue_30(int i)
{
     if(i==4||i==6||i==9||i==11)
	return 1;
    return 0;
}
void restart()
{
    allday=0;
    year_1=0;month_1=0;day_1=0;
    year_2=0;month_2=0;day_2=0;
}
void kong(int i)
{
    for(int n=1;n<=i;n++)
	cout<<" ";
}
void print()
{
    cout<<endl;
    kong(25);
    cout<<"          "<<year_1<<" "<<setw(2)<<month_1<<" "<<setw(2)<<day_1
	<<endl;
    kong(39);
    cout<<"TO"<<endl;
    kong(25);
    cout<<"          "<<year_2<<" "<<setw(2)<<month_2<<" "<<setw(2)<<day_2
	<<endl;
    kong(17);
    cout<<"┌────────────────────┐\n";
    kong(17);
    cout<<"│              "<<"共:"<<setw(6)<<allday<<"  天             │"<<endl;
    kong(17);
    cout<<"└────────────────────┘\n\n\n";
}






