#pragma once
typedef int DataType;
typedef struct SeqList
{
	DataType*_pData;
	int _capacity;//����
	int _size;//��ЧԪ�صĸ���

}SeqList;

void SeqListInit(SeqList*pSeq, int capacity);//��ʼ��˳���
void PushBack(SeqList*pSeq, DataType data);//β��
void PopBack(SeqList*pSeq);//βɾ
void PushFront(SeqList*pSeq, DataType data);//ͷ��
void PopFront(SeqList*pSeq);//ͷɾ
void SeqListInsert(SeqList*pSeq, int pos, DataType data);//��ָ��λ�ò���Ԫ��
void SeqListErase(SeqList*pSeq, int pos);//��ָ��λ��ɾ��Ԫ��
int SeqListFind(SeqList*pSeq, DataType data); //��˳�������dataԪ�ص�һ�γ��ֵ�λ��
void SeqListRemove(SeqList*pSeq, DataType data);// ɾ��˳�����(��һ�γ��֣���ֵΪdata��Ԫ��
int SeqListSize(SeqList*pSeq);//��ȡ˳�������ЧԪ�صĸ���
int SeqListCapacity(SeqList*pSeq);//��ȡ˳��������
DataType SeqListFront(SeqList*pSeq);// ��ȡ˳����е�һ��Ԫ��
DataType SeqListListBack(SeqList*pSeq);//��ȡ˳��������һ��Ԫ��
void SeqListDestory(SeqList*pSeq);//����˳���
void SeqListClear(SeqList*pSeq);//���˳���
void _CheckCapacity(SeqList*pSeq);//�������
void SeqListRemoveAll(SeqList*pSeq, DataType data);//ɾ��˳���������ֵΪdata��Ԫ��
void BubbleSort(SeqList*pSeq);//��ð������ķ�ʽ��˳����е�Ԫ�ؽ�������
void Print(SeqList*pSeq);