#include "adjacency.h"
#include <stdlib.h>
#include <stdio.h>
#include "fatal.h"

struct Node{
    int Dest;
    Vertex Next;
};

struct Graph{
    int NumVertices;
    AdjList AdjLists;
};

Vertex CreateNode( int dest ){
    Vertex NewNode;

    NewNode = malloc( sizeof( struct Node ));
    if ( NewNode == NULL ){
        FatalError("Out of Space!!!");
    }
    NewNode->Dest = dest;
    NewNode->Next = NULL;
    return NewNode;
}

GraphList CreateGraph( int vertices ){
    GraphList graph;
    graph = malloc( sizeof( struct Graph ));
    if ( graph == NULL ){
        FatalError("Out of Space!!!");
    }
    graph->NumVertices = vertices;
    graph->AdjLists = malloc(sizeof( struct Node ) * graph->NumVertices );
    if ( graph->AdjLists == NULL ){
        FatalError("Out of Space!!!");
    }
    for ( int i = 0; i<graph->NumVertices; i++ ){
        graph->AdjLists[i] = NULL;
    }
    return graph;
}

void AddEdge( GraphList graph, int src, int dest ){
    Vertex NewNode = CreateNode( dest );
    NewNode->Next = graph->AdjLists[src];
    graph->AdjLists[src] = NewNode;
}

void PrintGraph(GraphList graph){
    Vertex Tmp;
    for ( int i = 0; i<graph->NumVertices; i++ ){
        Tmp = graph->AdjLists[i];
        printf("Vertex %d: ", i);
        while( Tmp ){
            printf("-> %d ",Tmp->Dest);
            Tmp = Tmp->Next;
        }
        printf("-> NULL\n");
    }
}

void DeleteGraph(GraphList graph){
    Vertex Tmp, ToFree;
    for ( int i = 0; i<graph->NumVertices; i++ ){
        Tmp = graph->AdjLists[i];
        while( Tmp ){
            ToFree = Tmp;
            Tmp = Tmp->Next;
            free(ToFree);
        }
    }
    free(graph->AdjLists);
    free(graph);
}