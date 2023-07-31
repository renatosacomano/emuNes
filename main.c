#include <stdio.h>
#include <stdint.h>
#include "include/cpu6502.h"

int main(){
    //Sample bin data stored in mem to be processed
    uint8_t mem[3] = {0xa9,0x80,0x00};
    
    //create a new CPU
    cpu6502 cpu = cpu_new();

    //Process the memory using a CPU
    cpu_process(&cpu,&mem);

    //debugs the CPU state
    cpu_debug(&cpu);
    
    return 0;
}