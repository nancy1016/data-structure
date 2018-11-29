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



//向下调整
void AdjustDown(int parent, HDataType*array, int size)
{
	//标记左右孩子中较小的孩子，默认左孩子较小
	int child = parent * 2 + 1;
	//找左右孩子中最小的孩子
	while (child < size)//保证左孩子存在
	{
		//保证右孩子存在，才能进行左右孩子大小比较
		if (child + 1 < size)
		{
			if (array[child] > array[child + 1])
			{
				child = child + 1;
			}
		}
		//将左右孩子中较小的那一个与父节点进行比较，若比父节点还小，则要交换（把父节点调整下来）
		if (array[parent] > array[child])
		{
			Swap(&array[parent], &array[child]);
			//调整后可能导致child为根的子树不满足堆的性质
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}



//堆的初始化
void HeapInit(Heap*hp, int*arr, int size)
{
	assert(hp);
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*size);
	if (hp->_array == NULL)
	{
		exit(1);
	}

	//将数组元素全部拷贝进堆空间
	for (int i = 0; i < size; i++)
	{
		hp->_array[i] = arr[i];
	}
	hp->_capacity = size;
	hp->_size = size;


	//调整元素位置，使之成为堆
	//从最后一个非叶子节点依次调整
	int root = (size - 1) / 2;
	for (root; root>=0; root--)
	{
		AdjustDown(root, hp->_array, hp->_size);
	}
	
}



//获取堆顶元素
HDataType HeapTop(Heap*hp)
{
	assert(hp);
	return hp->_array[0];
}


//检测容量
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



//向上调整算法
//思路：因为前提已经是一个堆了，插入元素在最后插入，所以只需要调整插入位置依次往上的子树，直到根节点也满足
void AdjustUp(int child, HDataType*array, int size)
{
	//方式一：
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


	//方式二：
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
//插入
void HeapInsert(Heap*hp, HDataType data)
{
	assert(hp);
	_CheckCapacity(hp);
	//1.先将元素放入堆中
	hp->_array[hp->_size] = data;
	hp->_size++;
	//2.向上调整
	AdjustUp(hp->_size - 1, hp->_array, hp->_size);
}



//判断堆是否为空（为空返回1，不为空返回0）
int HeapEmpty(Heap*hp)
{
	return hp->_size == 0;
}



//堆的销毁
void HeapDestory(Heap*hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

//删除堆顶元素
void HeapErase(Heap*hp)
{
	//如果为空则无法删除元素
	if (HeapEmpty(hp))
	{
		exit(1);
	}
	//不为空，
	//思路：将堆顶元素与堆的最后一个元素交换（即堆顶元素换到最后），然后size--,就删掉了堆顶元素
	//删掉后，堆的结构可能被破坏，所以再向下调整
	//HDataType top=HeapTop(hp);
	Swap(&(hp->_array[0]), &(hp->_array[hp->_size - 1]));
	hp->_size--;
	AdjustDown(0, hp->_array, hp->_size);

}


//打印堆
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
	//默认左孩子值较小
	int child = root * 2 + 1;
	while (child<size)//保证左孩子存在
	{
		if(child + 1 < size)//保证右孩子存在
		{
			//比较左右孩子的值，更新child
			if (arr[child] > arr[child + 1])
			{
				child = child + 1;
			}
		}
		//将最小值与当前子树的根节点进行比较，若小于子树根节点，则数据进行调换
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
//堆排：降序（建小堆）
void HeapSort(int*arr, int size)
{
	//1.先建堆(利用向下调整算法，从第一个非叶子节点开始调)
	int parent = (size - 1) / 2;
	for (int root = parent; root >= 0; root--)
	{
		HeapAdjust(root, arr, size);//向下调整
	}
	//2.把堆顶元素和最后一个元素调换，然后删除最后一个元素（不能用size--);再开始向下调整
	int end = size - 1;//用end标记尾元素下标，每次排好一个后，end--，继续排其他元素
	while (end)
	{
		Swap(&arr[0], &arr[end]);
		HeapAdjust(0, arr, end);
		end--;
	}
}


