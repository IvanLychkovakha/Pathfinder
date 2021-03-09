#include "../inc/header.h"


 void mx_del_graph(Graph **g){
    mx_del_list(&(*g)->array,(*g)->V);
    free(*g);
    (*g)->array = NULL;
    *g = NULL;

}
