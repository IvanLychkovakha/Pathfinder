#include "../inc/header.h"

void printAllPathsUtil(Graph *g, int v1, int v2, bool *visited, int *path, int index, int **path2, int temp){
    visited[v1] = true;
    
    path[index]=v1;
    index++;
    
    if(v1==v2){
        if(!g->pathExist)
            g->pathExist=true;
        for(int j = 0; j < temp; j++){
            if( path2[j][0] == -1){
                for(int k = 0; k < index; k++){
                    path2[j][k] = path[k];
                }
                break;
            }
        }    
    }
    else{ 
       
        AdjListNode* pCrawl = g->array[v1].head; 
        int i = g->array[v1].head->dest;
        
        while(pCrawl != NULL){
            if (!visited[i]) {   
                printAllPathsUtil(g, i, v2, visited, path, index,path2,temp);
            }
            if(pCrawl->next == NULL)
                break;
            pCrawl = pCrawl->next;
            i = pCrawl->dest;
        } 
    }
   
    index--;
    visited[v1]=false;
    
}
