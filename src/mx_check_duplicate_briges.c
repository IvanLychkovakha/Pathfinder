#include "../inc/header.h"
static int mx_get_len_arr(char **arr){
    int count = 0;
    for(int i = 0; arr[i] != NULL; i++){
        count++;
    }
    return count-1;
}
bool mx_check_duplicate_briges(char *arrayfile){
    char **arr = NULL;
    
    if(!(arr = mx_get_arr_of_islands(arrayfile)))
        return false;
  
    for(int i = 0; i < mx_get_len_arr(arr); i+=2){
        for(int j = i+2; j < mx_get_len_arr(arr); j+=2){
            if(((mx_strcmp(arr[i],arr[j]) == 0 && mx_strcmp(arr[i+1],arr[j+1]) == 0) || (mx_strcmp(arr[i],arr[j+1]) == 0 && mx_strcmp(arr[i+1] ,arr[j]) == 0)) && i+1 < mx_get_len_arr(arr)  && j+1 < mx_get_len_arr(arr)){
                return true;
            }
        }

    }
    return false;

}
