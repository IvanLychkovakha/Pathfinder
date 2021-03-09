#include "../inc/header.h"

void countPathsUtil(int u, int d, bool *visited, int *pathCount, Graph *g) 
{ 
    visited[u] = true;

    if (u == d) 
    {
        (*pathCount)++; 
    }
    // If current vertex is not destination 
    else 
    { 
        
        AdjListNode* pCrawl = g->array[u].head; 
        int i = pCrawl->dest;
        
        while(pCrawl != NULL)
        {
            if (!visited[i]) 
            {   
                countPathsUtil(i, d, visited, pathCount, g); 
            }
            if(pCrawl->next == NULL)
                break;
            pCrawl = pCrawl->next;
            i = pCrawl->dest;  
        } 
    }
    visited[u] = false;
}
