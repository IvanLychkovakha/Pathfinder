#include "../inc/header.h"

int mx_atoi(const char *s) {
    int num = 0;
    
    while(*s) {
        if(mx_isdigit(*s)) {
            num = num * 10 + *s -'0'; 
            s++;
        }
        else
            return -1;
        
        
    } 
    
    return num;
}
