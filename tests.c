#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "main.h"

void sumation_code_tests (uint32_t* chunk_sizes, uint32_t total_chunks, uint32_t* memory, uint32_t* icv, uint64_t* results){
    int         curr_chunk_size, total_time;
    bool        result;     
    clock_t     start, end;
    
    for (int j = 0; j < total_chunks; j++ ){
        curr_chunk_size = chunk_sizes[j];
        
        // icv calulations
        for (int i = 0; i < ROM_SIZE / curr_chunk_size; i++){
            icv[i] = calculate_icv_for_summation_code(memory + i * (curr_chunk_size / 32) , curr_chunk_size, 0);
        }
        
        // performance measurment
        start = clock();
        for (int i = 0; i < ROM_SIZE / curr_chunk_size; i++){
            result = summation_code(memory + i * (curr_chunk_size / 32), curr_chunk_size, icv[i]);
        }
        end = clock();
        total_time = ((int) end - start);
        
        results[j] += total_time;
    }   
}



void sumation_code_modulo_tests (uint32_t* chunk_sizes, uint32_t total_chunks, uint32_t* memory, uint32_t* icv, uint32_t check_bits, uint64_t* results){
    int         curr_chunk_size, total_time;
    bool        result;     
    clock_t     start, end;
    uint32_t    modulo = (uint32_t)pow(2, check_bits);

    for (int j = 0; j < total_chunks; j++ ){
        curr_chunk_size = chunk_sizes[j];
        
        // icv calulations
        for (int i = 0; i < ROM_SIZE / curr_chunk_size; i++){
            icv[i] = calculate_icv_for_summation_code(memory + i * (curr_chunk_size / 32) , curr_chunk_size, modulo);
        }
        
        // performance measurment
        start = clock();
        for (int i = 0; i < ROM_SIZE / curr_chunk_size; i++){
            result = summation_code_modulo(memory + i * (curr_chunk_size / 32), curr_chunk_size, icv[i], modulo);
        }
        end = clock();
        total_time = ((int) end - start);
        
        results[j] += total_time;
    }  
}



void code_1_tests (uint32_t* chunk_sizes, uint32_t total_chunks, uint32_t* memory, uint32_t* icv, uint32_t check_bits, uint64_t* results){
    int         curr_chunk_size, total_time;
    bool        result;     
    clock_t     start, end;
    uint32_t    modulo = (uint32_t)pow(2, check_bits);

    for (int j = 0; j < total_chunks; j++ ){
        curr_chunk_size = chunk_sizes[j];
        
        // icv calulations
        for (int i = 0; i < ROM_SIZE / curr_chunk_size; i++){
            icv[i] = calculate_icv_for_code_1(memory + i * (curr_chunk_size / 32) , curr_chunk_size, check_bits);
        }
        
        // performance measurment
        start = clock();
        for (int i = 0; i < ROM_SIZE / curr_chunk_size; i++){
            result = code_1(memory + i * (curr_chunk_size / 32), curr_chunk_size, icv[i], check_bits);
        }
        end = clock();
        total_time = ((int) end - start);
        
        results[j] += total_time;
    }  
}


void code_2_tests (uint32_t* chunk_sizes, uint32_t total_chunks, uint32_t* memory, uint32_t* icv, uint32_t check_bits, uint64_t* results){
    int         curr_chunk_size, total_time;
    bool        result;     
    clock_t     start, end;
    uint32_t    modulo = (uint32_t)pow(2, check_bits);

    for (int j = 0; j < total_chunks; j++ ){
        curr_chunk_size = chunk_sizes[j];
        
        // icv calulations
        for (int i = 0; i < ROM_SIZE / curr_chunk_size; i++){
            icv[i] = calculate_icv_for_code_2(memory + i * (curr_chunk_size / 32) , curr_chunk_size, check_bits);
        }
        
        // performance measurment
        start = clock();
        for (int i = 0; i < ROM_SIZE / curr_chunk_size; i++){
            result = code_2(memory + i * (curr_chunk_size / 32), curr_chunk_size, icv[i], check_bits);
        }
        end = clock();
        total_time = ((int) end - start);
        
        results[j] += total_time;
    }  
}
