#include "../inc/header.h"


int mx_get_num_of_unique_words( char *arrayfile){
    char **arr = NULL;
    int count = 0;
    
    if(!(arr = mx_get_arr_of_islands(arrayfile)))
        return -1;
    for(int i = 0; arr[i] != NULL; ++i)
    {
        ++count;
        for(int j = 0; j < i; ++j)
            if (mx_strcmp(arr[i],arr[j]) == 0)
            {
                --count;
                break;
            }
    }
    mx_del_strarr(&arr);
    return count;
}
