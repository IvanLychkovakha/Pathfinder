#include "../inc/header.h"

AdjListNode* mx_newAdjListNode(int dest, int weight, char *island) 
{ 
    AdjListNode* newNode = 
     (AdjListNode*) malloc(sizeof(AdjListNode)); 
    newNode->dest = dest; 
    newNode->weight = weight;
    newNode->island = island;
    newNode->checked = false;
    newNode->next = NULL; 
    return newNode; 
} 

