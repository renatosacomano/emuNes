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
    int     cpu_process(cpu6502 *cpu,int8_t * mem);

    //memory addressing modes
    #define ADDR_MODE_IMPLICIT          0   //no addressing
    #define ADDR_MODE_ACCUMULATOR       1   //operates directly on accumulator (A register)
    #define ADDR_MODE_IMMEDIATE         2   //the next byte of memory contains the value
    #define ADDR_MODE_ZERO_PAGE         3   //1 byte of memory address for the first 256 bytes of memory
    #define ADDR_MODE_ZERO_PAGE_X       4   //1byte of memory plus the value of X resister, warps arround if exceed byte size (255)
    #define ADDR_MODE_ZERO_PAGE_Y       5   //same as ZERO_PAGE_X but with the Y register 
    #define ADDR_MODE_RELATIVE          6   //used for branching instructions, adds one signed byte(-128 to 127) to Program Counter (register P)
    #define ADDR_MODE_ABSOLUTE          7   //An absolute 16 bit(2bytes) memory address little endian
    #define ADDR_MODE_ABSOLUTE_X        8   //Add X register value to the absolute 16 bit(2 bytes) memory
    #define ADDR_MODE_ABSOLUTE_Y        9   //same as ABSOLUTE_X but with Y register value
    #define ADDR_MODE_INDIRECT          10  //used only with JMP instruction
    #define ADDR_MODE_INDEXED_INDIRECT  11
    #define ADDR_MODE_INDIRECT_INDEXED  12

    uint16_t get_addr(cpu6502 *cpu,uint8_t *mem,uint8_t mode);
    
#endif
