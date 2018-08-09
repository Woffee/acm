# include <iostream>
using namespace std;
class Mammal
{
public:
     Mammal():itsAge(2), itsWeight(5)
     {
     cout<<"Mammal constructor��\n";
	 }
     ~Mammal () {cout<<"Mammal destructor��\n";}
     int GetAge () const { return itsAge;}
     void SetAge (int age) {itsAge = age;}
     int GetWeight () const {return itsWeight; }
     void SetWeight (int weight) {itsWeight = weight;}
     void Move () const {cout << "Mammal move one step\n";}
     virtual void Speak () const {}
     void sleep () const { cout << "shhh, I'm sleeping.\n";}
protected:
     int itsAge;
     int itsWeight;
};
class Dog:public Mammal
{
public:
    Dog(){}
    Dog(int a,int w){itsAge=a;itsWeight=w;}
	virtual void Speak()//ʵ��Ϊ�麯���������Woof
	{
	    cout<<"Woooooooooooof!!!"<<endl;
	}
	void Tail()  // ����Ҫβ�ͣ����ӳ�Ա�����������Tail wagging��������
	{
	    cout<<"Tail wagging..."<<endl;
	}
	void beg()//����ʳ����ӳ�Ա����
	{
	    cout<<"I'm hungry..."<<endl;
	}
}
class Cat:public Mammal
{
public:
    Cat(){}
    Cat(int a,int w){itsAge=a;itsWeight=w;}
    virtual void Speak()
	{
	    cout<<"Meow!"<<endl;
	}
} ;
class Horse:public Mammal
{
public:
    Horse(){}
    Horse(int a,int w){itsAge=a;itsWeight=w;}
    virtual void Speak()
	{
	    cout<<"Winnie!"<<endl;
	}
};
class Pig:public Mammal
{
public:
    Pig(){}
    Pig(int a,int w){itsAge=a;itsWeight=w;}
    virtual void Speak()
	{
	    cout<<"Oink"<<endl;
	}
};

class Play()
{
public:
    Play(){}
    void Menu(){
        cout<<"1:CAIRN"<<endl
            <<"2:DORERMAN"<<endl
            <<"3:LAB"<<endl
            <<"4:è"<<endl
            <<"5:��"<<endl
            <<"6:��"<<endl;}
    void get_print
private:
    Dog d;
    Cat a;
    Horse h;
    Pig p;
};
int  main()
{
    Play p;
    p.Menu();
    p.Get_print();
}

/*
����ũ��
���鶯����������ʾ��
     # include <iostream.h>
   class Mammal
{
public:
     Mammal():itsAge(2), itsWeight(5)
     {
     cout<<"Mammal constructor��\n";
	 }
     ~Mammal () {cout<<"Mammal destructor��\n";}
     int GetAge () const { return itsAge;}
     void SetAge (int age) {itsAge = age;}
     int GetWeight () const {return itsWeight; }
     void SetWeight (int weight) {itsWeight = weight;}
     void Move () const {cout << "Mammal move one step\n";}
     virtual void Speak () const {}
     void sleep () const { cout << "shhh, I'm sleeping.\n";}
protected:
     int itsAge;
     int itsWeight;
};
�������鶯�������������Ʒ��֮�֣��ڲ�����Ļ���������Ʒ�����ϳ�Ա����
�����������������Speak����ʵ��Ϊ�麯���������Woof!������
����Ҫβ�ͣ����ӳ�Ա�����������Tail wagging��������
����ʳ����ӳ�Ա�����������begging for food��������

è������Ҳ���ڲ��鶯�������ֱ�Ϊ����Meow!��, ��Winnie!��, ��Oink����
��̷ֱ�ʹ�����������Ϊ��һ������Ϊ��
Ҫ��
�� ����Ʒ�֣�
enum BREED{YORKIE, CAIRN, DANDIE, SHETLAND, DORERMAN,
      LAB};�ֱ���һ������ʵ�����ù���Ʒ�֣���һ������ʵ�ֶ�������Ʒ�֡�
�� �ӻ���Mammal��ֱ����������ֶ��
ͨ���麯��ʵ��Mammal�ද�����ָ�뱻��//?????????????
�費ͬ�Ķ�������ʱ������Ϊ��ͬ����Ϊ��
�� ����
��CAIRN��3�꣬30kg��
DORERMAN��4�꣬28kg��
LAB��6�꣬40kg��
è��2�꣬15kg��
��5�꣬60kg��
��2�꣬45kg��
�� ����һ��Mammal���飬����һ����Ļ�˵���ѡ��ͬ�Ķ����ͬ��Ʒ�֣�
��ʵ�ֶ�Ӧ�Ķ�����ֱ��ѡ�������
�� ��Ӧ�Ķ�����������ʾ�������ƣ�Ȼ�����䣬������Ʒ�֣��������Լ������ص㡣

*/
