#include "../inc/header.h"

int mx_check_first_island_in_line(char **array){
    char **arr = array;

    for (int i = 1; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != '-'; j++) {
            if (mx_isalpha(arr[i][j]) == false)
               return i + 1;
        }
        if (mx_isalpha(arr[i][0]) == false)
            return i + 1;
    }
    return -1;
}
