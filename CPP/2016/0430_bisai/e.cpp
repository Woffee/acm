/*
Problem :
Status  :

一个字符串，
V:元音的个数
C:辅音的个数
如果V<=2*C，那么这个串是好串

问你最长的好子串的长度，以及这个长度的子串的数量

By wf,
*/

#include "algorithm"
#include "iostream"
#include "cstring"
#include "cstdio"
#include "string"
#include "stack"
#include "cmath"
#include "queue"
#include "set"
#include "map"

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

typedef long long ll;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
