#include"SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


//��ʼ��
void SeqListInit(SeqList*pSeq, int capacity)
{
	assert(pSeq);
	pSeq->_pData = (DataType*)malloc(sizeof(int)* capacity);
	if (pSeq->_pData == NULL)
	{
		printf("���ٿռ�ʧ��!!!\n");
		exit(1);
	}
	pSeq->_size = 0;
	pSeq->_capacity = capacity;
}
//β��
void PushBack(SeqList*pSeq, DataType data)
{
	//�������_CheckCapacity
	_CheckCapacity(pSeq);
	pSeq->_pData[pSeq->_size] = data;
	pSeq->_size++;
}
//βɾ
void PopBack(SeqList*pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("�ѿ�\n");
		exit(1);
	}
	pSeq->_size--;
}
//ͷ��
void PushFront(SeqList*pSeq, DataType data)
{
	assert(pSeq);
	//�������_CheckCapacity
	//Ԫ������������
	for (int i = pSeq->_size - 1; i >= 0; i--)//i����Ԫ��
	{
		pSeq->_pData[i + 1] = pSeq->_pData[i];
	}
	pSeq->_pData[0] = data;
	pSeq->_size++;
}

//ͷɾ
void PopFront(SeqList*pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("�ѿգ���\n");
		exit(1);
	}
	//Ԫ��������ǰ����
	for (int i = 1; i < pSeq->_size; i++)
	{
		pSeq->_pData[i - 1] = pSeq->_pData[i];
	}
	pSeq->_size--;
}

//��ָ��λ�ò���Ԫ��
void SeqListInsert(SeqList*pSeq, int pos, DataType data)
{
	assert(pSeq);
	//�������_CheckCapacity
	if (pos<0 || pos>pSeq->_size)
	{
		printf("����λ������\n");
		return;
	}
	//�Ƚ�posλ�ú��Ԫ������������
	for (int i = pSeq->_size - 1; i >= pos; i--)
	{
		pSeq->_pData[i + 1] = pSeq->_pData[i];
	}
	pSeq->_pData[pos] = data;
	pSeq->_size++;
}


//��ָ��λ��ɾ��Ԫ��
void SeqListErase(SeqList*pSeq, int pos)
{
	assert(pSeq);
	//�������_CheckCapacity
	if (pos<0 || pos>pSeq->_size)
	{
		printf("ɾ��λ������\n");
		return;
		//exit(1);//���﾿��Ӧ�����ĸ���
	}
	//�Ƚ�posλ�ú��Ԫ��������ǰ����
	for (int i = pos; i < pSeq->_size - 1; i++)
	{
		pSeq->_pData[i] = pSeq->_pData[i + 1];
	}
	pSeq->_size--;
}


//��˳�������dataԪ�ص�һ�γ��ֵ�λ��
int SeqListFind(SeqList*pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("˳���Ϊ�գ��޷�����Ԫ��\n");
		return;//������return����exit?
	}
	for (int i = 0; i < pSeq->_size; i++)
	{
		if (pSeq->_pData[i] == data)
		{
			return i;
		}
	}
	return -1;//û���ҵ�Ԫ��
}

// ɾ��˳�����(��һ�γ��֣���ֵΪdata��Ԫ��
void SeqListRemove(SeqList*pSeq, DataType data)
{
	//˼·���Ȳ��Ҹ�Ԫ�أ��ҵ���ɾ��ɾ���Ե���֮ǰд�ĺ���
	assert(pSeq);
	int pos = SeqListFind(pSeq, data);
	if (pos != -1)
	{
		SeqListErase(pSeq, pos);
	}
	//����Ҫ��Ҫд����else��䣿���д�˵Ļ�SeqListRemoveAll����ʱɾ�����Ҳ���Ԫ�ػ�һֱ���
	/*else
	{
	printf("���޴�Ԫ�أ��޷�ɾ��\n");
	}*/
}


