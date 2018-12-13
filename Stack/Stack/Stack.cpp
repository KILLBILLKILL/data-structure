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

}STACK,*PSTACK;//PSTACK本身就等价于  struct Stack*
void innitStack(PSTACK);
void pushStack(PSTACK, int);
void traverseStack(PSTACK);
bool pop(PSTACK, int*);
void clear(PSTACK pS);
int main()
{
	STACK S;//STACK等价于 struct Stack
	int val;
	innitStack(&S);//目的是造出一个空栈
	pushStack(&S,1);//压栈
	pushStack(&S,2);
	pushStack(&S, 3);
	pushStack(&S, 4);
	pushStack(&S, 5);
	pushStack(&S,6);
	pushStack(&S, 7);
	pushStack(&S, 8);
	pushStack(&S, 9);
	traverseStack(&S);//遍历输出
	if (pop(&S, &val))
	{

		printf("出栈成功,出栈的值是%d\n", val);
	}
	else
	{
		printf("出栈失败");
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
		printf("动态内存分配失败");
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
	pNew->pNext = pS->pTop;//ps->Top 不能改成pS->Bottom
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
//把pS所指向的栈出栈一次,并把出栈的元素存入pVal形参所指向的变量中,如果出栈失败返回false,否则返回true
bool pop(PSTACK pS, int* pVal)
{
	if (empty(pS))//pS本身存放的就是S的地址
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
//清空
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
