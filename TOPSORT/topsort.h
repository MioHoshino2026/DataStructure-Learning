#ifndef _TOPSORT_H
#define _TOPSORT_H

struct Node;
typedef struct Node* Vertex;
typedef struct Node** AdjList;
struct Graph;
typedef struct Graph* GraphList;

Vertex CreateNode( int dest );
GraphList CreateGraph( int vertices );
void AddEdge( GraphList graph, int src, int dest );
void PrintGraph( GraphList graph );
void DeleteGraph( GraphList graph );

void PrintIndegree( GraphList graph );

int* TopSort( GraphList graph );

#endif