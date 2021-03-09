#include "../inc/header.h"

void mx_valid_argc(int argc) {
    if(!mx_check_num_of_argc(argc)){
        mx_printerr_pf(INVLD_CMD_ARGS, NULL);
    }
}
