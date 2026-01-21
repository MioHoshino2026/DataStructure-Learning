//用数组实现二叉堆, 假设堆中存储元素均为正整数
#ifndef _BINHEAP_H
#define _BINHEAP_H

struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;

PriorityQueue Initialize( int MaxElements );
void Destroy( PriorityQueue H );
void MakeEmpty( PriorityQueue H );
void Insert( int X, PriorityQueue H );
int Deletemin( PriorityQueue H );
int FindMin( PriorityQueue H );
int IsEmpty( PriorityQueue H );
int IsFull( PriorityQueue H );

#endif