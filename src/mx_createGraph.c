#include "../inc/header.h"

 Graph* mx_createGraph(int V) 
{ 
    Graph* graph = (Graph*) malloc(sizeof( Graph)); 
    graph->V = V; 
    graph->count = 0;

    graph->array =(AdjList*) malloc(V * sizeof(AdjList)); 
   
    int i; 
    for (i = 0; i < V; ++i)
    {
        graph->array[i].head = NULL; 
        graph->array[i].island = "";
    }
  
    return graph; 
} 
