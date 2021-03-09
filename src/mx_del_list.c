#include "../inc/header.h"

 void mx_del_list(AdjList **list,int V){
    
   for (int i = 0;i < V; i++)
   {
         AdjListNode *current = (*list)->head;
         (*list)++;
         while (current != NULL)
         {
             mx_pop_back_node(&current);
         }
   }
}
