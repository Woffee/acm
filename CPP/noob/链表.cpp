//链表
	//链表L1和链表L2合并为链表L3
	#include<stdio.h>
	#include<stdlib.h>
	typedef int ElemType;                        //定义元素类型为整型
	typedef struct LNode{
		ElemType data;
		struct LNode *next;
	}LNode;
	LNode* build()                               //单链表的创建
	{
		int i=1;
		int n;                                  //n为链表的长度
		LNode *L,*p;                            //L为头指针
		L=(LNode *)malloc(sizeof(LNode));       //为头结点开辟空间
	    	p=L;
		scanf("%d",&n);                         //输入链表的长度
		L->data=n;
		printf("请输入链表中的元素:");
		for(;i<=n;++i)
		{
	        p->next=(LNode *)malloc(sizeof(LNode));//为元素开辟空间
	        p=p->next;  
			scanf("%d",&(p->data));
		}
		p->next=NULL;
		return L;
	}
	void GetElem_L(LNode *L,int i,ElemType e)//元素的查找及修改
	{
		//L为带头结点的单链表的头指针
		//当第i个元素存在时，将其值改为e
		LNode *p;
		int j=1;                            //j为计数器
		p=L->next;                          //初始化p指向第一个结点
		while(p&&j<i)                       //顺指针向后查找，直到p指向第i个元素或p为空
		{
			p=p->next;++j;
		}
		if(!p||j>i)                         //第i个元素不存在
		    printf("第%d个元素不存在！\n",i);
		else
		{
			printf("第%d个元素为:%d\n",i,p->data);//将第i个元素输出
			p->data=e;                      //将第i个元素的值改为e
		}
	}
	void Insert(LNode *L,int i,ElemType e)  //在第i个位置之前插入元素e
	{
		//在带头结点的单链线性表L中第i个位置之前插入元素e
		int j=0;
		LNode *p,*q;
		p=L;
		while(p&&j<i-1)                     //寻找第i-1个结点
		{
			p=p->next;++j;
		}
		if(!p||j>i-1)                        //i小于1或大于表长加1
		{
			printf("插入位置不合理！\n");
			return ;
		}
		q=(LNode *)malloc(sizeof(LNode));    //生成新结点
		q->data=e;q->next=p->next;           //插入L中
		p->next=q;
		return ;
	}
	void Delete(LNode *L,int i,ElemType e)   //在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
	{
		int j=0;
		LNode *p,*q;
		p=L;                        
		while(p->next&&j<i-1)                //寻找第i个结点，并令p指向其前驱
		{
			p=p->next;++j;
		}
		if(!(p->next)||j>i-1)                //删除位置不合理！
		{
			printf("删除位置不合理！");
			return ;
		}
		q=p->next;p->next=q->next;          //删除指定结点
		e=q->data;
		printf("删除的元素为:%d\n",e);
		free(q);                            //释放该结点
	}
	void display(LNode *L)                    //输出链表中的元素
	{
		while(L->next)
		{
			L=L->next;
			printf("%d ",L->data);
		}
		printf("\n");
	}
	void Linklist(LNode *L)//链表从小到大排序
	{
		LNode *p,*q,*temp;
		temp=(LNode *)malloc(sizeof(LNode));
		p=L->next;q=p;
		while(p->next)
		{
			while(q)
			{
				if(p->data>q->data)
				{
					temp->data=p->data;
					p->data=q->data;
					q->data=temp->data;
				}
				q=q->next;
			}
			p=p->next;
			q=p;
		}
	}
	void MergeList_L(LNode *L1,LNode *L2,LNode *L3)
	{
		//已知单链线性表L1和L2的元素按值非递减排列。
		//归并L1和L2得到新的单链线性表L3，L3的元素也按值非递减排列
		LNode *p1,*p2,*p3;
		p1=L1->next;p2=L2->next;
		p3=L3;       //p3指向L3的头结点
		while(p1&&p2)
		{
			p3->next=(LNode *)malloc(sizeof(LNode));
			p3=p3->next;
			if(p1->data<p2->data)
			{
				p3->data=p1->data;p1=p1->next;
			}
			else if(p1->data==p2->data)
			{
				p3->data=p1->data;p1=p1->next;//p2=p2->next;//将p2=p2->next语句加上，则合并后的链表相同元素只保留一个
			}
			else
			{
				p3->data=p2->data;p2=p2->next;
			}
		}
		while(p1)                      //插入剩余段
		{
			p3->next=(LNode *)malloc(sizeof(LNode));
			p3=p3->next;
			p3->data=p1->data;
			p1=p1->next;
		}
	    while(p2)
		{
			p3->next=(LNode *)malloc(sizeof(LNode));
			p3=p3->next;
			p3->data=p2->data;
			p2=p2->next;
		}
		p3->next=NULL;              
		display(L3);                       //显示合并后的L3
	}
	void main()
	{
		LNode *L1,*L2,*L3;
		int e=0;
		L3=(LNode *)malloc(sizeof(LNode));
		printf("请输入链表L1的长度:");
		L1=build();
		printf("请输入链表L2的长度:");
		L2=build();
		Linklist(L1);
		Linklist(L2);
		printf("L1和L2合并后的链表L3为:\n");
		MergeList_L(L1,L2,L3);
		printf("链表L1为:");
		display(L1);
		//增、删、改、查都是在链表L1上操作的
		GetElem_L(L1,2,4);//查找L1第二个元素的值，并将其修改为4;
		printf("修改后的链表L1为:");
		display(L1);
		Insert(L1,3,5);//在链表L1的第三个元素之前插入5
		printf("插入后的链表L1为:");
		display(L1);		
		Delete(L1,1,e);//删除链表L1中的第一个元素，并将删除的元素的值赋给e
		printf("删除后的链表L1为:");
		display(L1);
	}
	
		