/*Author:3120000000

Bob and math problem

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 0    Accepted Submission(s): 0


Problem Description
Recently, Bob has been thinking about a math problem.
There are N Digits, each digit is between 0 and 9. You need to use this N Digits to constitute an Integer.
This Integer needs to satisfy the following conditions:
1. must be an odd Integer.

2. there is no leading zero.

3. find the biggest one which is satisfied 1, 2.

Example: 
  There are three Digits: 0, 1, 3. It can constitute six number of Integers. Only "301", "103" is legal, while "130", "310", "013", "031" is illegal. The biggest one of odd Integer is "301".
 
Input
There are multiple test cases. Please process till EOF.
Each case starts with a line containing an integer N ( 1 <= N <= 100 ).
The second line contains N Digits which indicate the digit a1,a2,a3,⋯,an.(0≤ai≤9).
 
Output
The output of each test case of a line. If you can constitute an Integer which is satisfied above conditions, please output the biggest one. Otherwise, output "-1" instead.
 
Sample Input
3
0 1 3
3
5 4 2
3
2 4 6
 
Sample Output
301
425
-1
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=105;
int A[maxn];
int B[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)==1){
         int od=11,loc=0;
         for(int i=0; i<n; ++i){
             scanf("%d",&A[i]);
             if(A[i]%2==1&&A[i]<od){
                od=A[i]; loc=i;
             }
         }
             if(od==11) {
                    puts("-1"); continue;
             }
             if(n==1) {
                  printf("%d\n",od); continue;
             }
             int len=0;
             for(int i=0; i<n; ++i)
                 if(i!=loc) B[len++]=A[i];
             sort(B,B+len);
             A[0]=od;
             int ff=1;
             for(int i=0; i<n-1; ++i){
                A[ff++]=B[i];
             }
             if(A[n-1]==0){
                    puts("-1");
                continue;
             }
             for(int i=n-1; i>=0 ; --i){
                 printf("%d",A[i]);
             }
             printf("\n");


    }
    return 0;
}
