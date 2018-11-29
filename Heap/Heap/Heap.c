#include"Heap.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void Swap(HDataType* x, HDataType* y)
{
	HDataType tmp = *x;
	*x = *y;
	*y = tmp;
}



//int Greater(HDataType left, HDataType right)
//{
//	return left > right;
//}
//
//int Less(HDataType left, HDataType right)
//{
//	return left < right;
//}



//���µ���
void AdjustDown(int parent, HDataType*array, int size)
{
	//������Һ����н�С�ĺ��ӣ�Ĭ�����ӽ�С
	int child = parent * 2 + 1;
	//�����Һ�������С�ĺ���
	while (child < size)//��֤���Ӵ���
	{
		//��֤�Һ��Ӵ��ڣ����ܽ������Һ��Ӵ�С�Ƚ�
		if (child + 1 < size)
		{
			if (array[child] > array[child + 1])
			{
				child = child + 1;
			}
		}
		//�����Һ����н�С����һ���븸�ڵ���бȽϣ����ȸ��ڵ㻹С����Ҫ�������Ѹ��ڵ����������
		if (array[parent] > array[child])
		{
			Swap(&array[parent], &array[child]);
			//��������ܵ���childΪ��������������ѵ�����
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}



//�ѵĳ�ʼ��
void HeapInit(Heap*hp, int*arr, int size)
{
	assert(hp);
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*size);
	if (hp->_array == NULL)
	{
		exit(1);
	}

	//������Ԫ��ȫ���������ѿռ�
	for (int i = 0; i < size; i++)
	{
		hp->_array[i] = arr[i];
	}
	hp->_capacity = size;
	hp->_size = size;


	//����Ԫ��λ�ã�ʹ֮��Ϊ��
	//�����һ����Ҷ�ӽڵ����ε���
	int root = (size - 1) / 2;
	for (root; root>=0; root--)
	{
		AdjustDown(root, hp->_array, hp->_size);
	}
	
}



//��ȡ�Ѷ�Ԫ��
HDataType HeapTop(Heap*hp)
{
	assert(hp);
	return hp->_array[0];
}


//�������
void _CheckCapacity(Heap*hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		int New_capacity = hp->_capacity * 2;
		hp->_array = (HDataType*)realloc(hp->_array, sizeof(HDataType)*New_capacity);
		if (hp->_array == NULL)
		{
			exit(1);
		}
		hp->_capacity = New_capacity;
	}
}



//���ϵ����㷨
//˼·����Ϊǰ���Ѿ���һ�����ˣ�����Ԫ���������룬����ֻ��Ҫ��������λ���������ϵ�������ֱ�����ڵ�Ҳ����
void AdjustUp(int child, HDataType*array, int size)
{
	//��ʽһ��
	int parent = (child - 1) / 2;
	while (parent >= 0&&parent<child)
	{
		if (array[child] < array[parent])
		{
			Swap(&array[parent], &array[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}


	//��ʽ����
	/*int parent = (child - 1) / 2;
	while (child)
	{
		if (array[child] < array[parent])
		{
			Swap(&array[parent], &array[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			return;
		}
	}*/
	
}
//����
void HeapInsert(Heap*hp, HDataType data)
{
	assert(hp);
	_CheckCapacity(hp);
	//1.�Ƚ�Ԫ�ط������
	hp->_array[hp->_size] = data;
	hp->_size++;
	//2.���ϵ���
	AdjustUp(hp->_size - 1, hp->_array, hp->_size);
}



//�ж϶��Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0��
int HeapEmpty(Heap*hp)
{
	return hp->_size == 0;
}



//�ѵ�����
void HeapDestory(Heap*hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

//ɾ���Ѷ�Ԫ��
void HeapErase(Heap*hp)
{
	//���Ϊ�����޷�ɾ��Ԫ��
	if (HeapEmpty(hp))
	{
		exit(1);
	}
	//��Ϊ�գ�
	//˼·�����Ѷ�Ԫ����ѵ����һ��Ԫ�ؽ��������Ѷ�Ԫ�ػ�����󣩣�Ȼ��size--,��ɾ���˶Ѷ�Ԫ��
	//ɾ���󣬶ѵĽṹ���ܱ��ƻ������������µ���
	//HDataType top=HeapTop(hp);
	Swap(&(hp->_array[0]), &(hp->_array[hp->_size - 1]));
	hp->_size--;
	AdjustDown(0, hp->_array, hp->_size);

}


//��ӡ��
void HeapPrint(Heap*hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
}




void HeapAdjust(int root, int*arr, int size)
{
	//Ĭ������ֵ��С
	int child = root * 2 + 1;
	while (child<size)//��֤���Ӵ���
	{
		if(child + 1 < size)//��֤�Һ��Ӵ���
		{
			//�Ƚ����Һ��ӵ�ֵ������child
			if (arr[child] > arr[child + 1])
			{
				child = child + 1;
			}
		}
		//����Сֵ�뵱ǰ�����ĸ��ڵ���бȽϣ���С���������ڵ㣬�����ݽ��е���
		if (arr[root] > arr[child])
		{
			Swap(&arr[root], &arr[child]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//���ţ����򣨽�С�ѣ�
void HeapSort(int*arr, int size)
{
	//1.�Ƚ���(�������µ����㷨���ӵ�һ����Ҷ�ӽڵ㿪ʼ��)
	int parent = (size - 1) / 2;
	for (int root = parent; root >= 0; root--)
	{
		HeapAdjust(root, arr, size);//���µ���
	}
	//2.�ѶѶ�Ԫ�غ����һ��Ԫ�ص�����Ȼ��ɾ�����һ��Ԫ�أ�������size--);�ٿ�ʼ���µ���
	int end = size - 1;//��end���βԪ���±꣬ÿ���ź�һ����end--������������Ԫ��
	while (end)
	{
		Swap(&arr[0], &arr[end]);
		HeapAdjust(0, arr, end);
		end--;
	}
}


