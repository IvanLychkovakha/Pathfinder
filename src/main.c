#include "../inc/header.h"

int main(int argc, char *argv[])
{
    mx_valid_argc(argc);
    t_file *file = mx_create_file(argv);

    mx_validation_controller(file);
    Graph *graph = mx_parse_file_to_graph(file); 
    
    mx_del_file(&file);
    for(int i = 0; i < graph->V; i++){
        for(int j = i + 1; j < graph->V; j++){
            printAllPaths(graph->array[i].island,graph->array[j].island,graph);
        }
    }
    mx_del_graph(&graph);
    exit(0);
}
