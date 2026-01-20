//分离链接哈希表
#include "hashsep.h"
#include "fatal.h"
#include <stdlib.h>

//定义链表节点结构体
struct ListNode{
    int Element;
    Position Next;
};

//定义哈希表结构体, 包含一个链表节点数组和该数组大小
typedef Position List;

struct HashTbl{
    int TableSize;
    List* TheLists;
};

//初始化Hash表
HashTable InitializeTable( int TableSize ){
    HashTable H;
    int i;

    H = malloc( sizeof( struct HashTbl ) );
    if ( H == NULL ){
        FatalError("Out of Space!!!");
    }
    H->TableSize = TableSize;
    H->TheLists = malloc( sizeof( List ) * H->TableSize );
    if( H->TheLists == NULL ){
        FatalError("Out of Space!!!");
    }
    for( i = 0; i < H->TableSize; i++ ){
        H->TheLists[i] = malloc( sizeof( struct ListNode ) );
        if( H->TheLists[i] == NULL ){
            FatalError("Out of Space!!!");
        }
        else{
            H->TheLists[i]->Next = NULL;
        }
    }
    return H;
}

int Hash( int Key, int TableSize){
    char buffer[12];
    snprintf(buffer, sizeof(buffer), "%d", Key);
    const char* str = buffer;
    unsigned int HashVal = 0;
    while(*str != "\0" ){
        HashVal = ( HashVal << 5 ) + *str++;
    }
    return HashVal % TableSize;
}

//FIND操作
Position Find( int Key, HashTable H ){
    Position P;
    List L;

    L = H->TheLists[ Hash(Key, H->TableSize) ];
    P = L->Next;
    while ( P != NULL && P->Element != Key ){
        P = P->Next;
    }
    return P;
}

//插入操作
void Insert( int Key, HashTable H ){
    Position P, Newcell; List L;
    P = Find(Key, H);
    if( P == NULL ){
        Newcell = malloc(sizeof(struct ListNode));
        if( Newcell == NULL ){
            FatalError("Out of Space!!!");
        }
        else{
            L = H->TheLists[Hash(Key, H->TableSize)];
            Newcell->Next = L->Next;
            Newcell->Element = Key;
            L->Next = Newcell;
        }
    }
}