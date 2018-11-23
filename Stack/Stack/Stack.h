#pragma once
#define N 3
typedef int SDataType;
//动态栈
typedef struct Stack
{
	SDataType*_array;
	int _capacity;//有效元素的最大个数
	int _top;//栈顶
}Stack;


void StackInit(Stack*ps);//栈的初始化
void _Checkcapacity(Stack*ps);//检测容量
void StackPush(Stack*ps, SDataType data);//压栈（在栈顶插入数据data)
void StackPop(Stack*ps);//出栈（在栈顶弹出数据data）
SDataType StackTop(Stack*ps);//取栈顶元素
int StackSize(Stack*ps);//获取栈中有效元素的个数
int StackEmpty(Stack*ps);//检测栈是否为空
void StackDeatory(Stack*ps);//销毁栈
void StackPrint(Stack*ps);//打印
