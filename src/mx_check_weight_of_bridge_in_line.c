#include "../inc/header.h"

int mx_check_weight_of_bridge_in_line(char **array){
    char **arr = array;
    bool status = false;

    for (int i = 1; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != '\0'; j++) {
            if (arr[i][j] == ',') {
                status = true;
                j++;
            }
            if (status == true && (mx_isdigit(arr[i][j]) == false || (arr[i][j-1] == ',' && arr[i][j] == '0' ))){
                return i+1;
            }
        }
        status = false;
    }
    return -1;
}
