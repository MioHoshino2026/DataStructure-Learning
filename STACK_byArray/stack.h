//基于数组的栈实现的H文件
#ifndef _STACK_H
#define _STACK_H

struct StackRecord;
typedef struct StackRecord* Stack;

int IsEmpty( Stack S );
int IsFull( Stack S );  //相较于链表版本新增的函数, 因为数组有大小上限
Stack CreateStack( int MaxElements );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( double X, Stack S );
double Top( Stack S );
void Pop( Stack S );
double TopAndPop( Stack S );

#endif