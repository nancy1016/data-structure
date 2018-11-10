#pragma once
typedef int DataType;
typedef struct SeqList
{
	DataType*_pData;
	int _capacity;//容量
	int _size;//有效元素的个数

}SeqList;

void SeqListInit(SeqList*pSeq, int capacity);//初始化顺序表
void PushBack(SeqList*pSeq, DataType data);//尾插
void PopBack(SeqList*pSeq);//尾删
void PushFront(SeqList*pSeq, DataType data);//头插
void PopFront(SeqList*pSeq);//头删
void SeqListInsert(SeqList*pSeq, int pos, DataType data);//在指定位置插入元素
void SeqListErase(SeqList*pSeq, int pos);//在指定位置删除元素
int SeqListFind(SeqList*pSeq, DataType data); //在顺序表中找data元素第一次出现的位置
void SeqListRemove(SeqList*pSeq, DataType data);// 删除顺序表中(第一次出现）的值为data的元素
int SeqListSize(SeqList*pSeq);//获取顺序表中有效元素的个数
int SeqListCapacity(SeqList*pSeq);//获取顺序表的容量
DataType SeqListFront(SeqList*pSeq);// 获取顺序表中第一个元素
DataType SeqListListBack(SeqList*pSeq);//获取顺序表中最后一个元素
void SeqListDestory(SeqList*pSeq);//销毁顺序表
void SeqListClear(SeqList*pSeq);//清空顺序表
void _CheckCapacity(SeqList*pSeq);//检测容量
void SeqListRemoveAll(SeqList*pSeq, DataType data);//删除顺序表中所有值为data的元素
void BubbleSort(SeqList*pSeq);//用冒泡排序的方式对顺序表中的元素进行排序
void Print(SeqList*pSeq);