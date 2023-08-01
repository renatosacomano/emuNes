/*Aqui faremos a implementação das declarações feitas na biblioteca*/
#include "cpu6502.h"


cpu6502 cpu_new(){
    cpu6502 cpu;
    cpu.p = 0x00;
    cpu.a = 0x00;
    cpu.x = 0x00;
    cpu.y = 0x00;
    cpu.s = 0x00;

    int i;
    for(i=0;i<256;i++){
        cpu.stack[i] = 0x00;
    }

    return cpu;
}

void cpu_debug(cpu6502 *cpu){

    printf("\n--DEBUG START--\n\n");
    printf("Program Counter: %d\n",cpu->p);
    printf("Accumulator:     %d\n",cpu->a);
    printf("Index X:         %d\n",cpu->x);
    printf("Index Y:         %d\n",cpu->y);
    printf("Stack Pointer:   %d\n\n",cpu->v);

    printf("                 _NVBDIZC\n");
    printf("Status of CPU:   %d",(cpu->s & 0x80)>>7);
    printf("%d",(cpu->s & 0x40)>>6);
    printf("%d",(cpu->s & 0x20)>>5);
    printf("%d",(cpu->s & 0x10)>>4);
    printf("%d",(cpu->s & 0x08)>>3);
    printf("%d",(cpu->s & 0x04)>>2);
    printf("%d",(cpu->s & 0x02)>>1);
    printf("%d",cpu->s & 0x01);

    printf("\n\nStatus Flags:\nC = Carry Flag    Z=Zero Flag      I=Interrupt Disable");
    printf("\nD = Decimal Mode  B=Break Command  V=Overflow Flag");
    printf("\nN = Negative Flag");

    printf("\n\n--DEBUG END--");
}

int cpu_process(cpu6502 *cpu,uint8_t * mem){
    
    while(mem[cpu->p] != 0x00){
        switch (mem[cpu->p]) // opcodes
        {
        case 0x00:
            return 0;
            break;
        case 0xa9:
            cpu->p ++;
            cpu->a = mem[cpu->p];
            cpu->p++;

            if (cpu->a == 0x00){
                cpu->s = cpu->s | 0x02;
            }else{
                cpu->s = cpu->s & 0xfd;
            }

            if(cpu->a & 0x80){
                cpu->s = cpu->s | 0x40;
            }else{
                cpu->s = cpu->s & 0xbf;
            }

            break;
        
        default:
            break;
        }
    }

    return 0;
}

uint16_t get_addr(cpu6502 *cpu,uint8_t *mem,int8_t mode){
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
    case ADDR_MODE_INDIRECT: break;
    case ADDR_MODE_INDEXED_INDIRECT: break;
    case ADDR_MODE_INDIRECT_INDEXED: break;
    default:
        break;
    }
}