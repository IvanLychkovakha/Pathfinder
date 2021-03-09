#include "../inc/header.h"

static bool mx_isdelim(char c){
    if(mx_isspace(c) || c == '-' || mx_isdigit(c) || c ==','){
        return true;
    }
    return false;
}

char **mx_get_arr_of_islands(char *arrayfile){

    if(arrayfile == NULL)
        return NULL;
    char *arr = mx_strdup(arrayfile);

    for(int i = 0; arr[i] != '\0'; i++){
        if(mx_isdelim(arr[i])){
            arr[i] = ' ';
        }
    }
    arr = mx_del_extra_spaces(arr);
    char ** arr2 = mx_strsplit(arr,' ');
  
    mx_strdel(&arr);
    return arr2;
}
