#include "../inc/header.h"

bool mx_check_file_dexist(int fd)
{
    if(fd < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}
