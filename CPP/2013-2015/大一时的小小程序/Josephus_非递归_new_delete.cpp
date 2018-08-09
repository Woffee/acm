#include<iostream>
using namespace std;
int main()
{
	int person_num;
	int interval;

	cout<<"Person:";
	cin>>person_num;
	cout<<"Interval:";
	cin>>interval;

	do
	{
		
		
		if(person_num>=1&&interval>=1)break;
	
	
		int tem;
		cout
		<<"-----------Error!Please make a choice:\n"
		<<"-----------1:Quit\n"
		<<"-----------2:Re enter\n"
		<<"-----------3:Default:10人，间隔3\n";
		cin>>tem;
		switch(tem)
		{
			case 1:return 0;
			case 2:{cout<<"Person:";
					cin>>person_num;
					cout<<"Interval:";
					cin>>interval;};break;
			case 3:person_num=10;
				   interval=3;

		}
	}while(person_num<1||interval<1);
	int * a;
	a=new int[person_num];

	for(int i=0;i<person_num;i++) a[i]=i+1;
	cout<<"原来的编号：";
	for(int i=0;i<person_num;i++) cout<<a[i]<<",";

	cout<<endl;

	int k=1;
	int i=-1;
        cout<<"离开的编号：";
	while(1)
	{
		for(int j=0;j<interval;)
		{
			i=(i+1)%person_num;
			if(a[i]!=0)j++;
		}
		if(k==person_num)break;
		cout<<a[i]<<",";
		a[i]=0;
		k++;
	}
	cout<<"\n"<<person_num<<"人，间隔"<<interval<<"。胜利者："<<a[i]<<" (非递归)"<<endl;
	delete[]a;
}

