#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Declared in "codes.h"
extern uint32_t mapping_function[];

uint32_t calculate_icv_for_summation_code (uint32_t* rand_value, uint32_t size, uint32_t modulo){
    uint32_t counter = 0;
    uint32_t curr_value = 0;
    
    while (size) {
        curr_value = rand_value[(size / 32) - 1];
        
        while (curr_value){
            // We are looking for 0's
            // 0 xor 1 = 1 , 1 xor 1  = 0
            counter += (curr_value ^ 0x1);
            curr_value = curr_value >> 1;
        }        
        size -= 32;
    }
    
    if (modulo != 0){
            counter &= modulo -1;
    }
    
    return counter;    
}


uint32_t calculate_icv_for_code_1 (uint32_t* rand_value, uint32_t size, uint32_t check_bits){
    uint32_t counter = 0;
    uint32_t curr_value = 0;
    uint32_t icv = 0;
    
    while (size) {
        curr_value = rand_value[(size / 32) - 1];
        
        while (curr_value){
            // We are looking for 0's
            // 0 xor 1 = 1 , 1 xor 1  = 0
            counter += (curr_value ^ 0x1);
            curr_value = curr_value >> 1;
        }        
        size -= 32;
    }
    
    if (check_bits != 0){
        icv = counter % (uint32_t)pow(2, check_bits -1);
    }
    icv += (uint32_t)pow(2, check_bits - 2);
    
    return icv;  
}


uint32_t calculate_icv_for_code_2 (uint32_t* rand_value, uint32_t size, uint32_t check_bits){
    uint32_t counter = 0;
    uint32_t curr_value = 0;
    uint32_t icv = 0;
    
    while (size) {
        curr_value = rand_value[(size / 32) - 1];
        
        while (curr_value){
            // We are looking for 0's
            // 0 xor 1 = 1 , 1 xor 1  = 0
            counter += (curr_value ^ 0x1);
            curr_value = curr_value >> 1;
        }        
        size -= 32;
    }
    
    if (check_bits != 0){
        icv = counter % (6 * (uint32_t)pow(2, check_bits - 4));
    }    
    icv = (mapping_function[icv >> check_bits - 4] << (check_bits - 4)) + (icv & ((1 < (check_bits - 4)) - 1));
    
    return icv;  
}

