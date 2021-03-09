#include "../inc/header.h"
static bool mx_nondigit(char c){
    if(mx_isspace(c) || c == '-' || mx_isalpha(c) || c ==','){
        return true;
    }
    return false;
}

static char **mx_get_arr_of_weight(char *filearr){
   if(filearr == NULL)
        return NULL;
    char *arr = mx_strdup(filearr);

    for(int i = 0; arr[i] != '\0'; i++){
        if(mx_nondigit(arr[i])){
            arr[i] = ' ';
        }
    }
    arr = mx_del_extra_spaces(arr);
    char ** arr2 = mx_strsplit(arr,' ');
  
    mx_strdel(&arr);
    return arr2;
}

int mx_get_sum_of_lengths(char *arrayfile){
    char **arr = NULL;
    int count = 0;
    
    if(!(arr = mx_get_arr_of_weight(arrayfile)))
        return -1;

    for(int i = 1; arr[i] != NULL; i++){
        if(count > INT32_MAX - mx_atoi(arr[i]))
             return -1;
        count += mx_atoi(arr[i]);
        
    }
    mx_del_strarr(&arr);
    return count;
}
