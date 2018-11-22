#ifndef __DList_H_
#define __DList_H_


typedef int DataType;
typedef struct DListNode
{
	DataType _data;
	struct DListNode* _pPre;
	struct DListNode* _pNext;
}DListNode;


DListNode*BuyDListNode(DataType data);//�����½ڵ�
void DListInit(DListNode**plist);//��ʼ��
void DListPushBack(DListNode*plist, DataType data);//β��
void DListPopBack(DListNode*plist);//βɾ
void DListPushFront(DListNode*plist, DataType data);//ͷ��
void DListPopFront(DListNode*plist);//ͷɾ
DListNode*DListFind(DListNode*plist, DataType data);//����ָ��Ԫ��
void DListInsert(DListNode* pos, DataType data);//��pos��ǰ����в���
void DListErase(DListNode* pos);//ɾ��posλ�õĽڵ�
void DListRemove(DListNode* plist, DataType data);//ɾ��ָ��Ԫ�صĽڵ�

void DListPrint(DListNode*plist);




//��һ�ֶ��巽ʽ
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