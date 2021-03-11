# ROM Circuit Edit Detecting Codes
This repository is the code of the testing framework for a project that has been created for course 236379 - Coding and Algorithms for Memories. 
The goal of this project was to find efficient codes to detect asymmetric errors that are resulted in a circuit edit. This framework implements several codes and evaluates their efficiency by validating a randomly initialized memory with them.

## Paper
The full project details can be found inside the file "project.pdf"


## Getting Started
### Prerequisites
All that is needed is a simple linux machine with gcc installed. To get accurate results it is highly recommended to run this program over a real linux machine and not a virtual machine or WSL (Windows Subsystem for Linux).

### Building the Project
Simply clone this github repository and run make:
```
git clone https://github.com/Yehonatanlus/EDC_project.git
cd EDC_project
make
```
### Running
Once the project was compiled a new executable called "EDC.elf" will appear. To run it simply type:

```
./EDC.elf
```
If all went ok (The tests may take few hours), you are expected to see an output like this:

```
 [ + ] Intializing memory with random values
 [ + ] Performing summation code:
     [ - ] Summation code on 32 bit chunks took 238496.472000 clocks on average
     [ - ] Summation code on 64 bit chunks took 238216.977000 clocks on average
     [ - ] Summation code on 128 bit chunks took 239737.513000 clocks on average
     [ - ] Summation code on 256 bit chunks took 244636.673000 clocks on average
 [ + ] Performing summation modulo code:
     [ - ] Summation code modulo with 4 check bits, on 32 bit chunks took 264919.057000 clocks on average
     [ - ] Summation code modulo with 4 check bits, on 64 bit chunks took 264897.363000 clocks on average
     [ - ] Summation code modulo with 4 check bits, on 128 bit chunks took 260707.801000 clocks on average
     [ - ] Summation code modulo with 4 check bits, on 256 bit chunks took 262048.808000 clocks on average
 [ + ] Performing code 1:
     [ - ] Code 1 with 4 check bits, on 32 bit chunks took 449398.883000 clocks on average
     [ - ] Code 1 with 4 check bits, on 64 bit chunks took 347098.432000 clocks on average
     [ - ] Code 1 with 4 check bits, on 128 bit chunks took 297293.548000 clocks on average
     [ - ] Code 1 with 4 check bits, on 256 bit chunks took 277332.867000 clocks on average
 [ + ] Performing code 2:
     [ - ] Code 2 with 4 check bits, on 32 bit chunks took 285834.823000 clocks on average
     [ - ] Code 2 with 4 check bits, on 64 bit chunks took 261133.269000 clocks on average
     [ - ] Code 2 with 4 check bits, on 128 bit chunks took 248948.164000 clocks on average
     [ - ] Code 2 with 4 check bits, on 256 bit chunks took 246372.288000 clocks on average
 [ + ] Done
```

## Creating Your Own Tests
In case you would like to create your own tests, all the relevant configuration is located in two files.
### main.h
This file contains the following values that can be configured:
```
ROM_SIZE    - the size of the ROM to work with
CHECK_BITS  - The amount of redundancy bits
SINGLE_TEST - Whether to perform a single test or full test with several cycles
CYCLES      - The amount of cycles to perform in the case of a full test
```
### main.c
In case you want to change the chunks size (which is something that you probably would not wanna do), simply add the relevant chunk sizes to the following array:
```
line 16:      uint32_t      chunk_sizes[] = {32, 64, 128, 256};
```

## Running Your Tests
Simply recompile the project and execute it
```
make
./EDC.elf
```





