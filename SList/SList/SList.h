#ifndef __SLIST_H__
#define __SLIST_H__

typedef int SLDataType;
typedef struct SListNode
{
	SLDataType _data;
	struct SListNode*_pNext;
}SListNode;


void SListInit(SListNode*pList);//初始化
void SListPushBack(SListNode**pList, SLDataType data);//尾插
void SListPopBack(SListNode**pList);//尾删
void SListPrint(SListNode*pList);//打印链表
void SListPushFront(SListNode**pList, SLDataType data);//头插
void SListPopFront(SListNode**pList);//头删
SListNode*SListFind(SListNode*pList, SLDataType data);//查找
void SListInsert(SListNode*pos,SLDataType data);//在指定位置插入元素(pos后面)
void SListErase(SListNode**pList, SListNode*pos);//在指定位置删除元素
void SListDestory(SListNode**pList);//销毁
int SListSize(SListNode*pList);//统计节点个数
int SListEmpty(SListNode*pList);//判断链表中的元素是否为空
SLDataType Front(SListNode*pList);//取首元素
SLDataType Back(SListNode*pList);//取尾元素
void SListRemove(SListNode**pList, SLDataType data);//删除指定元素的节点
void SListRemoveAll(SListNode**pList,SLDataType data);//删除元素为data的所有节点
void BubbleSort(SListNode*pList);//冒泡排序



#endif