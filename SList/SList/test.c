#include"SList.h"
#include<stdio.h>
#include<stdlib.h>

void test()
{
	SListNode*list=NULL;
	SListInit(list);
	SListPushBack(&list, 2);
	SListPushBack(&list, 7);
	SListPushBack(&list, 3);
	SListPushBack(&list, 2);
	SListPushBack(&list, 5);
	SListPrint(list);

	//SListRemove(&list,2);
	SListRemoveAll(&list, 2);
	SListPrint(list);
	//printf("size=%d\n", SListSize(list));

	//SLDataType data = Front(list);
	//printf("data=%d\n", Front(list));
	//printf("data=%d\n", Back(list));

	/*SListDestory(&list);
	SListPrint(list);
	printf("size=%d\n", SListSize(list));*/
	//printf("ret=%d", SListEmpty(list));

	/*SListPopBack(&list);
	SListPopBack(&list);
	SListPrint(list);

	SListPushFront(&list, 6);
	SListPushFront(&list, 7);
	SListPrint(list);

	SListPopFront(&list);
	SListPopFront(&list);
	SListPrint(list);*/


	/*SListNode*p = SListFind(list,3);
	SListInsert(p, 7);
	SListPrint(list);*/

	/*SListNode*p = SListFind(list,1);
	SListErase(&list, p);
	SListPrint(list);*/

}
int main()
{
	test();
	system("pause");
	return 0;
}