//��ȡ˳��������
int SeqListCapacity(SeqList*pSeq)
{
	assert(pSeq);
	return pSeq->_capacity;
}


//��ȡ˳�������ЧԪ�صĸ���
int SeqListSize(SeqList*pSeq)
{
	assert(pSeq);
	return pSeq->_size;
}


// ��ȡ˳����е�һ��Ԫ��
DataType SeqListFront(SeqList*pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("�ѿ�,�޷���ȡ\n");
		return;//������return����exit?
	}
	return pSeq->_pData[0];

}

//��ȡ˳��������һ��Ԫ��
DataType SeqListListBack(SeqList*pSeq)
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("�ѿ�,�޷���ȡ\n");
		return;//������return����exit?
	}
	return pSeq->_pData[pSeq->_size - 1];
}


//����˳���
void SeqListDestory(SeqList*pSeq)
{
	free(pSeq->_pData);
	pSeq->_capacity = 0;
	pSeq->_size = 0;
}
//���˳���
void SeqListClear(SeqList*pSeq)
{
	assert(pSeq);
	pSeq->_size = 0;
}


//�������
void _CheckCapacity(SeqList*pSeq)
{
	//˼·�����_size==_capacity��˵����������Ҫ����;����ÿ�����ݶ�����2��
	//ע��:����ʱ������ö���һ���µı��������գ���Ȼ��������������Ǹ��µ�ǰ����
	assert(pSeq);
	if (pSeq->_size == pSeq->_capacity)
	{
		int New_capacity = pSeq->_capacity * 2;
		DataType*pNew = (DataType*)malloc(sizeof(DataType)*New_capacity);
		if (pNew == NULL)
		{
			printf("�ڴ�ռ䲻�㣬����ʧ�ܣ�����\n");
			exit(1);//������return����exit?
		}
		memcpy(pNew, pSeq->_pData, sizeof(DataType)*pSeq->_capacity);
		free(pSeq->_pData);
		pSeq->_pData = pNew;

		//���ݺ���µ�ǰ������
		pSeq->_capacity = New_capacity;
	}
}

//ɾ��˳���������ֵΪdata��Ԫ��
//����һ��ÿ���ҵ�һ������ɾ����ȱ�㣺ÿ�ζ�Ҫ��ͷ��ʼ������ʱ�临�Ӷ�̫��
//void SeqListRemoveAll(SeqList*pSeq, DataType data)
//{
//	assert(pSeq);
//	for (int i = 0; i < pSeq->_size; i++)
//	{
//		SeqListRemove(pSeq, data);
//	}
//}

//ɾ��˳���������ֵΪdata��Ԫ��
//�����������������ռ�
//����n��Ԫ�صĿռ䣬�������һ��Ԫ�����У�
//��1�������Ҫɾ����Ԫ�أ��Ͳ��ܣ�
//��2���������Ҫɾ����Ԫ�أ������������飻
//����ٰ��¿ռ��Ԫ�ض�������ԭ�ռ䣬���ͷ��¿��ٵĿռ�
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



//ɾ��˳���������ֵΪdata��Ԫ��
//������������Ҫ�����κθ����ռ䣬Ч�����
//����һ������������¼��ǰ������Ҫɾ����Ԫ�صĸ���
//��1��������˵��֮���Ԫ��Ҫ���ƣ�count��¼���ƴ���
//��2��û������˵��֮���Ԫ�ز����ƣ���ǰԪ����ǰ����i - count
void SeqListRemoveAll(SeqList*pSeq, DataType data)
{
	if (pSeq == NULL)
	{
		exit(0);
	}
	int count = 0;//��¼Ҫɾ����Ԫ�س��ֵĸ���
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

//��ð������ķ�ʽ��˳����е�Ԫ�ؽ�������
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
//��ӡ
void Print(SeqList*pSeq)
{
	for (int i = 0; i < pSeq->_size; i++)
	{
		printf("%d ", pSeq->_pData[i]);
	}
	printf("\n");
}