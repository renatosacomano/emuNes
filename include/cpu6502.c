/*Aqui faremos a implementação das declarações feitas na biblioteca*/
#include "cpu6502.h"


cpu6502 cpu_new(){
    cpu6502 cpu;
    cpu.p = 0x00;
    cpu.a = 0x00;
    cpu.x = 0x00;
    cpu.y = 0x00;
    cpu.s.carry_flag = 0;
    cpu.s.zero_flag = 0;
    cpu.s.interrupt_disable = 0;
    cpu.s.decimal_mode_flag = 0;
    cpu.s.break_command = 0;
    cpu.s.overflow_flag = 0;
    cpu.s.negative_flag = 0;
    return cpu;
    printf("cpu criada...\n");
}

void cpu_debug(cpu6502 *cpu){

    printf("\n--DEBUG START--\n\n");
    printf("Program Counter: %d\n",cpu->p);
    printf("Accumulator:     %d\n",cpu->a);
    printf("Index X:         %d\n",cpu->x);
    printf("Index Y:         %d\n",cpu->y);
    printf("Stack Pointer:   %d\n\n",cpu->v);

    printf("                 _NVBDIZC\n");
    printf("Status of CPU:   %d",(cpu->s.carry_flag));
    printf("%d",(cpu->s.zero_flag));
    printf("%d",(cpu->s.interrupt_disable));
    printf("%d",(cpu->s.decimal_mode_flag));
    printf("%d",(cpu->s.break_command));
    printf("%d",(cpu->s.overflow_flag));
    printf("%d",(cpu->s.negative_flag));

    printf("\n\nStatus Flags:\nC = Carry Flag    Z=Zero Flag      I=Interrupt Disable");
    printf("\nD = Decimal Mode  B=Break Command  V=Overflow Flag");
    printf("\nN = Negative Flag");

    printf("\n\n--DEBUG END--");
}

int cpu_process(cpu6502 *cpu,uint8_t * mem){
    
    while(mem[cpu->p] != 0x00){
        printf("%d",mem[cpu->p]);
        switch (mem[cpu->p]) // opcodes
        {
        case 0x00:
            return 0;
            break;
        case 0xa9: lda(cpu,mem,get_addr(cpu,mem,ADDR_MODE_IMMEDIATE),2,2); break;
        
        default:
            break;
        }
    }

    return 0;
}

uint16_t get_addr(cpu6502 *cpu,uint8_t *mem,uint8_t mode){

    switch (mode)
    {
    case ADDR_MODE_IMPLICIT:    return  cpu->p;break;
    case ADDR_MODE_ACCUMULATOR: return  cpu->p;break;
    case ADDR_MODE_IMMEDIATE:   return  cpu->p + 1;break;
    case ADDR_MODE_ZERO_PAGE:   return  mem[cpu->p+1];break;
    case ADDR_MODE_ZERO_PAGE_X: return (mem[cpu->p+1]+cpu->x) % 0xff; break;
    case ADDR_MODE_ZERO_PAGE_Y: return (mem[cpu->p+1]+cpu->y) % 0xff; break;
    case ADDR_MODE_RELATIVE:    return (mem[cpu->p+1]+cpu->p+2); break;
    case ADDR_MODE_ABSOLUTE:    return  mem[cpu->p+1] | (mem[cpu->p+2] << 8); break;
    case ADDR_MODE_ABSOLUTE_X:  return (mem[cpu->p+1] | (mem[cpu->p+2]<<8)) + cpu->x; break;
    case ADDR_MODE_ABSOLUTE_Y:  return (mem[cpu->p+1] | (mem[cpu->p+2]<<8)) + cpu->y; break;
    case ADDR_MODE_INDIRECT:    uint16_t absolute = (mem[cpu->p+1 | (mem[cpu->p+2]<<8)]); return mem[absolute] | (mem[absolute+1]<<8); break;
    case ADDR_MODE_INDEXED_INDIRECT: uint16_t table = mem[cpu->p+1]; return mem[(cpu->x+table)%0xFF]; break;
    case ADDR_MODE_INDIRECT_INDEXED: break;
    default:return 0;break;
    }
}

void u0n(cpu6502 *cpu, uint8_t v){
    cpu->s.zero_flag = (v==0);
    cpu->s.negative_flag = (v>>7);
}

uint8_t adc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t and	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t asl	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t bcc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t bcs	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t beq	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t bit	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t bmi	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t bne	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t bpl	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t brk	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t bvc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t bvs	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t clc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t cld	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t cli	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t clv	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t cmp	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t cpx	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t cpy	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t dec	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t dex	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t dey	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t eor	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t inc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t inx	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t iny	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t jmp	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t jsr	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t lda	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){cpu->a = mem[addr];u0n(cpu,cpu->a);cpu->p += bytes;return cycles;}
uint8_t ldx	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t ldy	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t lsr	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t nop	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t ora	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t pha	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t php	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t pla	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t plp	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t rol	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t ror	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t rti	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t rts	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t sbc	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t sec	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t sed	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t sei	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t sta	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t stx	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t sty	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t tax	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t tay	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t tsx	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t txa	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t txs	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}
uint8_t tya	(cpu6502 *cpu,uint8_t *mem,uint16_t addr,uint8_t bytes,uint8_t cycles){return cycles;}

