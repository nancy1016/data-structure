#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
void test()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPrint(&s);

	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	StackPop(&s);


	StackDeatory(&s);
	//StackPrint(&s);



	int size = StackSize(&s);
	printf("size=%d\n", size);

	/*int ret = StackTop(&s);
	printf("ret=%d\n", ret);*/
	/*StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);*/
}


int main()
{

	test();
	system("pause");
	return 0;
}