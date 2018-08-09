
/************** N! 大数乘法 *************/
memset(a,0,sizeof(a));
a[0]=1;b=1;
for(int i=1;i<=n;++i)
{
    temp=0;
    for(int j=0;j<b;j++)		//模拟手算过程...
    {
        a[j]=a[j]*i+temp;
        temp=a[j]/10;
        a[j]=a[j]%10;
        if(temp&&b<=j+1)
            b++;
    }
}
for(int i=b-1;i>=0;--i)			//倒序输出...
            cout<<a[i];


/************** 大数除法 **************/

/*----------高精度除低精度求商模板-----------*//*大数除法 ------除数为int范围*/

//******************************************
//**大数在数组的存储为顺序，下标大者为高位**
//******************************************

#define N 1000
using namespace std;				
void division(char * src,int n)		
{									
    int len = strlen(src),i,k,t=0,s=0;
    char dest[N];
    bool flag = true;    //商是否有了第一个有效位，防止商首部一直出现0    
    for(i=0,k=0; i<len; i++)		//模拟手算过程...
    {
        t = s*10+(src[i]-48);    //新余数
        if(t/n>0 || t==0)        //余数为0要修改商
        {
            dest[k++] = t/n+48,s = t%n,flag = false;
        }
       else                    //不够除，修改余数
        {
            s = t;
            if(!flag)            //商已经有有效位了，补零
                dest[k++] = '0';
        }
    }
       /*for(i=0;i<k;i++)		//正序输出...
         cout<<dest[i];
         cout<<endl;*/
}