#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int s1[3][3]={1,2,-1,-2,1,0,1,0,3};
    int s2[3][3]={5,7,8,2,-2,4,1,1,1};
    int s3[3][3];
    for(int m=0;m<3;m++)
    {
        for(int n=0;n<3;n++)
        {
            s3[m][n]=s1[m][n]+s2[m][n];
        }
    }
    for(int m=0;m<3;m++)
    {
        for(int n=0;n<3;n++)
            cout<<setw(4)<<s3[m][n];
        cout<<endl;
    }
    cout<<"\a\a";
}
