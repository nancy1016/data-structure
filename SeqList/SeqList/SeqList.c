#include"SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


//初始化
void SeqListInit(SeqList*pSeq, int capacity)
{
	assert(pSeq);
	pSeq->_pData = (DataType*)malloc(sizeof(int)* capacity);
	if (pSeq->_pData == NULL)
	{
		printf("开辟空间失败!!!\n");
		exit(1);
	}
	pSeq->_size = 0;
	pSeq->_capacity = capacity;
}
//尾插
void PushBack(SeqList*pSeq, DataType data)
{
	//检测容量_CheckCapacity
	_CheckCapacity(pSeq);
	pSeq->_pData[pSeq->_size] = data;
	pSeq->_size++;
}
//尾删
void PopBack(SeqList*pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("已空\n");
		exit(1);
	}
	pSeq->_size--;
}
//头插
void PushFront(SeqList*pSeq, DataType data)
{
	assert(pSeq);
	//检测容量_CheckCapacity
	//元素依次向后搬移
	for (int i = pSeq->_size - 1; i >= 0; i--)//i代表元素
	{
		pSeq->_pData[i + 1] = pSeq->_pData[i];
	}
	pSeq->_pData[0] = data;
	pSeq->_size++;
}

//头删
void PopFront(SeqList*pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("已空！！\n");
		exit(1);
	}
	//元素依次向前搬移
	for (int i = 1; i < pSeq->_size; i++)
	{
		pSeq->_pData[i - 1] = pSeq->_pData[i];
	}
	pSeq->_size--;
}

//在指定位置插入元素
void SeqListInsert(SeqList*pSeq, int pos, DataType data)
{
	assert(pSeq);
	//检测容量_CheckCapacity
	if (pos<0 || pos>pSeq->_size)
	{
		printf("插入位置有误\n");
		return;
	}
	//先将pos位置后的元素依次向后搬移
	for (int i = pSeq->_size - 1; i >= pos; i--)
	{
		pSeq->_pData[i + 1] = pSeq->_pData[i];
	}
	pSeq->_pData[pos] = data;
	pSeq->_size++;
}


//在指定位置删除元素
void SeqListErase(SeqList*pSeq, int pos)
{
	assert(pSeq);
	//检测容量_CheckCapacity
	if (pos<0 || pos>pSeq->_size)
	{
		printf("删除位置有误\n");
		return;
		//exit(1);//这里究竟应该用哪个？
	}
	//先将pos位置后的元素依次向前搬移
	for (int i = pos; i < pSeq->_size - 1; i++)
	{
		pSeq->_pData[i] = pSeq->_pData[i + 1];
	}
	pSeq->_size--;
}


//在顺序表中找data元素第一次出现的位置
int SeqListFind(SeqList*pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("顺序表为空，无法查找元素\n");
		return;//这里用return还是exit?
	}
	for (int i = 0; i < pSeq->_size; i++)
	{
		if (pSeq->_pData[i] == data)
		{
			return i;
		}
	}
	return -1;//没有找到元素
}

// 删除顺序表中(第一次出现）的值为data的元素
void SeqListRemove(SeqList*pSeq, DataType data)
{
	//思路：先查找该元素，找到则删，删可以调用之前写的函数
	assert(pSeq);
	int pos = SeqListFind(pSeq, data);
	if (pos != -1)
	{
		SeqListErase(pSeq, pos);
	}
	//这里要不要写这条else语句？如果写了的话SeqListRemoveAll调用时删完后会找不到元素会一直输出
	/*else
	{
	printf("查无此元素，无法删除\n");
	}*/
}


//获取顺序表的容量
int SeqListCapacity(SeqList*pSeq)
{
	assert(pSeq);
	return pSeq->_capacity;
}


//获取顺序表中有效元素的个数
int SeqListSize(SeqList*pSeq)
{
	assert(pSeq);
	return pSeq->_size;
}


// 获取顺序表中第一个元素
DataType SeqListFront(SeqList*pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("已空,无法获取\n");
		return;//这里用return还是exit?
	}
	return pSeq->_pData[0];

}

//获取顺序表中最后一个元素
DataType SeqListListBack(SeqList*pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("已空,无法获取\n");
		return;//这里用return还是exit?
	}
	return pSeq->_pData[pSeq->_size - 1];
}


