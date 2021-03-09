#include "../inc/header.h"
 void mx_del_file(t_file **file){
    mx_strdel(&((*file)->filearray));
    mx_del_strarr(&((*file)->array));
    free(*file);
    *file = NULL;
    
}
