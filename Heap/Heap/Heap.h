#ifndef __Heap_H_
#define __Heap_H_


//定义一个函数指针
//typedef int (*PF)(HDataType left, HDataType right);

typedef int HDataType;
typedef struct Heap
{
	HDataType* _array;
	int _capacity;//容量
	int _size;//元素个数
	//PF _pCom;
}Heap;



//int Greater(HDataType left, HDataType right);
//int Less(HDataType left, HDataType right);

void HeapInit(Heap*hp, int*arr, int size);//堆的初始化
HDataType HeapTop(Heap*hp);//获取堆顶元素
void _CheckCapacity(Heap*hp);//检测容量
void HeapInsert(Heap*hp, HDataType data);//插入
int HeapEmpty(Heap*hp);//判断堆是否为空
void HeapDestory(Heap*hp);//堆的销毁
void HeapErase(Heap*hp);//删除堆顶元素
void HeapPrint(Heap*hp);//打印堆


void HeapSort(int*arr,int size);
#endif
