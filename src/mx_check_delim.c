#include "../inc/header.h"

int mx_check_delim(char **array) {
    char **arr = array;
    int delim1 = 0;
    int delim2 = 0;

    for (int i = 1; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != '\0'; j++) {
            if (arr[i][j] == '-')
                delim1++;
            if (arr[i][j] == ',' && delim1 == 1)
                delim2++;
        }
        if (delim1 != 1 || delim2 != 1)
            return i + 1;
        delim1 = 0;
        delim2 = 0;
    }
    return -1;
}
