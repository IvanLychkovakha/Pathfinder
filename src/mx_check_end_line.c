#include "../inc/header.h"

int mx_check_end_line(char *array) {
    int delim = 1;

    for (int i = 0; array[i]; i++) {
        if (array[i] == '\n') {
            delim++;
            if (array[i] == array[i + 1] ||( array[i] == '\n' && array[i-1] == ' '))
                return delim - 1;
        }
    }
    return -1;
}
