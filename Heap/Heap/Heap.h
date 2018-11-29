#ifndef __Heap_H_
#define __Heap_H_


//����һ������ָ��
//typedef int (*PF)(HDataType left, HDataType right);

typedef int HDataType;
typedef struct Heap
{
	HDataType* _array;
	int _capacity;//����
	int _size;//Ԫ�ظ���
	//PF _pCom;
}Heap;



//int Greater(HDataType left, HDataType right);
//int Less(HDataType left, HDataType right);

void HeapInit(Heap*hp, int*arr, int size);//�ѵĳ�ʼ��
HDataType HeapTop(Heap*hp);//��ȡ�Ѷ�Ԫ��
void _CheckCapacity(Heap*hp);//�������
void HeapInsert(Heap*hp, HDataType data);//����
int HeapEmpty(Heap*hp);//�ж϶��Ƿ�Ϊ��
void HeapDestory(Heap*hp);//�ѵ�����
void HeapErase(Heap*hp);//ɾ���Ѷ�Ԫ��
void HeapPrint(Heap*hp);//��ӡ��


void HeapSort(int*arr,int size);
#endif
