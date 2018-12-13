#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct  Node
{
	int data;//������
	struct Node*pNext;//ָ����

}NODE, *PNODE;//NODE�ȼ���   struct  Node    PNODE�ȼ���  struct  Node*
PNODE creat_list();//��������
void traverse_list(PNODE pHead);//��������
bool is_empty(PNODE pHead);//�ж��Ƿ�Ϊ��
int length_list(PNODE pHead);//������ĳ���
bool insert_list(PNODE, int, int);//���� //��pHead��ָ������ĵ�pos���ڵ��ǰ�����һ���µĽڵ�	,�ýڵ��ֵ�� Val   �±�ӿ�ʼ
bool delete_list(PNODE, int, int*);//ɾ��
void sort_list(PNODE);//����
int main()
{
	int val;
	PNODE pHead = NULL;//�ȼ���   struct  Node* pHead = NULL
	pHead = creat_list();//creat_list()�Ĺ��� ����һ����ѭ�������� �������������ͷ���ĵ�ַ��ֵ��pHead
	traverse_list(pHead);//����  
	int len = length_list(pHead);
	printf("����ĳ�����%d\n", len);
	if (is_empty(pHead))
		printf("����Ϊ��!\n");
	else
		printf("�����ǿյ�\n");
	sort_list(pHead);
	traverse_list(pHead);
	insert_list(pHead, 4, 666);
	traverse_list(pHead);
	if (delete_list(pHead, 3, &val))
	{
		printf("ɾ���ɹ�,��ɾ����Ԫ����%d\n",val);
	}
	else
	{
		printf("ɾ��ʧ��\n");

	}
	traverse_list(pHead);
	system("pause"); 
	return 0;
}
PNODE creat_list()
{
	int len;//���������Ч�ڵ�ĸ���
	int i;
	int val;//������ʱ����û�����Ľ���ֵ
    //������
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("����ʧ��,������ֹ\n");
		exit( -1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("����������Ҫ���ɵ�������ĸ�����len=\n");
	scanf_s("%d", &len);
	for (i = 0; i < len; ++i)
	{
		printf("�������%d���ڵ��ֵ\n",i+1);
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pHead)
		{
			printf("����ʧ�� ���������ֹ!\n");
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
//��pHead��ָ������ĵ�pos���ڵ��ǰ�����һ���µĽڵ�	,�ýڵ��ֵ�� Val   �±�ӿ�ʼ
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
		printf("����ʧ�� ���������ֹ!\n");
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
	//ɾ��P�ڵ����Ľڵ�
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;



}