#include "../inc/header.h"

Graph* mx_parse_file_to_graph(t_file *file){
    char **ptr1 = NULL;
    char **ptr2 = NULL;

    Graph* graph = mx_createGraph(mx_atoi(file->array[0]));

    for(int i = 1; file->array[i] != NULL; i++)
    {
        ptr1 = mx_strsplit(file->array[i], ',');
        ptr2 = mx_strsplit(ptr1[0], '-');
        mx_addEdge(graph,mx_atoi(mx_strdup(ptr1[1])),mx_strdup(ptr2[0]),mx_strdup(ptr2[1]));
        mx_del_strarr(&ptr1);
        mx_del_strarr(&ptr2);
    }
  
    return graph;
}
