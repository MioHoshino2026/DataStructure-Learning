#include "dist.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

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
        printf("Out of Space!!!");
        exit(1);
    }
    NewNode->Dest = dest;
    NewNode->Next = NULL;
    return NewNode;
}

GraphList CreateGraph( int vertices ){
    GraphList graph;
    graph = malloc( sizeof( struct Graph ));
    if ( graph == NULL ){
        printf("Out of Space!!!");
        exit(1);
    }
    graph->NumVertices = vertices;
    graph->AdjLists = malloc(sizeof( Vertex ) * graph->NumVertices );
    if ( graph->AdjLists == NULL ){
        printf("Out of Space!!!");
        exit(1);
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

//输入路径起点和图的名称, 以创建路径辅助列表
TableList Initialize( int Start, GraphList graph ){
    TableList T;

    T = malloc(sizeof(struct Table)*graph->NumVertices);
    if ( T == NULL ){
        printf("Out of Space!!!");
        exit(1);
    }
    for ( int i = 0; i < graph->NumVertices ; i++){
        T[i].Dist = -1;
        T[i].Path = -1;
    }
    T[Start].Dist = 0;
    return T;
}

//无权最短路径算法
TableList Unweighted( int Start, GraphList graph )
{
    TableList T = Initialize( Start, graph);
    Queue Q = CreateQueue( graph->NumVertices );
    Enqueue( Start, Q );
    while ( !IsEmpty(Q) ){
        int v = FrontAndDequeue(Q);
        Vertex Tmp = graph->AdjLists[v];
        while( Tmp ){
            if ( T[Tmp->Dest].Dist == -1 ){
                T[Tmp->Dest].Dist = T[v].Dist + 1;
                T[Tmp->Dest].Path = v;
                Enqueue(Tmp->Dest, Q);
            }
            Tmp = Tmp->Next;
        }
    }
    DisposeQueue(Q);
    return T;
}