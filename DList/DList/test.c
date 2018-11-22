#include"DList.h"
#include<stdio.h>
#include<stdlib.h>


int main()
{
	DListNode*plist=NULL;
	DListInit(&plist);
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPushBack(plist, 5);
	DListPushBack(plist, 6);
	DListPrint(plist);



	//DListNode*pos = DListFind(plist,0);
	//DListErase(pos);
	DListRemove(plist,1);
	//printf("%p\n", pos);
	//DListInsert(pos, 5);
	DListPrint(plist);

	//DListPopBack(plist);
	
	/*DListPushFront(plist, 1);
	DListPushFront(plist, 2);
	DListPushFront(plist, 3);
	DListPushFront(plist, 4);*/

	/*DListPopFront(plist);
	DListPopFront(plist);
	DListPopFront(plist);*/

	//DListPrint(plist);
	system("pause");
	return 0;
}