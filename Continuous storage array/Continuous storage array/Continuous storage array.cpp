
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//������һ���������ͣ����������͵����ֽ���  struct Arr,���������ͺ���������Ա
struct  Arr//�ṹ���Ǹ��ϵ���������
{
	int* pBase;//�洢���������һ��Ԫ�صĵ�ַ
	int len;//�����������ɵ����Ԫ�صĸ���
	int cent;//��ǰ������ЧԪ�صĸ���
};
void innit_arr(struct  Arr* pArr, int length);
bool append_arr(struct  Arr* pArr, int val);//׷��
bool insert_arr(struct  Arr* pArr, int pos, int val); //����  pos��ֵ��1��ʼ  ��ǰ���λ�ò���
bool delete_arr(struct  Arr* pArr, int pos, int* pVal);//ɾ��
int get();
bool is_empty(struct  Arr* pArr);
bool is_full(struct  Arr* pArr);
void sort_arr(struct  Arr* pArr);//����
void show_arr(struct  Arr* pArr);
void inversion_arr(struct  Arr* pArr);
int main()
{
	struct  Arr arr;
	int val;
	innit_arr(&arr, 6);
	is_empty(&arr);
	show_arr(&arr);
	append_arr(&arr, 1);
	append_arr(&arr, 10);
	append_arr(&arr, -3);
	append_arr(&arr, 6);
	append_arr(&arr, 88);
	append_arr(&arr, 11);
	if (delete_arr(&arr, 4, &val))
	{
		printf("ɾ���ɹ�\n");
		printf("��ɾ���ɹ���Ԫ����%d\n", val);
	}
	else
	{
		printf("ɾ��ʧ��\n");

	}
	/*append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	insert_arr(&arr, 6, 99);*/
	show_arr(&arr);
	inversion_arr(&arr);
	printf("����֮�������������\n");
	show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);
	system("pause");
	return 0;
}
void innit_arr(struct  Arr* pArr, int length)
{
	pArr->pBase = (int*)malloc(sizeof(int)*length);
	if (NULL == pArr->pBase)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);//��ֹ��������
	}
	else
	{
		pArr->len = length;
		pArr->cent = 0;
	}
	return;
}
bool is_empty(struct  Arr* pArr)
{
	if (0 == pArr->cent)
		return true;
	else
		return false;
}
bool is_full(struct  Arr* pArr)
{
	if (pArr->cent == pArr->len)
		return true;
	else
		return false;
}
void show_arr(struct  Arr* pArr)
{
	if (is_empty(pArr))
	{
		printf("����Ϊ��!\n");
	}
	else
	{
		for (int i = 0; i < pArr->cent; ++i)
		{
			printf("%d ", pArr->pBase[i]);// int*
		}
		printf("\n");
	}
}
bool append_arr(struct  Arr* pArr, int val)
{
	//��ʱ����false
	if (is_full(pArr))
		return false;
	//������ʱ��׷��
	pArr->pBase[pArr->cent] = val;
	(pArr->cent)++;
	return true;
}
bool insert_arr(struct  Arr* pArr, int pos, int val)
{
	int i;
	if (is_full(pArr))
		return false;
	if (pos<1 || pos>pArr->cent + 1)
		return false;
	for (i = pArr->cent - 1; i >= pos - 1; --i)
	{
		pArr->pBase[i + 1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val;
	(pArr->cent)++;
	return true;
}
bool delete_arr(struct  Arr* pArr, int pos, int* pVal)
{
	int i;
	if (is_empty(pArr))
		return false;
	if (pos<1 || pos>pArr->cent)
		return false;
	*pVal = pArr->pBase[pos - 1];
	for (i = pos; i < pArr->cent; ++i)
	{
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	pArr->cent--;
	return true;
}
void inversion_arr(struct  Arr* pArr)
{
	int i = 0;
	int j = pArr->cent - 1;
	int t;
	while (i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;
}
void sort_arr(struct  Arr* pArr)
{
	int i, j, t;
	for (i = 0; i<pArr->cent; ++i)
	{
		for (j = i + 1; j < pArr->cent; ++j)
		{
			if (pArr->pBase[i]>pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
}
