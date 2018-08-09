/*
Subtraction of large numbers
*/

#include <stdio.h>
#include <string.h>
void main()
{
	int la,lb,lc,l,t,n,i,j=0;
	char a[1002],b[1002],c[1002];
	scanf("%d",&t);
	while(t--)
	{
		getchar();
		for(i=0;i<1002;i++)
		{
			a[i]='\0';
			b[i]='\0';
			c[i]='\0';
		}
		scanf("%s%s",a,b);
		la=strlen(a);la=la-1;
		lb=strlen(b);lb=lb-1;
		for(i=1001,n=0;la>=0&&lb>=0;la--,lb--,i--)
		{
			c[i]=(a[la]-48+b[lb]-48+n)%10+48;
			if(a[la]-48+b[lb]-48+n>=10)
				n=1;
			else
				n=0;
		}
		if(la>lb)
		{
			for(;la>=0;la--,i--)
			{
				c[i]=(a[la]-48+n)%10+48;
				if(a[la]-48+n>=10)
					n=1;
				else
					n=0;
			}
		}
		else if(la<lb)
		{
			for(;lb>=0;lb--,i--)
			{
				c[i]=(b[lb]-48+n)%10+48;
				if(b[lb]-48+n>=10)
					n=1;
				else
					n=0;
			}
		}

		if(n==1)
			c[i]=1+48;
		j++;
		printf("Case %d:\n",j);
		printf("%s + %s = ",a,b);
		for(i=0;i<1002;i++)
		{
			if(c[i]!='\0')
				putchar(c[i]);
		}
		putchar('\n');
		if(t!=0)
			putchar('\n');
	}
}
