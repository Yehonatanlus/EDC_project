// Typical ROM size 16MB = 0x8000000 bits

#define ROM_SIZE     0x8000000
#define CHECK_BITS   5
#define SINGLE_TEST  0
#define CYCLES       1000

// Codes
bool summation_code (uint32_t* value, uint32_t size, uint32_t icv);
bool summation_code_modulo (uint32_t* value, uint32_t size, uint32_t icv, uint32_t modulo);
bool code_1 (uint32_t* value, uint32_t size, uint32_t icv, uint32_t check_bits);
bool code_2 (uint32_t* value, uint32_t size, uint32_t icv, uint32_t check_bits);

// ICV calculations
uint32_t calculate_icv_for_summation_code (uint32_t* rand_value, uint32_t size, uint32_t check_bits);
uint32_t calculate_icv_for_code_1 (uint32_t* rand_value, uint32_t size, uint32_t check_bits);
uint32_t calculate_icv_for_code_2 (uint32_t* rand_value, uint32_t size, uint32_t check_bits);

// Tests
void sumation_code_tests (uint32_t* chunk_sizes, uint32_t total_chunks, uint32_t* memory, uint32_t* icv, uint64_t* results);
void sumation_code_modulo_tests (uint32_t* chunk_sizes, uint32_t total_chunks, uint32_t* memory, uint32_t* icv, uint32_t check_bits, uint64_t* results);
void code_1_tests (uint32_t* chunk_sizes, uint32_t total_chunks, uint32_t* memory, uint32_t* icv, uint32_t check_bits, uint64_t* results);
void code_2_tests (uint32_t* chunk_sizes, uint32_t total_chunks, uint32_t* memory, uint32_t* icv, uint32_t check_bits, uint64_t* results);

