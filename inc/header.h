#ifndef header
#define header
#include "../libmx/inc/libmx.h"

typedef enum e_error {
    INVLD_CMD_ARGS,
    FILE_DEXIST,
    FILE_EMPTY,
    INVLD_FRST_LINE,
    INVLD_LINE,
    INVLD_NUM_ISLDS,
    DPLC_ISLDS,
    INVLD_SUM_LNGTH
} t_error;



typedef struct s_file t_file;
typedef struct AdjListNode AdjListNode;
typedef struct AdjList AdjList;
typedef struct Graph Graph;
typedef struct MinHeapNode MinHeapNode;
typedef struct MinHeap MinHeap;
typedef struct Path Path;
typedef struct PathNode PathNode;


struct AdjListNode 
{ 
    int dest; 
    int weight;
    char *island;
    bool checked;
    AdjListNode* next; 
}; 
struct AdjList 
{ 
    char *island;
    AdjListNode *head;  
}; 
struct Graph 
{ 
    int V;
    int count;
    bool pathExist;
    AdjList* array;
};
struct s_file {
    int fd;
    char *name;
    char *filearray;
    char **array;
};



void mx_printerr(const char *s);

int mx_atoi(const char *s);
bool mx_isalpha(int c);
bool mx_isdigit(int c);
char **mx_get_arr_of_islands(char *arrayfile);
//Valid
void mx_validation_controller(t_file *file);
bool mx_check_num_of_argc(int argc);
void mx_valid_argc(int argc);
void mx_printerr_pf(t_error err, const char *s);
bool mx_check_file_dexist(int fd);
int mx_check_file_is_empty(const char *name);
bool mx_check_first_line(char **array);
int mx_check_first_island_in_line(char **array);
int mx_check_second_island_in_line(char **array);
int mx_check_weight_of_bridge_in_line(char **array);
int mx_check_delim(char **array);
int mx_check_end_line(char *array);
int mx_check_duplicate_islands(char **array);
int mx_get_num_of_unique_words( char *arrayfile);
bool mx_check_duplicate_briges(char *arrayfile);
int mx_get_sum_of_lengths(char *arrayfile);
t_file *mx_create_file(char *argv[]);

void countPathsUtil(int u, int d, bool *visited, int *pathCount, Graph *g);
void mx_addEdge(Graph* graph, int weight, char *island1, char *island2);
AdjListNode* mx_newAdjListNode(int dest, int weight, char *island);
Graph* mx_createGraph(int V) ;
Graph* mx_parse_file_to_graph(t_file *file);
 void mx_del_file(t_file **file);
void mx_pop_back_node(AdjListNode **head);
void mx_del_list(AdjList **list,int V);
 void mx_del_graph(Graph **g);
void printAllPaths(char *island1,char  *island2,Graph *g) ;
void printAllPathsUtil(Graph *g, int v1, int v2, bool *visited, int *path, int index, int **path2, int temp);
#endif
