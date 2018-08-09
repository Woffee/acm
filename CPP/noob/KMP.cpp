#include<iostream>
#include<malloc.h>

using namespace std;
main()
{
    int t;
    string a,b;
    cin>>t;

    while (t-- > 0)
    {

        cin>>a>>b;
        int n=b.length();
        int next [n];

        // getnext[]
        int i = 0;
        next[0] = -1;
        int j = -1;
        while (i < n)
        {
            if (j == -1 ||b[i] == b[j])
            {
                ++i;
                ++j;
				if(b[i]!=b[j])
					next[i]=j;
				else
					next[i]=next[j];
            }
            else
            {
                j = next[j];
            }
        }

        //KMP
        i =0;
        j=0;
        while(i<a.length()&&j<n)
        {
            if(j==-1||a[i]==b[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j=next[j];
            }
        }

        if(j>=n)
            cout<<i-n<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}

