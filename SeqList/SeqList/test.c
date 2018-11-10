#include"SeqList.h"
#include<stdio.h>
#include<stdlib.h>


int main()
{
	SeqList sq;
	SeqListInit(&sq, 3);
	PushBack(&sq, 1);
	PushBack(&sq, 2);
	PushBack(&sq, 3);
	PushBack(&sq, 2);
	PushBack(&sq, 5);
	PushBack(&sq, 2);
	PushBack(&sq, 7);
	PushBack(&sq, 8);
	PushBack(&sq, 9);
	Print(&sq);
	//SeqListRemoveAll(&sq, 2);
	BubbleSort(&sq);
	Print(&sq);



	////Print(&sq);
	///*PopBack(&sq);
	//PopBack(&sq);
	//Print(&sq);*/
	//PushFront(&sq, 4);
	//PushFront(&sq, 5);
	//Print(&sq);
	////PopFront(&sq);
	//SeqListInsert(&sq, 1, 6);
	//SeqListInsert(&sq, 2, 6);
	//Print(&sq);
	//SeqListErase(&sq, 2);
	//Print(&sq);
	///*int ret = SeqListFind(&sq, 1);
	//printf("%d ", ret);*/
	//SeqListRemove(&sq, 6);
	//Print(&sq);

	//int size = SeqListSize(&sq);
	//printf("size=%d\n", size);

	//int capacity = SeqListCapacity(&sq);
	//printf("capacity =%d\n", capacity);

	//int data_front = SeqListFront(&sq);
	//printf("dada_front =%d\n", data_front);

	//int data_back = SeqListListBack(&sq);
	//printf("dada_back =%d\n", data_back);


	////SeqListClear(&sq);
	//SeqListDestory(&sq);
	//Print(&sq);


	system("pause");
	return 0;
}