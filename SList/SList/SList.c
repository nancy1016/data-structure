#include"SList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//��ʼ��
void SListInit(SListNode*pList)
{
	//pList = (SListNode*)malloc(sizeof(SListNode));
	//pList->_data = 3;
	//pList->_pNext = NULL;
	pList=NULL;
}


//����һ���ڵ�
SListNode* BuySListNode(SLDataType data)
{
	SListNode*pNewNode = (SListNode*)malloc(sizeof(SListNode));
	if (pNewNode == NULL)
	{
		printf("����ռ�ʧ��");
		exit(1);
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
//β��
//ע�⣺����һ��Ҫ������ָ��
void SListPushBack(SListNode**pList, SLDataType data)
{
	//pListΪ�յ������
	//��1���ֶ�����
	//��2������ڵ�ʱû�пռ俪�ٳɹ�������һ��ָ��Ϊ�գ����Զ���ָ����ȻΪ��
	//������������������BuySListNode�����ڲ����ٿռ�ʧ��ʱֱ��exit�ˣ�������䲻��Ҳ����ν
	assert(pList);

	//����Ϊ��ʱ���൱�ڲ����һ���ڵ㣬ֱ������ȥ����
	SListNode*newNode = BuySListNode(data);
	if (*pList == NULL)
	{
		*pList = newNode;
	}
	//����Ϊ��ʱ����������ֱ���ҵ�ԭ���һ���ڵ㣬Ȼ����½ڵ�����ȥ
	else
	{
		SListNode*cur = *pList;
		while (cur->_pNext)
		{
			cur = cur->_pNext;
		}
		//�Ѿ�����ԭ�����һ���ڵ㴦
		cur->_pNext = newNode;
	}
	
}


//βɾ
void SListPopBack(SListNode**pList)
{
	if (*pList == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ��Ԫ��\n");
		exit(1);
	}
	else
	{
		//ֻ��һ���ڵ�
		SListNode*cur = *pList;
		if (cur->_pNext == NULL)
		{
			*pList = NULL;
		}
		//�ж���ڵ�
		else
		{
			while (cur->_pNext->_pNext)
			{
				cur = cur->_pNext;
			}
			//����һ���Ѿ��ߵ��˵����ڶ���Ԫ�أ�������Ҫ������_next�ÿ�
			//��ע��ǧ�����ߵ����һ��Ԫ�أ���Ȼû��ɾ������Ĺؼ���ʵ�ǶԵ����ڶ���Ԫ�ص�next��������
			cur->_pNext = NULL;
		}
	}
}


//ͷ��
void SListPushFront(SListNode**pList, SLDataType data)
{
	SListNode*newNode = BuySListNode(data);
	//���һ������Ϊ��-->ֱ������ȥ
	if (*pList == NULL)
	{
		*pList = newNode;
	}
	//�����������Ϊ��-->Ҫ����ǰ���������:�������棬����ǰ��
	else
	{
		SListNode*cur = *pList;
		newNode->_pNext = cur;
		*pList= newNode;//ע������һ��Ҫ����*pList��ָ�򡣲�����cur=newNode
	}
}


//ͷɾ
void SListPopFront(SListNode**pList)
{
	if (*pList == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ��Ԫ��\n");
		exit(1);
	}
	//���һ��ֻ��һ���ڵ�,ɾ����ע��*pListҪ�ÿ�
	SListNode*cur = *pList;
	if (cur->_pNext == NULL)
	{
		*pList = NULL;
	}
	//��������ж���ڵ㣬ɾ��ʱҪ����*pList��ָ��
	*pList = cur->_pNext;
	free(cur);
	cur = NULL;
}


//����
SListNode*SListFind(SListNode*pList, SLDataType data)
{
	if (pList == NULL)
	{
		printf("����Ϊ��\n");
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

//��ָ��λ�ò���Ԫ��(pos����)
//���ﲻ������ָ���ԭ���ǣ�û�д���SListNode*pList�����������ʼλ�ã�
//ֻ����Ҫ�������������ʱ���Ҫ������ָ��
void SListInsert(SListNode*pos, SLDataType data)
{
	SListNode*newNode = BuySListNode(data);
	if (pos == NULL)
	{
		return;
	}
	//�����ǰ��Ҳ�ڵ�һ��Ԫ�غ�����룬��������Ƚϼ򵥣�����Ҫϸ��
	//�ڵ�һ��Ԫ�غ������ʱ��newNode->_pNext = pos->_pNext;Ҳ��Ӱ�죬��Ϊpos->_pNext==NULL��
	newNode->_pNext = pos->_pNext;
	pos->_pNext = newNode;
}


//��ָ��λ��ɾ��Ԫ��
void SListErase(SListNode**pList, SListNode*pos)
{
	//˼·�����������
	//(1)ͷɾ
	//(2)����λ��ɾ

	if (*pList==pos)
	{
		*pList = pos->_pNext;
	}
	else
	{
		//�ҵ�posǰһ��λ��
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


//����
void SListDestory(SListNode**pList)
{
	SListNode*cur = *pList;
	SListNode*pre = cur;//ÿ��cur�ƶ�֮ǰ������ǰһ��λ�ã�����ɾ��
	while (cur)
	{
		pre = cur;
		cur = cur->_pNext;
		free(pre);
		*pList = cur;//ÿɾ��һ��Ԫ�ض�Ҫע�����ͷָ���λ��
	}


	//���д��
	/*SListNode*cur = *pList;
	while (*pList)
	{
		cur = *pList;
		*pList = cur->_pNext;
		free(cur);
	}*/

}


//ͳ�ƽڵ����
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
//�ж������е�Ԫ���Ƿ�Ϊ��
int SListEmpty(SListNode*pList)
{
	return pList == NULL;
}



//ȡ��Ԫ��
SLDataType Front(SListNode*pList)
{
	assert(pList);
	return pList->_data;
}


//ȡβԪ��
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


//ɾ��ָ��Ԫ�صĽڵ�
//˼·��ֻ���������������1��ɾ���׽ڵ㣨2��ɾ���Ĳ����׽ڵ�
//����Ҫ�����������ܹ��еĽڵ�������
void SListRemove(SListNode**pList, SLDataType data)
{
	SListNode*cur = *pList;
	SListNode*pre = cur;
	while (cur)
	{
		if (cur->_data == data)
		{
			//���ɾ�����ǵ�һ���ڵ�
			if (cur == *pList)
			{
				*pList = cur->_pNext;
			}
			//���ɾ���Ĳ��ǵ�һ���ڵ�
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


//ɾ��Ԫ��Ϊdata�����нڵ�
//˼·��������SListRemoveһ�£�Ψһ��������ǣ�ÿ��ɾ�����ܰ�cur�ÿգ���Ϊ��Ҫ��������֮��Ľڵ�
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
			//���ɾ�����ǵ�һ���ڵ�
			if (cur == *pList)
			{
				*pList = cur->_pNext;
				free(cur);
				cur = *pList;//���ܽ�cur�ÿգ���Ϊ��Ҫ����֮��Ľڵ㣬��ʱ��Ҫ����curλ��
			}
			//���ɾ���Ĳ��ǵ�һ���ڵ�
			else
			{
				pre->_pNext = cur->_pNext;
				free(cur);
				cur = pre->_pNext;//ɾ����cur��Ҫ��������֮��Ľڵ㣬����Ӧ�ø���curλ��
			}
		}
		else
		{
			pre = cur;
			cur = cur->_pNext;
		}
	}

}


//ð������˼·��
//ÿһ�˱Ƚϣ���������ָ�룬���ڱȽ�Ԫ�أ����н�����ÿһ�˶��ܰ�һ��Ԫ�ع鵽���һλ
//�ܹ������Ŀ��ƣ�����һ��ptailָ�룬�޶��ȽϷ�Χ
void Swap(SListNode* pre, SListNode* cur)
{
	SLDataType tmp;
	tmp = pre->_data;
	pre->_data = cur->_data;
	cur->_data = tmp;
}
void BubbleSort(SListNode*pList)
{
	//�������Ϊ�ջ���ֻ��һ���ڵ�
	if (pList == NULL || pList->_pNext == NULL)
	{
		return;
	}
	SListNode*ptail = NULL;
	while (ptail != pList)//����������
	{
		//һ������
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
		ptail = pre;//ÿһ�˽�����ptail��λ�ö�Ҫ����
	}
	
}




