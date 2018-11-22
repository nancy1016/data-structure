#include"DList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//构造新节点
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

//初始化
void DListInit(DListNode**plist)
{
	assert(plist);
	DListNode*pHead = BuyDListNode(0);
	pHead->_pNext = pHead;
	pHead->_pPre = pHead;
	*plist = pHead;
}


//尾插
void DListPushBack(DListNode*plist, DataType data)
{
	//思路：plist因为指向的是首节点，只用于固定链表的起始位置，其他元素都是直接插在plist之后
	//连接节点的思想：要找到当前最后一个节点，修改4个指针域
	//具体先断开哪个节点：始终把握“找当前最后一个节点位置”使用完毕后，再断开原连接
	DListNode*pNewNode = BuyDListNode(data);
	plist->_pPre->_pNext = pNewNode;
	pNewNode->_pPre = plist->_pPre;
	pNewNode->_pNext = plist;
	plist->_pPre = pNewNode;

}

//尾删
void DListPopBack(DListNode*plist)
{
	//这里不用分情况讨论head后面只有一个节点还是多个节点，因为head始终在最前面，不会被删
		plist->_pPre->_pPre->_pNext = plist;
		plist->_pPre = plist->_pPre->_pPre;
}


//头插
void DListPushFront(DListNode*plist, DataType data)
{
	//思路:找到当前第一个节点（即头结点后面的那个节点）然后连接
	//连接方式：先连接后面，再连接前面
	DListNode*pNewNode = BuyDListNode(data);
	pNewNode->_pNext = plist->_pNext;
	plist->_pNext->_pPre = pNewNode;
	plist->_pNext = pNewNode;
	pNewNode->_pPre = plist;

}


//头删
void DListPopFront(DListNode*plist)
{
	//思路：找当前第一个节点的下一个节点，因为要改变它的指针指向
	//从后向前链
	plist->_pNext->_pNext->_pPre = plist;
	plist->_pNext = plist->_pNext->_pNext;
}

//打印
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


//查找指定元素
DListNode*DListFind(DListNode*plist, DataType data)
{
	//若没有有效节点(即只有一个首节点)
	if (plist->_pNext == plist)
	{
		return NULL;
	}
	DListNode*cur =plist->_pNext;//初始位置在头结点的下一个位置
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


//在pos的前面进行插入
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

//删除pos位置的节点
void DListErase(DListNode* pos)
{
	if (pos == NULL)
	{
		exit(1);
	}
	//先找到pos前边的节点，将pos前边节点的指针域与pos后边节点相连接
	//然后将pos后边节点的pre指针域pos前边节点相连接
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;

}


//删除指定元素的节点
void DListRemove(DListNode* plist, DataType data)
{
	//先找到元素所在的节点位置，然后调用DListErase函数删除
	DListNode*pos = DListFind(plist, data);
	if (pos==NULL)
	{
		exit(1);
	}
	DListErase(pos);
}