//销毁顺序表
void SeqListDestory(SeqList*pSeq)
{
	free(pSeq->_pData);
	pSeq->_capacity = 0;
	pSeq->_size = 0;
}
//清空顺序表
void SeqListClear(SeqList*pSeq)
{
	assert(pSeq);
	pSeq->_size = 0;
}


//检测容量
void _CheckCapacity(SeqList*pSeq)
{
	//思路：如果_size==_capacity，说明已满，需要扩容;这里每次扩容都扩大2倍
	//注意:扩容时容量最好定义一个新的变量来接收，不然很容易扩完后忘记更新当前容量
	assert(pSeq);
	if (pSeq->_size == pSeq->_capacity)
	{
		int New_capacity = pSeq->_capacity * 2;
		DataType*pNew = (DataType*)malloc(sizeof(DataType)*New_capacity);
		if (pNew == NULL)
		{
			printf("内存空间不足，开辟失败！！！\n");
			exit(1);//这里用return还是exit?
		}
		memcpy(pNew, pSeq->_pData, sizeof(DataType)*pSeq->_capacity);
		free(pSeq->_pData);
		pSeq->_pData = pNew;

		//扩容后更新当前的容量
		pSeq->_capacity = New_capacity;
	}
}

//删除顺序表中所有值为data的元素
//方法一：每次找到一个，则删除；缺点：每次都要从头开始遍历，时间复杂度太高
//void SeqListRemoveAll(SeqList*pSeq, DataType data)
//{
//	assert(pSeq);
//	for (int i = 0; i < pSeq->_size; i++)
//	{
//		SeqListRemove(pSeq, data);
//	}
//}

//删除顺序表中所有值为data的元素
//方法二：借助辅助空间
//开辟n个元素的空间，整体遍历一遍元素序列，
//（1）如果是要删除的元素，就不管；
//（2）如果不是要删除的元素，拷贝到新数组；
//最后再把新空间的元素都拷贝到原空间，再释放新开辟的空间
//void SeqListRemoveAll(SeqList*pSeq, DataType data)
//{
//	if (pSeq == NULL)
//	{
//		exit(0);
//	}
//	DataType*pData = (DataType*)malloc(sizeof(DataType)*pSeq->_size);
//	int count = 0;
//	for (int i = 0; i < pSeq->_size; i++)
//	{
//		if (pSeq->_pData[i] != data)
//		{
//			pData[count] = pSeq->_pData[i];
//			count++;
//		}
//	}
//	memcpy(pSeq->_pData, pData, sizeof(DataType)*count);
//	pSeq->_size =count;
//	free(pData);
//}



//删除顺序表中所有值为data的元素
//方法三：不需要借助任何辅助空间，效率最高
//定义一个计数器，记录当前遇到的要删除的元素的个数
//（1）遇到：说明之后的元素要搬移；count记录搬移次数
//（2）没遇到：说明之后的元素不搬移，当前元素向前搬移i - count
void SeqListRemoveAll(SeqList*pSeq, DataType data)
{
	if (pSeq == NULL)
	{
		exit(0);
	}
	int count = 0;//记录要删除的元素出现的个数
	for (int i = 0; i < pSeq->_size; i++)
	{
		
		if (pSeq->_pData[i] == data)
		{
			count++;
		}
		else
		{
			pSeq->_pData[i - count] = pSeq->_pData[i];
		}
	}
	pSeq->_size -= count;
}

//用冒泡排序的方式对顺序表中的元素进行排序
void BubbleSort(SeqList*pSeq)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->_size - 1; i++)
	{
		for (int j = 0; j < pSeq->_size - 1 - i; j++)
		{
			if (pSeq->_pData[j]>pSeq->_pData[j + 1])
			{
				DataType tmp = pSeq->_pData[j];
				pSeq->_pData[j] = pSeq->_pData[j + 1];
				pSeq->_pData[j + 1] = tmp;
			}

		}
	}
}
//打印
void Print(SeqList*pSeq)
{
	for (int i = 0; i < pSeq->_size; i++)
	{
		printf("%d ", pSeq->_pData[i]);
	}
	printf("\n");
}