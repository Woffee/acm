# include <iostream>
using namespace std;
class Mammal
{
public:
     Mammal():itsAge(2), itsWeight(5)
     {
     cout<<"Mammal constructor…\n";
	 }
     ~Mammal () {cout<<"Mammal destructor…\n";}
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
	virtual void Speak()//实现为虚函数，输出”Woof
	{
	    cout<<"Woooooooooooof!!!"<<endl;
	}
	void Tail()  // 还会要尾巴（增加成员函数，输出”Tail wagging…”），
	{
	    cout<<"Tail wagging..."<<endl;
	}
	void beg()//乞讨食物（增加成员函数
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
            <<"4:猫"<<endl
            <<"5:马"<<endl
            <<"6:猪"<<endl;}
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
仿真农场
哺乳动物类如下所示：
     # include <iostream.h>
   class Mammal
{
public:
     Mammal():itsAge(2), itsWeight(5)
     {
     cout<<"Mammal constructor…\n";
	 }
     ~Mammal () {cout<<"Mammal destructor…\n";}
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
狗属哺乳动物，且它的属性有品种之分（在哺乳类的基础上增加品种资料成员），
叫声区别于其它动物（Speak（）实现为虚函数，输出”Woof!”），
还会要尾巴（增加成员函数，输出”Tail wagging…”），
乞讨食物（增加成员函数，输出”begging for food…”）。

猫、马、猪也属于哺乳动物，其叫声分别为：”Meow!”, “Winnie!”, “Oink”。
编程分别使各个动物表现为不一样的行为。
要求：
① 狗的品种：
enum BREED{YORKIE, CAIRN, DANDIE, SHETLAND, DORERMAN,
      LAB};分别用一个操作实现设置狗的品种，另一个操作实现读出狗的品种。
② 从基类Mammal类分别派生出各种动物，
通过虚函数实现Mammal类动物对象指针被赋//?????????????
予不同的动物种类时，表现为不同的行为。
③ 今有
狗CAIRN：3岁，30kg；
DORERMAN：4岁，28kg；
LAB：6岁，40kg；
猫：2岁，15kg；
马：5岁，60kg；
猪：2岁，45kg。
④ 设置一个Mammal数组，设置一个屏幕菜单，选择不同的动物或不同的品种，
则实现对应的动作，直到选择结束。
⑤ 对应的动作中首先显示动物名称，然后年龄，重量，品种，叫声，以及其它特点。

*/
