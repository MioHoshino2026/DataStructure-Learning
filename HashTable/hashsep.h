//分离链接哈希表
#ifndef _HASHSEP_H
#define _HASHSEP_H

struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable( int TableSize );
Position Find( int Key, HashTable H );
void Insert( int Key, HashTable H );
double Retrieve( Position P );

#endif