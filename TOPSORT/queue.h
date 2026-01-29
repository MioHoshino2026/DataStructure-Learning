//利用数组实现队列
#ifndef _QUEUE_H
#define _QUEUE_H

struct QueueRecord;
typedef struct QueueRecord* Queue;

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue( int MaxElements );
void DisposeQueue( Queue Q );
void MakeEmpty( Queue Q );
void Enqueue( int X, Queue Q );
int Front( Queue Q );
void Dequeue( Queue Q );
int FrontAndDequeue( Queue Q );

#endif