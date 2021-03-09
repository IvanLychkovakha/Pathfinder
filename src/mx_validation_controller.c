#include "../inc/header.h"


void mx_validation_controller(t_file *file){
    if(!mx_check_file_dexist(file->fd))
        mx_printerr_pf(FILE_DEXIST, file->name);
    if(mx_check_file_is_empty(file->name) == 0)
        mx_printerr_pf(FILE_EMPTY, file->name);
    if(!mx_check_first_line(file->array))
        mx_printerr_pf(INVLD_FRST_LINE, NULL);
    if(mx_check_weight_of_bridge_in_line(file->array) > 0)
        mx_printerr_pf(INVLD_LINE, mx_itoa(mx_check_weight_of_bridge_in_line(file->array)));
    if(mx_check_first_island_in_line(file->array) > 0)
        mx_printerr_pf(INVLD_LINE, mx_itoa(mx_check_first_island_in_line(file->array)));
    if(mx_check_second_island_in_line(file->array) > 0)
        mx_printerr_pf(INVLD_LINE, mx_itoa(mx_check_second_island_in_line(file->array)));
    if(mx_check_delim(file->array) > 0)
        mx_printerr_pf(INVLD_LINE, mx_itoa(mx_check_delim(file->array)));
    if(mx_check_end_line(file->filearray) >= 0)
        mx_printerr_pf(INVLD_LINE, mx_itoa(mx_check_end_line(file->filearray)));
    if(mx_check_duplicate_islands(file->array) > 0)
        mx_printerr_pf(INVLD_LINE, mx_itoa(mx_check_duplicate_islands(file->array)));
    if(mx_get_num_of_unique_words(file->filearray) != mx_atoi(file->array[0]))
        mx_printerr_pf(INVLD_NUM_ISLDS, NULL);
    if(mx_check_duplicate_briges(file->filearray) )
        mx_printerr_pf(DPLC_ISLDS, NULL);
    if(mx_get_sum_of_lengths(file->filearray) == -1)
        mx_printerr_pf(INVLD_SUM_LNGTH, NULL);
}
