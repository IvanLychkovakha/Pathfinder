#include "../inc/header.h"


static int findExistNode(struct Graph* graph, char* island)
{
    for(int i = 0; i < graph->V; i++)
    {
        if(mx_strcmp(graph->array[i].island, island) == 0)
            return i;
    }
    return -1;
}


void mx_addEdge(Graph* graph, int weight, char *island1, char *island2) 
{
    int nodeId1 = findExistNode(graph, island1);
    int nodeId2 = findExistNode(graph, island2);

    if(nodeId1 == -1)
    {
        nodeId1 = graph->count;
        graph->count++;
    }
    if(nodeId2 == -1)
    {
        nodeId2 = graph->count;
        graph->count++;
    }

    AdjListNode* newNode = mx_newAdjListNode(nodeId2, weight, island2); 
    newNode->next = graph->array[nodeId1].head; 
    graph->array[nodeId1].head = newNode;
    graph->array[nodeId1].island = island1;
  
    newNode = mx_newAdjListNode(nodeId1, weight, island1); 
    newNode->next = graph->array[nodeId2].head; 
    graph->array[nodeId2].head = newNode;
    graph->array[nodeId2].island = island2;
}
