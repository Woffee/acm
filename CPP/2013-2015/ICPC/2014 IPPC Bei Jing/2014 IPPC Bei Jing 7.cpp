//2014 ACMICPC Asia Regional Beijing Online------Grade
/*
Bad Mushroom

后面是我的代码，测试案例成功了，提交错误。
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int x=1;x<=T;x++)
    {
        map<int,int> mushroom;
        map<int,int>::iterator it=mushroom.begin();//???
        for(int i=0;i<=200;i++)
        {
            mushroom.insert(map<int,int>::value_type(i,0));
        }
        int N;
        cin>>N;
        for(int y=0;y<N;y++)
        {
            int weight;
            scanf("%d",&weight);
            it=mushroom.find(weight);
            it->second++;
        }
        map<int,int> count;
        int max=0;
        for(int i=1;i<=100;i++)
        {
            if(i!=100)
                count.insert(map<int,int>::value_type(i,mushroom.find(i)->second+mushroom.find(200-i)->second));
            else
                count.insert(map<int,int>::value_type(i,mushroom.find(i)->second));
            max=max<count.find(i)->second ? count.find(i)->second : max;
        }
        vector<int> a;
        int flag_1=1;
        int flag_2=0;
        int n=1;
        int all=0;
        for(map<int,int>::iterator iter=count.begin();iter!=count.end();iter++)
        {
            if(iter->second==max)
            {
                a.push_back(n);
                all++;
            }
            else
            {
                if(iter->second!=0)
                flag_2=1;
            }
            n++;
        }
        cout<<"Case #"<<x<<":"<<endl;
        if(flag_2==0 && all!=1)
            cout<<"Bad Mushroom"<<endl;
        else
        {
            for(int i=0;i<a.size();i++)
            {
                cout<<200*a[i]-a[i]*a[i];
                if(i!=a.size()-1)
                    cout<<" ";
            }
            cout<<endl;
        }
    }
}


/*#include <algorithm>   
#include <iostream>
#include <iomanip>     
#include <fstream>     
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <time.h>      
#include <map>
using namespace std; 
int data[1000005];
int absd[105]={0};
int fre[205]={0};
int fre_abs[101]={0};
//int temp[205]={0};//记录s对应的data
int abs(int a){
	if(a>=100)return (a-100);
	else return (100-a);
}

int main()
{

	int t;
	cin>>t;
	stack<int>ans;
	for(int i=1;i<=t;i++){
		memset(data,0,sizeof(data));
		memset(absd,0,sizeof(absd));
		memset(fre,0,sizeof(fre));
		//memset(temp,0,sizeof(temp));
		memset(fre_abs,0,sizeof(fre_abs));
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>data[j];
			absd[j]=abs(data[j]);
			fre[data[j]]++;//记录每个不同的数据出现的次数
			fre_abs[absd[j]]++;//记录s出现的次数
		}

		bool flag=true;

		


		int max_fre_s=-1;
		for(int j=0;j<101;j++){
			if(fre_abs[j]>=max_fre_s)
				max_fre_s=fre_abs[j];
		}

		for(int j=0;j<n;j++){
			if(fre_abs[absd[j]]==max_fre_s){
				int tt=data[j];
				int ttabsd=absd[j];
				//cout<<"tt "<<tt<<endl;
				for(int k=j+1;k<n;k++){
					if( fre_abs[absd[k]]==max_fre_s && absd[k]==ttabsd){
						//cout<<"fre_abs[absd[k]]==max_fre_s"<<endl;
						if(data[k]!=tt ){
							flag=false;
							break;
						}
					}
				}

			}
			if(!flag)break;
		}

		//把出现频率最多的入栈
		if(flag){
			for(int j=0;j<101;j++){
				if(fre_abs[j]==max_fre_s)
					ans.push(10000-j);
			}
		}

		cout<<"Case #"<<i<<":"<<endl;
		if(flag){
			bool first=true;
			while(!ans.empty()){
				if(first){
					cout<<ans.top();
					first=false;
				}
				else 
					cout<<" "<<ans.top();
				ans.pop();
			}
			cout<<endl;
		}
		else cout<<"Bad Mushroom"<<endl;
	}     
	
}*/