#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct  Node
{
	int data;//数据域
	struct Node*pNext;//指针域

}NODE, *PNODE;//NODE等价于   struct  Node    PNODE等价于  struct  Node*
PNODE creat_list();//创建链表
void traverse_list(PNODE pHead);//遍历链表
bool is_empty(PNODE pHead);//判断是否为空
int length_list(PNODE pHead);//求链表的长度
bool insert_list(PNODE, int, int);//增加 //在pHead所指向链表的第pos个节点的前面插入一个新的节点	,该节点的值是 Val   下标从开始
bool delete_list(PNODE, int, int*);//删除
void sort_list(PNODE);//排序
int main()
{
	int val;
	PNODE pHead = NULL;//等价于   struct  Node* pHead = NULL
	pHead = creat_list();//creat_list()的功能 创建一个非循环单链表 ，并将该链表的头结点的地址赋值给pHead
	traverse_list(pHead);//遍历  
	int len = length_list(pHead);
	printf("链表的长度是%d\n", len);
	if (is_empty(pHead))
		printf("链表为空!\n");
	else
		printf("链表不是空的\n");
	sort_list(pHead);
	traverse_list(pHead);
	insert_list(pHead, 4, 666);
	traverse_list(pHead);
	if (delete_list(pHead, 3, &val))
	{
		printf("删除成功,您删除的元素是%d\n",val);
	}
	else
	{
		printf("删除失败\n");

	}
	traverse_list(pHead);
	system("pause"); 
	return 0;
}
PNODE creat_list()
{
	int len;//用来存放有效节点的个数
	int i;
	int val;//用来临时存放用户输入的结点的值
    //分配了
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("分配失败,程序终止\n");
		exit( -1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("请输入您想要生成的链表结点的个数：len=\n");
	scanf_s("%d", &len);
	for (i = 0; i < len; ++i)
	{
		printf("请输入第%d个节点的值\n",i+1);
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pHead)
		{
			printf("分配失败 程序必须终止!\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;

	}

	return pHead;

}
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;

	while (NULL != p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}
bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
	

}
int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;
	while (NULL != p)
	{
		++len;
		p = p->pNext;

	}
	return len;
}
void sort_list(PNODE pHead)
{
	int i, j, t;
	int len = length_list( pHead);
	PNODE p, q;
	for (i = 0, p = pHead->pNext; i < len - 1; ++i,p = p->pNext)
	{
		for (j = i + 1, q = p->pNext; j < len; ++j, q = q->pNext)
		{
			if (p->data>q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}


}
//在pHead所指向链表的第pos个节点的前面插入一个新的节点	,该节点的值是 Val   下标从开始
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p&&i < pos - 1)
	{
		p = p->pNext;
		++i;
	}
	if (i>pos - 1 || NULL == p)
	{
		return false;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("分配失败 程序必须终止!\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	return true;

}
bool delete_list(PNODE pHead, int pos, int* pval)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p->pNext&&i < pos - 1)
	{
		p = p->pNext;
		++i;
	}
	if (i>pos - 1 || NULL == p->pNext)
	{
		return false;
	}
	PNODE q = p->pNext;
	*pval = q->data;
	//删除P节点后面的节点
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;



}