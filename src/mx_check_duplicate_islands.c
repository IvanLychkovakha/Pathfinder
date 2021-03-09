#include "../inc/header.h"


int mx_check_duplicate_islands(char **array){
    char **arr = array;
    int len = 0;
    bool status = true;
  
    for(int i = 1; arr[i] != NULL; i++){
        for(int j = 0; arr[i][j] != '-'; j++){
            len++;
        }
        for(int k = 0; k < len && arr[i][k+len+1] != ','; k++){
            if(arr[i][k] != arr[i][k+len+1])
                status = false;
        }
        if(status)
            return i+1;

        status = true;
        len = 0;
    }
    return -1;
}
