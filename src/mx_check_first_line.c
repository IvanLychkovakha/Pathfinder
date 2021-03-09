#include "../inc/header.h"

static bool mx_isnumber(char *s) {
    int i = -1;

    while (s[++i])
        if (!mx_isdigit(s[i]))
            return false;
    return true;
}

bool mx_check_first_line(char **array){
    if (!mx_isnumber(array[0]))
    {
        return false;
    }
    else
    {
        return true;
    }
}
