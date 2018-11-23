#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//ջ�ĳ�ʼ��
void StackInit(Stack*ps)
{
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)*N);
	if (ps->_array == NULL)
	{
		exit(1);
	}
	ps->_capacity = N;
	ps->_top = 0;
}

void _Checkcapacity(Stack*ps)
{
	//���ռ����������������
	if (ps->_top == ps->_capacity)
	{
		int New_capacity = ps->_capacity * 2;
		ps->_array = (SDataType*)realloc(ps->_array, sizeof(SDataType)*New_capacity);
		if (ps->_array == NULL)
		{
			exit(1);
		}
		ps->_capacity = New_capacity;
	}
}


//ѹջ����ջ����������data)
void StackPush(Stack*ps, SDataType data)
{
	assert(ps);
	_Checkcapacity(ps);
	ps->_array[ps->_top] = data;
	ps->_top++;
}

//��ջ����ջ����������data��
void StackPop(Stack*ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	/*if (ps->_top == 0)
	{
		return;
	}*/
	ps->_top--;
}


//ȡջ��Ԫ��
SDataType StackTop(Stack*ps)
{
	assert(ps);
	//��ջΪ��
	assert(!StackEmpty(ps));
	//ջ��Ϊ��
	return ps->_array[ps->_top-1];
}




//��ȡջ����ЧԪ�صĸ���
int StackSize(Stack*ps)
{
	assert(ps);
	return ps->_top;
}




//���ջ�Ƿ�Ϊ��(Ϊ�շ���1����Ϊ�շ���0��
int StackEmpty(Stack*ps)
{
	assert(ps);
	return ps->_top == 0;
}




//����ջ
void StackDeatory(Stack*ps)
{
	assert(ps);
	free(ps->_array);
	ps->_capacity = 0;
	ps->_top = 0;
}
//��ӡ
void StackPrint(Stack*ps)
{
	assert(ps);
	for (int i = 0; i < ps->_top; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}









//void StackInit(Stack*ps)
//{
//	assert(ps);
//	ps->_array = (SDataType*)malloc(sizeof(SDataType)*3);
//	if (ps->_array == NULL)
//	{
//		exit(1);
//	}
//	ps->_capacity = 3;
//	ps->_top = 0;
//}

