#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

uint32_t mapping_function[] = {3, 5, 6, 9, 10, 12};

bool code_1(uint32_t* value, uint32_t size, uint32_t icv, uint32_t check_bits){
    uint32_t counter = 0;
    uint32_t curr_value = 0;
    uint32_t curr_icv = 0;
    
    while (size) {
        curr_value = value[(size / 32) - 1];
        
        while (curr_value){
            // We are looking for 0's
            // 0 xor 1 = 1 , 1 xor 1  = 0
            counter += (curr_value ^ 0x1);
            curr_value = curr_value >> 1;
        }        
        size -= 32;
    }
    
    if (check_bits >= 2){
        curr_icv = counter % (uint32_t)pow(2, check_bits -1);
    }
    curr_icv += pow(2, check_bits - 2);
    
    if (curr_icv == icv )
        return true;
    else 
        return false;
}


bool code_2(uint32_t* value, uint32_t size, uint32_t icv, uint32_t check_bits){
    uint32_t counter = 0;
    uint32_t curr_value = 0;
    uint32_t curr_icv = 0;
    
    while (size) {
        curr_value = value[(size / 32) - 1];
        
        while (curr_value){
            // We are looking for 0's
            // 0 xor 1 = 1 , 1 xor 1  = 0
            counter += (curr_value ^ 0x1);
            curr_value = curr_value >> 1;
        }        
        size -= 32;
    }
    
    if (check_bits >= 0){
        curr_icv = counter % (6 * (uint32_t)pow(2, check_bits - 4));
    }    
    curr_icv = (mapping_function[curr_icv >> check_bits - 4] << (check_bits - 4)) + (curr_icv & ((1 < (check_bits - 4)) - 1));
    
    if (curr_icv == icv )
        return true;
    else 
        return false; 
}


bool summation_code(uint32_t* value, uint32_t size, uint32_t icv){
    uint32_t counter = 0;
    uint32_t curr_value = 0;
    
    while (size) {
        curr_value = value[(size / 32) - 1];
        
        while (curr_value){
            // We are looking for 0's
            // 0 xor 1 = 1 , 1 xor 1  = 0
            counter += (curr_value ^ 0x1);
            curr_value = curr_value >> 1;
        }        
        size -= 32;
    }

    if (counter == icv )
        return true;
    else 
        return false;
}    


bool summation_code_modulo(uint32_t* value, uint32_t size, uint32_t icv, uint32_t modulo){
    uint32_t counter = 0;
    uint32_t curr_value = 0;
    
    while (size) {
        curr_value = value[(size / 32) - 1];
        
        while (curr_value){
            // We are looking for 0's
            // 0 xor 1 = 1 , 1 xor 1  = 0
            counter += (curr_value ^ 0x1);
            curr_value = curr_value >> 1;
        }        
        size -= 32;
    }

    if ((counter & modulo -1) == icv )
        return true;
    else 
        return false;
}    
