#ifndef __SLIST_H__
#define __SLIST_H__

typedef int SLDataType;
typedef struct SListNode
{
	SLDataType _data;
	struct SListNode*_pNext;
}SListNode;


void SListInit(SListNode*pList);//��ʼ��
void SListPushBack(SListNode**pList, SLDataType data);//β��
void SListPopBack(SListNode**pList);//βɾ
void SListPrint(SListNode*pList);//��ӡ����
void SListPushFront(SListNode**pList, SLDataType data);//ͷ��
void SListPopFront(SListNode**pList);//ͷɾ
SListNode*SListFind(SListNode*pList, SLDataType data);//����
void SListInsert(SListNode*pos,SLDataType data);//��ָ��λ�ò���Ԫ��(pos����)
void SListErase(SListNode**pList, SListNode*pos);//��ָ��λ��ɾ��Ԫ��
void SListDestory(SListNode**pList);//����
int SListSize(SListNode*pList);//ͳ�ƽڵ����
int SListEmpty(SListNode*pList);//�ж������е�Ԫ���Ƿ�Ϊ��
SLDataType Front(SListNode*pList);//ȡ��Ԫ��
SLDataType Back(SListNode*pList);//ȡβԪ��
void SListRemove(SListNode**pList, SLDataType data);//ɾ��ָ��Ԫ�صĽڵ�
void SListRemoveAll(SListNode**pList,SLDataType data);//ɾ��Ԫ��Ϊdata�����нڵ�


//typedef int SLDataType;
//typedef struct SListNode
//{
//	SLDataType _data;
//	struct SListNode*_pNext;
//}SListNode;


//void SListInit(SListNode**pHead);
//void SListPushBack(SListNode*pHead, SLDataType data);
//void SListPopBack(SListNode**pHead);
//void SListPushFront(SListNode**pHead, SLDataType data);
//void SListPopFront(SListNode**pHead, SLDataType data);
//SListNode*SListFind(SListNode*pHead, SLDataType data);
//void SListInsert(SListNode*pos, SLDataType data);
//void SListErase(SListNode**pHead, SListNode*pos);//Ҫ��pHead����������Ϊ���ɾ�Ľڵ��ǵ�һ���ڵ�
//void SListDestory(SListNode**pHead);
//int SListSize(SListNode*pHead);
//int SListEmpty(SListNode*pHead);
//SLDataType Front(SListNode*pHead);
//SLDataType Back(SListNode*pHead);
//void SListRemove()



#endif