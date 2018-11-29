#include"Heap.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{

	int arr[] = { 10, 8, 7, 6, 5, 3};
	//int arr[] = { 2,3,4,1,5};
	Heap hp;
	HeapInit(&hp, arr, 6);
	HeapPrint(&hp);
	HeapDestory(&hp);

	//HeapSort(arr, sizeof(arr) / sizeof(arr[0]));

	/*printf("\n");
	HeapInsert(&hp, 11);
	HeapPrint(&hp);
	printf("\n");
	HeapBubble(&hp);
	HeapPrint(&hp);*/
	//int ret = HeapEmpty(&hp);
	//printf("ret=%d\n", ret);
	/*HeapErase(&hp);
	HeapErase(&hp);
	HeapPrint(&hp);*/


	system("pause");
	return 0;
}