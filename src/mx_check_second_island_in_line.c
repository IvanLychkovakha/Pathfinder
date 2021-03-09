#include "../inc/header.h"


int mx_check_second_island_in_line(char **array){
    char **arr = array;
    bool status = false;

    for (int i = 1; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != ','; j++) {
            if (arr[i][j] == '-') {
                status = true;
                j++;
            }
            if ((status == true) && (mx_isalpha(arr[i][j]) == false))
                return i + 1;
        }
        status = false;
    }
    return -1;
}
