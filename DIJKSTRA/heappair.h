//实现配对堆算法的H文件
#ifndef _HEAPPAIR_H
#define _HEAPPAIR_H

struct Nodel;
typedef struct Nodel* Position;
typedef Position PairHeap;
Position CreateNodel( int rank, int Element );
PairHeap Merge( PairHeap First, PairHeap Second );
PairHeap Insertl( int rank, int Item,Position P, PairHeap H );
PairHeap DecreaseKey( Position P, int Delta, PairHeap H );
PairHeap CombineSiblings( Position FirstSibling );
PairHeap DeleteMin(int* Number, PairHeap H );

#endif