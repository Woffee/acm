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
		<<"-----------3:Default:10�ˣ����3\n";
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
	cout<<"ԭ���ı�ţ�";
	for(int i=0;i<person_num;i++) cout<<a[i]<<",";

	cout<<endl;

	int k=1;
	int i=-1;
        cout<<"�뿪�ı�ţ�";
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
	cout<<"\n"<<person_num<<"�ˣ����"<<interval<<"��ʤ���ߣ�"<<a[i]<<" (�ǵݹ�)"<<endl;
	delete[]a;
}

