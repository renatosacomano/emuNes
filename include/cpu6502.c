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