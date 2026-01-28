#include "adjacency.h"
#include <stdio.h>

int main(){
    int N, M;  //N, M分别为顶点数和边数
    printf("Please enter vertices and edges: ");
    if ( scanf("%d %d", &N, &M) != 2 ) return 1;
    GraphList graph = CreateGraph(N);
    printf("Please enter %d edges: \n", M);
    for ( int i = 0; i < M; i++ ){
        int u, v;
        scanf("%d %d",&u,&v);
        if( u<0 || u>=N || v<0 || v>=N ){
            printf("Error! Please enter again!\n");
            i--;
            continue;
        }
        AddEdge(graph, u ,v);
    }
    PrintGraph(graph);
    DeleteGraph(graph);
}