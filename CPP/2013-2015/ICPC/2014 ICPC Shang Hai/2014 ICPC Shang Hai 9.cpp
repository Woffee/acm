//来源网上。。。
#include <stdio.h>
#include <string.h>

#define MAXN 1000
struct BigNumber {
    int len;
    int v[MAXN];
};
bool isSmaller(BigNumber n1,BigNumber n2)
{
    if(n1.len<n2.len)
        return 1;
    if(n1.len>n2.len)
        return 0;
    for(int i=n1.len-1; i>=0; i--) {
        if(n1.v[i]<n2.v[i])
            return 1;
        if(n1.v[i]>n2.v[i])
            return 0;
    }
    return 0;
}
BigNumber minus(BigNumber n1,BigNumber n2)
{
    BigNumber ret;
    int borrow,i,temp;
    ret=n1;
    for(borrow=0,i=0; i<n2.len; i++) {
        temp=ret.v[i]-borrow-n2.v[i];
        if(temp>=0) {
            borrow=0;
            ret.v[i]=temp;
        } else {
            borrow=1;
            ret.v[i]=temp+2;
        }
    }
    for(; i<n1.len; i++) {
        temp=ret.v[i]-borrow;
        if(temp>=0) {
            borrow=0;
            ret.v[i]=temp;
        } else {
            borrow=1;
            ret.v[i]=temp+2;
        }
    }
    while(ret.len>=1 && !ret.v[ret.len-1])
        ret.len--;
    return ret;
}
BigNumber div2(BigNumber n)
{
    BigNumber ret;
    ret.len=n.len-1;
    for(int i=0; i<ret.len; i++)
        ret.v[i]=n.v[i+1];
    return ret;
}
void gcd(BigNumber n1,BigNumber n2)
{
    long b=0,i;
    while(n1.len && n2.len) {
        if(n1.v[0]) {
            if(n2.v[0]) {
                if(isSmaller(n1,n2))
                    n2=minus(n2,n1);
                else
                    n1=minus(n1,n2);
            } else
                n2=div2(n2);
        } else {
            if(n2.v[0])
                n1=div2(n1);
            else {
                n1=div2(n1);
                n2=div2(n2);
                b++;
            }
        }
    }
    if(n2.len)
        for(i=n2.len-1; i>=0; i--)
            printf("%d",n2.v[i]);
    else
        for(i=n1.len-1; i>=0; i--)
            printf("%d",n1.v[i]);
    while(b--)
        printf("0");
    printf("\n");
}
int main()
{
    int cases,le,i;
    BigNumber n1,n2;
    char str1[MAXN],str2[MAXN];
    scanf("%d",&cases);
    for(int ii=1; ii<=cases; ii++) {
        scanf("%s%s",str1,str2);
        le=strlen(str1);
        n1.len=le;
        for(i=0; i<le; i++)
            n1.v[i]=str1[le-1-i]-'0';
        le=strlen(str2);
        n2.len=le;
        for(i=0; i<le; i++)
            n2.v[i]=str2[le-1-i]-'0';
        printf("Case #%d: ",ii );
        gcd(n1,n2);
    }
    return 0;
}
