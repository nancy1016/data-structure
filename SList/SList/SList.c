#include"SList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//初始化
void SListInit(SListNode*pList)
{
	//pList = (SListNode*)malloc(sizeof(SListNode));
	//pList->_data = 3;
	//pList->_pNext = NULL;
	pList=NULL;
}


//构造一个节点
SListNode* BuySListNode(SLDataType data)
{
	SListNode*pNewNode = (SListNode*)malloc(sizeof(SListNode));
	if (pNewNode == NULL)
	{
		printf("申请空间失败");
		exit(1);
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
//尾插
//注意：这里一定要传二级指针
void SListPushBack(SListNode**pList, SLDataType data)
{
	//pList为空的情况：
	//（1）手动传空
	//（2）创造节点时没有空间开辟成功，返回一级指针为空，所以二级指针自然为空
	//但是这里由于我们在BuySListNode函数内部开辟空间失败时直接exit了，所以这句不加也无所谓
	assert(pList);

	//链表为空时，相当于插入第一个节点，直接链上去即可
	SListNode*newNode = BuySListNode(data);
	if (*pList == NULL)
	{
		*pList = newNode;
	}
	//链表不为空时，遍历链表，直到找到原最后一个节点，然后把新节点链上去
	else
	{
		SListNode*cur = *pList;
		while (cur->_pNext)
		{
			cur = cur->_pNext;
		}
		//已经到达原来最后一个节点处
		cur->_pNext = newNode;
	}
	
}


//尾删
void SListPopBack(SListNode**pList)
{
	if (*pList == NULL)
	{
		printf("链表为空，无法删除元素\n");
		exit(1);
	}
	else
	{
		//只有一个节点
		SListNode*cur = *pList;
		if (cur->_pNext == NULL)
		{
			*pList = NULL;
		}
		//有多个节点
		else
		{
			while (cur->_pNext->_pNext)
			{
				cur = cur->_pNext;
			}
			//到这一步已经走到了倒数第二个元素，我们需要把它的_next置空
			//（注意千万不能走到最后一个元素，不然没法删；这里的关键其实是对倒数第二个元素的next域做处理）
			cur->_pNext = NULL;
		}
	}
}


//头插
void SListPushFront(SListNode**pList, SLDataType data)
{
	SListNode*newNode = BuySListNode(data);
	//情况一：链表为空-->直接链上去
	if (*pList == NULL)
	{
		*pList = newNode;
	}
	//情况二：链表不为空-->要考虑前后的连接性:先链后面，在链前面
	else
	{
		SListNode*cur = *pList;
		newNode->_pNext = cur;
		*pList= newNode;//注意这里一定要更新*pList的指向。不能是cur=newNode
	}
}


//头删
void SListPopFront(SListNode**pList)
{
	if (*pList == NULL)
	{
		printf("链表为空，无法删除元素\n");
		exit(1);
	}
	//情况一：只有一个节点,删除后注意*pList要置空
	SListNode*cur = *pList;
	if (cur->_pNext == NULL)
	{
		*pList = NULL;
	}
	//情况二：有多个节点，删除时要更新*pList的指向
	*pList = cur->_pNext;
	free(cur);
	cur = NULL;
}


//查找
SListNode*SListFind(SListNode*pList, SLDataType data)
{
	if (pList == NULL)
	{
		printf("链表为空\n");
		exit(1);
	}
	SListNode*cur = pList;
	while (cur)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		cur = cur->_pNext;
	}
	return NULL;
}

//在指定位置插入元素(pos后面)
//这里不传二级指针的原因是：没有传入SListNode*pList（即链表的起始位置）
//只有需要传入整个链表的时候才要传二级指针
void SListInsert(SListNode*pos, SLDataType data)
{
	SListNode*newNode = BuySListNode(data);
	if (pos == NULL)
	{
		return;
	}
	//这里最靠前的也在第一个元素后面插入，所以情况比较简单，不需要细分
	//在第一个元素后面插入时，newNode->_pNext = pos->_pNext;也不影响，因为pos->_pNext==NULL；
	newNode->_pNext = pos->_pNext;
	pos->_pNext = newNode;
}


//在指定位置删除元素
void SListErase(SListNode**pList, SListNode*pos)
{
	//思路：分两种情况
	//(1)头删
	//(2)其他位置删

	if (*pList==pos)
	{
		*pList = pos->_pNext;
	}
	else
	{
		//找到pos前一个位置
		SListNode*pre = *pList;
		while (pre->_pNext!=pos)
		{
			pre = pre->_pNext;
		}
		pre->_pNext = pos->_pNext;
	}
	free(pos);
	pos = NULL;
}


//销毁
void SListDestory(SListNode**pList)
{
	SListNode*cur = *pList;
	SListNode*pre = cur;//每次cur移动之前都保存前一个位置，方便删除
	while (cur)
	{
		pre = cur;
		cur = cur->_pNext;
		free(pre);
		*pList = cur;//每删掉一个元素都要注意更新头指针的位置
	}


	//简便写法
	/*SListNode*cur = *pList;
	while (*pList)
	{
		cur = *pList;
		*pList = cur->_pNext;
		free(cur);
	}*/

}


//统计节点个数
int SListSize(SListNode*pList)
{
	int count = 0;
	SListNode*cur = pList;
	while (cur)
	{
		count++;
		cur = cur->_pNext;
	}
	return count;
}
//判断链表中的元素是否为空
int SListEmpty(SListNode*pList)
{
	return pList == NULL;
}



//取首元素
SLDataType Front(SListNode*pList)
{
	assert(pList);
	return pList->_data;
}


//取尾元素
SLDataType Back(SListNode*pList)
{
	assert(pList);
	SListNode*cur = pList;
	while (cur->_pNext)
	{
		cur = cur->_pNext;
	}
	return cur->_data;
}

void SListPrint(SListNode*pList)
{
	while (pList)
	{
		printf("%d->", pList->_data);
		pList = pList->_pNext;
	}
	printf("NULL\n");
}


//删除指定元素的节点
//思路：只用区分两种情况（1）删除首节点（2）删除的不是首节点
//不需要按照链表里总共有的节点数讨论
void SListRemove(SListNode**pList, SLDataType data)
{
	SListNode*cur = *pList;
	SListNode*pre = cur;
	while (cur)
	{
		if (cur->_data == data)
		{
			//如果删除的是第一个节点
			if (cur == *pList)
			{
				*pList = cur->_pNext;
			}
			//如果删除的不是第一个节点
			else
			{
				pre->_pNext = cur->_pNext;
			}
			free(cur);
			cur = NULL;
		}
		else
		{
			pre = cur;
			cur = cur->_pNext;
		}
	}
}


//删除元素为data的所有节点
//思路：基本与SListRemove一致，唯一有区别的是：每次删除后不能把cur置空，因为还要继续遍历之后的节点
void SListRemoveAll(SListNode**pList, SLDataType data)
{
	if (*pList == NULL)
	{
		exit(1);
	}
	SListNode*cur = *pList;
	SListNode*pre = cur;
	while (cur)
	{
		if (cur->_data == data)
		{
			//如果删除的是第一个节点
			if (cur == *pList)
			{
				*pList = cur->_pNext;
				free(cur);
				cur = *pList;//不能将cur置空，因为还要遍历之后的节点，这时就要更新cur位置
			}
			//如果删除的不是第一个节点
			else
			{
				pre->_pNext = cur->_pNext;
				free(cur);
				cur = pre->_pNext;//删除后，cur还要继续遍历之后的节点，所以应该更新cur位置
			}
		}
		else
		{
			pre = cur;
			cur = cur->_pNext;
		}
	}

}


//冒泡排序思路：
//每一趟比较：定义两个指针，用于比较元素，进行交换。每一趟都能把一个元素归到最后一位
//总共趟数的控制：定义一个ptail指针，限定比较范围
void Swap(SListNode* pre, SListNode* cur)
{
	SLDataType tmp;
	tmp = pre->_data;
	pre->_data = cur->_data;
	cur->_data = tmp;
}
void BubbleSort(SListNode*pList)
{
	//如果链表为空或者只有一个节点
	if (pList == NULL || pList->_pNext == NULL)
	{
		return;
	}
	SListNode*ptail = NULL;
	while (ptail != pList)//控制总趟数
	{
		//一趟排序
		SListNode*pre = pList;
		SListNode*cur = pre->_pNext;
		while (cur!=ptail)
		{
			if (pre->_data > cur->_data)
			{
				Swap(pre, cur);	
			}
			pre = cur;
			cur = cur->_pNext;
		}
		ptail = pre;//每一趟结束后ptail的位置都要更新
	}
	
}




