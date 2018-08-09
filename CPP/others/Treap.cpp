/*
Problem :平衡树·Treap（hiho一下 第103周）
Status  :AC

By wf,2016.06.19
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

struct node
{
    int key,weight;
    node*f, *l, *r;
    node()
    {
        f = NULL;
        l = NULL;
        r = NULL;
    }
};

void Left_rotate(node * a)
{
    node * b = a->r;
    b->f = a->f;
    if( a->f->l == a )
    {
        a->f->l = b;
    }
    else
    {
        a->f->r=b;
    }
    a->r = b->l;
    b->l->f=a;
    b->l = a;
    a->f = b;
}
void Right_rotate(node * a)
{
    node * b = a->l;
    b->f = a->f;
    if( a->f->l == a )
    {
        a->f->l = b;
    }
    else
    {
        a->f->r=b;
    }
    a->l = b->r;
    b->r->f=a;
    b->r = a;
    a->f = b;
}
node * Insert(node * a,int key)
{
    if(key < a->key)
    {
        if( a->l == NULL )
        {
            node * b = new node();
            b->key = key;
            b->weight = rand();

            a -> l = b;
            return a->l;
        }
        else
        {
            return Insert(a->l,key);
        }
    }
    else
    {
        if( a->r == NULL )
        {
            node * b = new node();
            b->key = key;
            b->weight = rand();

            a -> r = b;
            return a->r;
        }
        else
        {
            return Insert(a->r,key);
        }
    }
}
void Rotate(node * a)
{
    while( a->f != NULL )
    {
        node * fa = a->f;
        if(a->weight < fa->weight)
        {
            if(a==fa->l)
            {
                Right_rotate(fa);
            }
            else
            {
                Left_rotate(fa);
            }
        }
        else break;
    }
}
int Query(node*a,int val)
{
    if(a==NULL)return -1;

//    cout<<"now:"<<a->key;
//    if( a->l !=NULL )cout<<" l:"<<a->l->key;
//    if( a->r !=NULL )cout<<" r:"<<a->r->key;
//    if( a->f !=NULL )cout<<" f:"<<a->f->key;
//    cout<<endl;

    if( val == a->key )return val;

    if( val < a->key  )
    {
        if(a->l != NULL) return Query(a->l,val);
        else return -1;
    }
    else
    {
        if(a->r != NULL )
        {
            int ret = Query(a->r,val);
            if(ret==-1)return a->key;
            else return ret;
        }
        else
        {
            return a->key;
        }

    }

    return -1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);

    node * root = NULL;
    int key,n;
    char ch;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>ch>>key;
        if(ch=='I')
        {
            if( root == NULL )
            {
                node * b = new node();
                b->key = key;
                b->weight = rand();
                root = b;
            }
            else
            {
                Rotate(Insert(root,key));
            }
        }
        else
        {
            cout<<Query(root,key)<<endl;
        }

    }

    return 0;
}
