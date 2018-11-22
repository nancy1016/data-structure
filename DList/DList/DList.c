#include"DList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//�����½ڵ�
DListNode*BuyDListNode(DataType data)
{
	DListNode*pNewNode = (DListNode*)malloc(sizeof(DListNode));
	if (pNewNode == NULL)
	{
		exit(1);
	}
	pNewNode->_data = data;
	pNewNode->_pPre = NULL;
	pNewNode->_pNext = NULL;
	return pNewNode;

}

//��ʼ��
void DListInit(DListNode**plist)
{
	assert(plist);
	DListNode*pHead = BuyDListNode(0);
	pHead->_pNext = pHead;
	pHead->_pPre = pHead;
	*plist = pHead;
}


//β��
void DListPushBack(DListNode*plist, DataType data)
{
	//˼·��plist��Ϊָ������׽ڵ㣬ֻ���ڹ̶��������ʼλ�ã�����Ԫ�ض���ֱ�Ӳ���plist֮��
	//���ӽڵ��˼�룺Ҫ�ҵ���ǰ���һ���ڵ㣬�޸�4��ָ����
	//�����ȶϿ��ĸ��ڵ㣺ʼ�հ��ա��ҵ�ǰ���һ���ڵ�λ�á�ʹ����Ϻ��ٶϿ�ԭ����
	DListNode*pNewNode = BuyDListNode(data);
	plist->_pPre->_pNext = pNewNode;
	pNewNode->_pPre = plist->_pPre;
	pNewNode->_pNext = plist;
	plist->_pPre = pNewNode;

}

//βɾ
void DListPopBack(DListNode*plist)
{
	//���ﲻ�÷��������head����ֻ��һ���ڵ㻹�Ƕ���ڵ㣬��Ϊheadʼ������ǰ�棬���ᱻɾ
		plist->_pPre->_pPre->_pNext = plist;
		plist->_pPre = plist->_pPre->_pPre;
}


//ͷ��
void DListPushFront(DListNode*plist, DataType data)
{
	//˼·:�ҵ���ǰ��һ���ڵ㣨��ͷ��������Ǹ��ڵ㣩Ȼ������
	//���ӷ�ʽ�������Ӻ��棬������ǰ��
	DListNode*pNewNode = BuyDListNode(data);
	pNewNode->_pNext = plist->_pNext;
	plist->_pNext->_pPre = pNewNode;
	plist->_pNext = pNewNode;
	pNewNode->_pPre = plist;

}


//ͷɾ
void DListPopFront(DListNode*plist)
{
	//˼·���ҵ�ǰ��һ���ڵ����һ���ڵ㣬��ΪҪ�ı�����ָ��ָ��
	//�Ӻ���ǰ��
	plist->_pNext->_pNext->_pPre = plist;
	plist->_pNext = plist->_pNext->_pNext;
}

//��ӡ
void DListPrint(DListNode*plist)
{
	DListNode*cur = plist->_pNext;
	while (cur != plist)
	{
		printf("%d->", cur->_data);
		cur = cur->_pNext;
	}
	printf("NULL\n");
}


//����ָ��Ԫ��
DListNode*DListFind(DListNode*plist, DataType data)
{
	//��û����Ч�ڵ�(��ֻ��һ���׽ڵ�)
	if (plist->_pNext == plist)
	{
		return NULL;
	}
	DListNode*cur =plist->_pNext;//��ʼλ����ͷ������һ��λ��
	while (cur!= plist)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		cur = cur->_pNext;
	}
	return NULL;
}


//��pos��ǰ����в���
void DListInsert(DListNode* pos, DataType data)
{
	DListNode*pNewNode = BuyDListNode(data);
	if (pos == NULL)
	{
		exit(1);
	}
	pNewNode->_pNext = pos;
	pos->_pPre->_pNext = pNewNode;
	pNewNode->_pPre = pos->_pPre;
	pos->_pPre = pNewNode;
}

//ɾ��posλ�õĽڵ�
void DListErase(DListNode* pos)
{
	if (pos == NULL)
	{
		exit(1);
	}
	//���ҵ�posǰ�ߵĽڵ㣬��posǰ�߽ڵ��ָ������pos��߽ڵ�������
	//Ȼ��pos��߽ڵ��preָ����posǰ�߽ڵ�������
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;

}


//ɾ��ָ��Ԫ�صĽڵ�
void DListRemove(DListNode* plist, DataType data)
{
	//���ҵ�Ԫ�����ڵĽڵ�λ�ã�Ȼ�����DListErase����ɾ��
	DListNode*pos = DListFind(plist, data);
	if (pos==NULL)
	{
		exit(1);
	}
	DListErase(pos);
}







