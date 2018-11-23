#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//栈的初始化
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
	//若空间已满，则进行扩容
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


//压栈（在栈顶插入数据data)
void StackPush(Stack*ps, SDataType data)
{
	assert(ps);
	_Checkcapacity(ps);
	ps->_array[ps->_top] = data;
	ps->_top++;
}

//出栈（在栈顶弹出数据data）
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


//取栈顶元素
SDataType StackTop(Stack*ps)
{
	assert(ps);
	//若栈为空
	assert(!StackEmpty(ps));
	//栈不为空
	return ps->_array[ps->_top-1];
}




//获取栈中有效元素的个数
int StackSize(Stack*ps)
{
	assert(ps);
	return ps->_top;
}




//检测栈是否为空(为空返回1，不为空返回0）
int StackEmpty(Stack*ps)
{
	assert(ps);
	return ps->_top == 0;
}




//销毁栈
void StackDeatory(Stack*ps)
{
	assert(ps);
	free(ps->_array);
	ps->_capacity = 0;
	ps->_top = 0;
}
//打印
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

