#ifndef __DList_H_
#define __DList_H_


typedef int DataType;
typedef struct DListNode
{
	DataType _data;
	struct DListNode* _pPre;
	struct DListNode* _pNext;
}DListNode;


DListNode*BuyDListNode(DataType data);//构造新节点
void DListInit(DListNode**plist);//初始化
void DListPushBack(DListNode*plist, DataType data);//尾插
void DListPopBack(DListNode*plist);//尾删
void DListPushFront(DListNode*plist, DataType data);//头插
void DListPopFront(DListNode*plist);//头删
DListNode*DListFind(DListNode*plist, DataType data);//查找指定元素
void DListInsert(DListNode* pos, DataType data);//在pos的前面进行插入
void DListErase(DListNode* pos);//删除pos位置的节点
void DListRemove(DListNode* plist, DataType data);//删除指定元素的节点

void DListPrint(DListNode*plist);




//另一种定义方式
//typedef int DLDataType;
//typedef struct DListNode
//{
//	DLDataType _data;
//	struct DListNode*_pNext;
//	struct DListNode*_pPre;
//}DListNode;
//
//typedef struct DList
//{
//	struct DListNode*_pHead;
//}DList;
//
//DListNode*BuyDListNode(DLDataType data);
//void ListInit(DList*plist);


#endif