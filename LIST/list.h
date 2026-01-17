//链表结构的H文件
#ifndef _LIST_H
#define _LIST_H

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty( List L );

int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( double X, List L );
Position FindPrevious( double X, List L );
void Delete( double X, List L );
void Insert( double X, List L, Position P );

void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P );
double Retrieve( Position P );

#endif