#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node*pNext;


}NODE,*PNODE;	
typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;

}STACK,*PSTACK;//PSTACK����͵ȼ���  struct Stack*
void innitStack(PSTACK);
void pushStack(PSTACK, int);
void traverseStack(PSTACK);
bool pop(PSTACK, int*);
void clear(PSTACK pS);
int main()
{
	STACK S;//STACK�ȼ��� struct Stack
	int val;
	innitStack(&S);//Ŀ�������һ����ջ
	pushStack(&S,1);//ѹջ
	pushStack(&S,2);
	pushStack(&S, 3);
	pushStack(&S, 4);
	pushStack(&S, 5);
	pushStack(&S,6);
	pushStack(&S, 7);
	pushStack(&S, 8);
	pushStack(&S, 9);
	traverseStack(&S);//�������
	if (pop(&S, &val))
	{

		printf("��ջ�ɹ�,��ջ��ֵ��%d\n", val);
	}
	else
	{
		printf("��ջʧ��");
	}
	traverseStack(&S);
	clear(&S);
	traverseStack(&S);
	
	system("pause");
	return 0;
}
void innitStack(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop)
	{
		printf("��̬�ڴ����ʧ��");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pBottom->pNext = NULL;//pS->pTop->pNext=NULL


	}


}
void pushStack(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;//ps->Top ���ܸĳ�pS->Bottom
	pS->pTop = pNew;

	return;


}
void traverseStack(PSTACK pS)
{
	PNODE p = pS->pTop;
	while (p != pS->pBottom)
	{
		printf("%d ", p->data);
		p=p->pNext;

	}
	printf("\n");
	return;


}
bool empty(PSTACK pS)
{
	if (pS->pBottom == pS->pTop)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//��pS��ָ���ջ��ջһ��,���ѳ�ջ��Ԫ�ش���pVal�β���ָ��ı�����,�����ջʧ�ܷ���false,���򷵻�true
bool pop(PSTACK pS, int* pVal)
{
	if (empty(pS))//pS�����ŵľ���S�ĵ�ַ
	{
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;

		return true;
	}

}
//���
void clear(PSTACK pS)
{
	if (empty(pS))
	{
		return;
	}
	else
	{

		PNODE p = pS->pTop;
		PNODE q = NULL;
		while (p != pS->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;

		}
		pS->pBottom= pS->pTop;
	}
}
