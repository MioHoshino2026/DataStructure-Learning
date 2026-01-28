#ifndef _ADJACENCY_H
#define _ADJACENCY_H

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

#endif