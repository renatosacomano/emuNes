#ifndef CPU6502
    #define CPU6502
    #include <stdint.h>
    #include <stdio.h>

    /* Declarations Goes Here*/
    typedef struct{
        uint8_t a; // Acummulator
        uint8_t x; // Index X
        uint8_t y; // Index Y

        uint16_t p; // Program Counter

        uint8_t s; // Status da CPU

        uint8_t v; //Endereçamento Stack

        uint8_t stack[256]; //dados da stack

    }cpu6502;

    //cpu functions in alphabetic order
    void    cpu_debug(cpu6502 *cpu);
    cpu6502 cpu_new();
    int     cpu_process(cpu6502 *cpu,uint8_t * mem);

#endif
