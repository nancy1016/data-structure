#pragma once
#define N 3
typedef int SDataType;
//��̬ջ
typedef struct Stack
{
	SDataType*_array;
	int _capacity;//��ЧԪ�ص�������
	int _top;//ջ��
}Stack;


void StackInit(Stack*ps);//ջ�ĳ�ʼ��
void _Checkcapacity(Stack*ps);//�������
void StackPush(Stack*ps, SDataType data);//ѹջ����ջ����������data)
void StackPop(Stack*ps);//��ջ����ջ����������data��
SDataType StackTop(Stack*ps);//ȡջ��Ԫ��
int StackSize(Stack*ps);//��ȡջ����ЧԪ�صĸ���
int StackEmpty(Stack*ps);//���ջ�Ƿ�Ϊ��
void StackDeatory(Stack*ps);//����ջ
void StackPrint(Stack*ps);//��ӡ
