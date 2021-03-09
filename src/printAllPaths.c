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
static int mx_get_num_of_path(int **paths, int V){
    int counter = 0;
     for(int i = 0; i < V; i++){
        if(paths[i][0] != -1){
          counter++;
        }
    }
    return counter;
}
static int* mx_get_arr_of_dist(Graph *g,int **path, int num_of_path, int temp){
    int *dist = (int*)malloc(sizeof(int)* num_of_path);

    for(int i = 0; i < temp; i++){
        int counter = 0;
        if(path[i][0] != -1){
           
            for(int j = 0; j + 1 < g->V && path[i][j+1] != -1; j++){
    
                AdjListNode* pCrawl2 = g->array[path[i][j]].head;
                while (pCrawl2)
                {
                    if(path[i][j+1] != -1 && mx_strcmp(pCrawl2->island,g->array[path[i][j+1]].island) == 0){
                        counter += pCrawl2->weight;
                    }
                    pCrawl2 = pCrawl2->next;
                }
                
            }
            

        }
        dist[i] = counter;
    }
    return dist;
}
static int mx_get_min_dist(int *dist, int num){

    int min_dist = dist[0];
    for(int i = 1; i < num; i++){

        if(dist[i]  < min_dist)
            min_dist = dist[i];
    }
    return min_dist;
}
static void mx_print_path(Graph *g, int **path, int min_dist,int temp){
    for(int i = 0; i < temp; i++){
         int counter = 0;
         
        if(path[i][0] != -1){
           int j;
            for( j = 0; j < g->V && path[i][j] != -1; j++){
              
                AdjListNode* pCrawl2 = g->array[path[i][j]].head;
                while (pCrawl2)
                {
                    if(j + 1 < g->V && path[i][j+1] != -1 && mx_strcmp(pCrawl2->island,g->array[path[i][j+1]].island) == 0){
                        counter += pCrawl2->weight;
                    }
                    pCrawl2 = pCrawl2->next;
                }
                
            }
          
            if(counter == min_dist){
                mx_printstr("========================================");
                mx_printchar('\n');
                mx_printstr("Path: ");
                mx_printstr(g->array[path[i][0]].island);
                mx_printstr(" -> ");
                 for(int j = 1; j < g->V && path[i][j] != -1; j++){
                    if(j + 1 == g->V || path[i][j+1] == -1){
                        mx_printstr(g->array[path[i][j]].island);
                    }
        
                 }
                mx_printchar('\n');
                mx_printstr("Route: ");
                 for(int j = 0; j  < g->V && path[i][j] != -1; j++){
                    if(j + 1 != g->V && path[i][j+1] != -1){
                        mx_printstr(g->array[path[i][j]].island);
                        mx_printstr(" -> ");
                    }else 
                    {
                       mx_printstr(g->array[path[i][j]].island);
                       mx_printchar('\n');
                    }
                }
                mx_printstr("Distance: ");
                if(j == 2){
                  //  mx_printstr(mx_itoa(g->array[path[i][j]].head->weight));
                  AdjListNode* pCrawl2 = g->array[path[i][j-2]].head;
                   while (pCrawl2)
                        {
                            if(mx_strcmp(pCrawl2->island,g->array[path[i][j-1]].island) == 0){
                                mx_printstr(mx_itoa(pCrawl2->weight));
                                
                            }
                            pCrawl2 = pCrawl2->next;
                        } 
                    mx_printchar('\n');
                }else
                {
                    for(int j = 0; j < g->V && path[i][j] != -1; j++){
                        AdjListNode* pCrawl2 = g->array[path[i][j]].head;
                        while (pCrawl2)
                        {
                            if(j + 1 < g->V && mx_strcmp(pCrawl2->island,g->array[path[i][j+1]].island) == 0){
                                mx_printstr(mx_itoa(pCrawl2->weight));
                                
                            }
                            pCrawl2 = pCrawl2->next;
                        }   
                        if(path[i][j+2] != -1 && j + 2 != g->V ){
                            mx_printstr(" + ");
                        }
                        else
                        {
                            mx_printstr(" = ");
                            mx_printstr(mx_itoa(min_dist));
                            mx_printchar('\n');
                            break;
                        }
                        
                    }
                }
                
                mx_printstr("========================================");
                mx_printchar('\n');

            }

        }

    }
}
void printAllPaths(char *island1,char  *island2,Graph *g) 
{ 
    int v1 = findExistNode(g, island1);
    int v2 = findExistNode(g, island2);


    int V = g->V;
    
    bool *visited = (bool*)malloc(sizeof(bool)*V); 
    for (int i = 0; i < V; i++) 
        visited[i] = false;

    int temp =  0;
    countPathsUtil(v1,v2, visited, &temp, g);

    for (int i = 0; i < V; i++) 
        visited[i] = false;

    
    int *path = (int*)malloc(sizeof(int) * V);
    int **path2 = (int**)malloc(sizeof(int*) * temp);
    for(int i = 0; i < temp; i++){
        path2[i] = (int*)malloc(sizeof(int) * V);
        for(int j = 0; j < V; j++){
            path2[i][j] = -1;
        }
    }
    
    int index = 0;
    
    g->pathExist = false;
    
    printAllPathsUtil(g,v1,v2,visited,path,index,path2,temp);
    int counter2 = mx_get_num_of_path(path2,temp);
    int *dist = mx_get_arr_of_dist(g,path2,counter2,temp);
    int min_dist = mx_get_min_dist(dist, counter2);

    
    mx_print_path(g,path2,min_dist,temp);
    free(path);
    path = NULL;
    int **ptr = path2;
    for (int i = 0; i < temp; i++)
    {
        free(ptr[i]);
    }
    free(path2);
    path2 = NULL;
    
} 
