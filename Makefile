all:
	gcc main.c tests.c calculate_icv.c codes.c -lm -o EDC.elf
    