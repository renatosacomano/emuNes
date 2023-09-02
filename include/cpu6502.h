#ifndef CPU6502
    #define CPU6502
    #include <stdint.h>
    #include <stdio.h>

    typedef struct{
        uint8_t carry_flag,zero_flag,interrupt_disable,decimal_mode_flag,break_command,overflow_flag,negative_flag;
    }status;
    
    
    typedef struct{
        uint8_t a; // Acummulator
        uint8_t x; // Index X
        uint8_t y; // Index Y

        uint16_t p; // Program Counter

        status s; // Status da CPU

        uint8_t v; //Endereçamento Stack

    }cpu6502;

    //cpu functions in alphabetic order
    void    cpu_debug(cpu6502 *cpu);
    cpu6502 cpu_new();
    int     cpu_process(cpu6502 *cpu,uint8_t * mem);

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

    //auxiliar functions
    void u0n(cpu6502 *cpu, uint8_t v); //update zero and negative flags
    //cpu instructions
    uint8_t adc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t and	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t asl	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t bcc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t bcs	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t beq	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t bit	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t bmi	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t bne	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t bpl	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t brk	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t bvc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t bvs	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t clc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t cld	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t cli	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t clv	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t cmp	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t cpx	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t cpy	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t dec	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t dex	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t dey	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t eor	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t inc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t inx	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t iny	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t jmp	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t jsr	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t lda	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t ldx	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t ldy	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t lsr	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t nop	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t ora	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t pha	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t php	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t pla	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t plp	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t rol	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t ror	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t rti	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t rts	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t sbc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t sec	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t sed	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t sei	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t sta	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t stx	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t sty	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t tax	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t tay	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t tsx	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t txa	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t txs	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    uint8_t tya	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles);
    
#endif
