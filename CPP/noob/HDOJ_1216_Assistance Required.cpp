#include<iostream>
using namespace std;
int lucky[3005];
int index=1;
typedef struct Lnode {
    int data;
    struct Lnode* next;
} Lnode,*LinkList;

void CreateList(LinkList&L)
{
    L=(LinkList)malloc(sizeof(Lnode));
    L->next=NULL;
    LinkList s=L;
    for(int i=2; i<=40000; i++) {
        LinkList p=(LinkList)malloc(sizeof(Lnode));
        p->data=i;
        p->next=NULL;
        s->next=p;
        s=p;
    }
}
void FindNumber(LinkList&L)
{

    LinkList q,s;
    LinkList p=L->next;
    while(p->next!=NULL) {
        lucky[index++]=p->data;
        q=p;

        if(index>=3001) break;


        while(p->next!=NULL) {
            int k=0;
            while(p->next!=NULL&&k<q->data) {
                k++;
                s=p;
                p=p->next;
            }
            if(p&&k==q->data)
                s->next=p->next;

        }
        p=q->next;

    }

}

int main()
{
    int n;
    LinkList L;
    CreateList(L);

    FindNumber(L);
    while(1) {
        scanf("%d",&n);
        if(n==0) break;
        printf("%d\n",lucky[n]);

    }
    return 0;
}
