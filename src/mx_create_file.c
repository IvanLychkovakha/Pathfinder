#include "../inc/header.h"

t_file *mx_create_file(char *argv[]) {
    t_file *file = malloc(sizeof(t_file));
   
    file->name = argv[1];
    file->fd = open(argv[1], O_RDONLY);
    file->filearray = mx_file_to_str(argv[1]);
    file->array = mx_strsplit(file->filearray, '\n');
    return file;
}

