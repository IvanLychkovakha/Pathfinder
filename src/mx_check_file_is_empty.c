#include "../inc/header.h"

int mx_check_file_is_empty(const char *name) {
    int length = 0;
    int file_descriptor = -1;
    char buffer[1];

    if (!name)
        return -1;
    file_descriptor = open(name, O_RDONLY);
    if (file_descriptor < 0)
        return -1;
    while (read(file_descriptor, buffer, 1))
        length++;
    if (close(file_descriptor) < 0)
        return -1;
    return length;
}
