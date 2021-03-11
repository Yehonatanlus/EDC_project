#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "main.h"

void main(){
    // The PROM data (memory)
    uint32_t*     memory = (uint32_t*)malloc(ROM_SIZE / 8);
    // At most (ROM_SIZE / 32) icv's, in case we llok at blocks of size 32 bits
    uint32_t*     icv    = (uint32_t*)malloc(ROM_SIZE / 8); 
    // The chunks to work with
    uint32_t      chunk_sizes[] = {32, 64, 128, 256};
    uint32_t      total_chunks = sizeof(chunk_sizes) / sizeof(uint32_t);
    // Total check bits
    uint32_t      check_bits = CHECK_BITS; 

    // Storing the total time in results
    uint64_t*     results = (uint64_t*)malloc(total_chunks * sizeof(uint64_t));
    
    // Random seed intialization, we want it to be random and deterministic so it can be repeated.
    srand(0);
    printf(" [ + ] Intializing memory with random values \n");
    for (int i = 0; i < ROM_SIZE / 32; i++){
        memory[i] = (uint32_t)rand();
    }
    
    // Intializing results
    for (int i = 0; i < total_chunks; i++){
        results[i] = 0;
    }
    
    if (SINGLE_TEST){
        printf(" [ + ] Performing summation code: \n");
        sumation_code_tests (chunk_sizes, total_chunks, memory, icv, results); 
        for (int i = 0; i < total_chunks; i++){
            printf("     [ - ] Summation code on %d bit chunks took %ld clocks \n", chunk_sizes[i], results[i]);
        }  
    
        printf(" [ + ] Performing summation modulo code: \n");
        sumation_code_modulo_tests (chunk_sizes, total_chunks, memory, icv, check_bits, results);
        for (int i = 0; i < total_chunks; i++){
            printf("     [ - ] Summation code modulo with %d check bits, on %d bit chunks took %ld clocks \n", check_bits, chunk_sizes[i], results[i]);
        }  
        
        printf(" [ + ] Performing code 1: \n");
        code_1_tests (chunk_sizes, total_chunks, memory, icv, check_bits, results);
        for (int i = 0; i < total_chunks; i++){
            printf("     [ - ] Code 1 with %d check bits, on %d bit chunks took %ld clocks \n", check_bits, chunk_sizes[i], results[i]);
        }  
        
        printf(" [ + ] Performing code 2: \n");
        code_2_tests (chunk_sizes, total_chunks, memory, icv, check_bits, results);
        for (int i = 0; i < total_chunks; i++){
            printf("     [ - ] Code 2 with %d check bits, on %d bit chunks took %ld clocks \n", check_bits, chunk_sizes[i], results[i]);
        }          
    }
    else {
        /* Summation code */
        printf(" [ + ] Performing summation code: \n");
        for (int i = 0; i < total_chunks; i++){
            results[i] = 0;
        }
        for (int curr_cycle = 0; curr_cycle < CYCLES; curr_cycle++){
            srand(curr_cycle);
            for (int i = 0; i < ROM_SIZE / 32; i++){
                memory[i] = (uint32_t)rand();
            }
            sumation_code_tests (chunk_sizes, total_chunks, memory, icv, results);     
        }
        for (int i = 0; i < total_chunks; i++){
            printf("     [ - ] Summation code on %d bit chunks took %f clocks on average \n", chunk_sizes[i], (double)results[i] / CYCLES);
        }  
        
        /* Summation modulo code */
        printf(" [ + ] Performing summation modulo code: \n");
        for (int i = 0; i < total_chunks; i++){
            results[i] = 0;
        }
        for (int curr_cycle = 0; curr_cycle < CYCLES; curr_cycle++){
            srand(curr_cycle);
            for (int i = 0; i < ROM_SIZE / 32; i++){
                memory[i] = (uint32_t)rand();
            }
            sumation_code_modulo_tests (chunk_sizes, total_chunks, memory, icv, check_bits, results);    
        }
        for (int i = 0; i < total_chunks; i++){
            printf("     [ - ] Summation code modulo with %d check bits, on %d bit chunks took %f clocks on average \n", check_bits, chunk_sizes[i], (double)results[i] / CYCLES);
        }  
        
        /* Code 1 */
        printf(" [ + ] Performing code 1: \n");        
        for (int i = 0; i < total_chunks; i++){
            results[i] = 0;
        }        
        for (int curr_cycle = 0; curr_cycle < CYCLES; curr_cycle++){
            srand(curr_cycle);
            for (int i = 0; i < ROM_SIZE / 32; i++){
                memory[i] = (uint32_t)rand();
            }
            code_1_tests (chunk_sizes, total_chunks, memory, icv, check_bits, results);
        }
        for (int i = 0; i < total_chunks; i++){
            printf("     [ - ] Code 1 with %d check bits, on %d bit chunks took %f clocks on average \n", check_bits, chunk_sizes[i], (double)results[i] / CYCLES);
        }  
        
        /* Code 2 */
        printf(" [ + ] Performing code 2: \n");       
        for (int i = 0; i < total_chunks; i++){
            results[i] = 0;
        }        
        for (int curr_cycle = 0; curr_cycle < CYCLES; curr_cycle++){
            srand(curr_cycle);
            for (int i = 0; i < ROM_SIZE / 32; i++){
                memory[i] = (uint32_t)rand();
            }
            code_2_tests (chunk_sizes, total_chunks, memory, icv, check_bits, results);
        }
        for (int i = 0; i < total_chunks; i++){
            printf("     [ - ] Code 2 with %d check bits, on %d bit chunks took %f clocks on average \n", check_bits, chunk_sizes[i], (double)results[i] / CYCLES);
        }  
    }
    printf(" [ + ] Done \n");
}