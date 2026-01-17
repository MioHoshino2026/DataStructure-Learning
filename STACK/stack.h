//实现栈的H文件
#ifndef _STACK_H
#define _STACK_H

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

int IsEmpty( Stack S );
Stack CreateStack();
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( double X, Stack S );
double Top( Stack S );
void Pop( Stack S );

#endif