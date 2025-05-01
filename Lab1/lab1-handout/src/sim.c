#include <stdio.h>
#include "shell.h"
#include <stdint.h>
//  R -type function hex value
#define ADD 0x20
#define ADDU 0x21
#define AND 0x24
#define BREAK 0x0D
#define DIV 0x1A
#define DIVU 0x1B
#define JALR 0x09
#define JR 0x08
#define MFHI 0x10
#define MFLO 0x12
#define MTHI 0x11
#define MTLO 0x13
#define MULT 0x18
#define MULTU 0x19
#define NOR 0x27
#define OR 0x25
#define SLL 0x00
#define SLLV 0x04
#define SLT 0x2A
#define SLTU 0x2B
#define SRA 0x03
#define SRAV 0x07
#define SRL 0x02
#define SRLV 0x06
#define SUB 0x22
#define SUBU 0x23
#define XOR 0x26
#define SYSCALL 0x0C
// i type opcode hex value
#define ADDI 0x08
#define ADDIU 0x09
#define ANDI 0x0C
#define BEQ 0x04
#define BNE 0x05
#define BGTZ 0x07
#define BLEZ 0x06
#define BLTZ 0x01
#define BGEZ 0x01
#define BLTZAL 0x01
#define BGEZAL 0x01
#define LB 0x20
#define LBU 0x24
#define LH 0x21
#define LHU 0x25
#define LUI 0x0F
#define LW 0x23
#define ORI 0x0D
#define SB 0x28
#define SLTI 0x0A
#define SLTIU 0x0B
#define SH 0x29
#define SW 0x2B
#define XORI 0x0E
// j-type opcode hex value
#define J 0x02
#define JAL 0x03
void R_type_instruct(uint32_t rs, uint32_t rt, uint32_t rd, uint32_t shamt, uint32_t funct){
      
       	switch(funct){

	       case ADD:
	               NEXT_STATE.REGS[rd] = (int32_t)CURRENT_STATE.REGS[rs] + (int32_t)CURRENT_STATE.REGS[rt];
		       break;

	       case ADDU:
                       NEXT_STATE.REGS[rd] =(uint32_t)CURRENT_STATE.REGS[rs] +(uint32_t)CURRENT_STATE.REGS[rt];
		       break;

               case AND:
                       NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] & CURRENT_STATE.REGS[rt];
		       break;

	       case DIV:
                       NEXT_STATE.LO = ((int32_t)CURRENT_STATE.REGS[rs] / (int32_t)CURRENT_STATE.REGS[rt]);
                       NEXT_STATE.HI = ((int32_t)CURRENT_STATE.REGS[rs] % (int32_t)CURRENT_STATE.REGS[rt]);
		       break;

               case DIVU:
                       NEXT_STATE.LO =(uint32_t)(CURRENT_STATE.REGS[rs] / (uint32_t)CURRENT_STATE.REGS[rt]);
                       NEXT_STATE.HI = ( (uint32_t)CURRENT_STATE.REGS[rs] % (uint32_t)CURRENT_STATE.REGS[rt]);
                       break;
               
	       case JALR:
                       NEXT_STATE.REGS[rs] = CURRENT_STATE.REGS[rs];
		       CURRENT_STATE.REGS[rd] = CURRENT_STATE.PC + 4;
		       NEXT_STATE.PC = NEXT_STATE.REGS[rd]; 
		       break;

               case JR:
                       NEXT_STATE.REGS[rs] = CURRENT_STATE.REGS[rs];
		       NEXT_STATE.PC = NEXT_STATE.REGS[rs];
		       break;

	       case MFHI:
                       NEXT_STATE.REGS[rd] = CURRENT_STATE.HI;
                       break;

               case MFLO:
                       NEXT_STATE.REGS[rd] = CURRENT_STATE.LO;
                       break;

               case MTHI:
                       NEXT_STATE.HI = CURRENT_STATE.REGS[rs];
		       break;

 	       case MTLO:
                       NEXT_STATE.LO = CURRENT_STATE.REGS[rs];
                       break;
                       
       	       case MULT:
		       int64_t temp_mult = (int32_t)CURRENT_STATE.REGS[rs] * (int32_t)CURRENT_STATE.REGS[rt];
                       NEXT_STATE.LO = temp_mult & 0x00000000ffffffff ; 
                       NEXT_STATE.HI = (temp_mult & 0xffffffff00000000)>> 32;
                       break;

               case MULTU:
                       uint64_t temp_multu = (uint32_t)CURRENT_STATE.REGS[rs] * (uint32_t)CURRENT_STATE.REGS[rt];
                       NEXT_STATE.LO = temp_multu & 0x00000000ffffffff ;
                       NEXT_STATE.HI = (temp_multu & 0xffffffff00000000)>> 32;
                       break;

               case NOR:
                       NEXT_STATE.REGS[rd] = ~ (CURRENT_STATE.REGS[rs] | CURRENT_STATE.REGS[rt]);
                       break;

               case OR:
                       NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] | CURRENT_STATE.REGS[rt];
                       break;

               case SLL:
                       NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rt] << shamt;
                       break;

	       case SLLV:
                       NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rt] << CURRENT_STATE.REGS[rs];
                       break;

               case SLT:
                       NEXT_STATE.REGS[rd] = ((int32_t)CURRENT_STATE.REGS[rs] < (int32_t)CURRENT_STATE.REGS[rt]) ? 1 : 0 ;
                       break;

               case SLTU:
                       NEXT_STATE.REGS[rd] = ( (uint32_t)CURRENT_STATE.REGS[rs]  < (uint32_t)CURRENT_STATE.REGS[rt] )? 1 : 0;
                       break;

               case SRA:
		       NEXT_STATE.REGS[rd] = (int)CURRENT_STATE.REGS[rt] >> shamt ;
                       break;

               case SRAV:
		       if(CURRENT_STATE.REGS[rt] < 0){
                       NEXT_STATE.REGS[rd] = ( CURRENT_STATE.REGS[rt] >> CURRENT_STATE.REGS[rs] ) | ( 1 << ( 32 - CURRENT_STATE.REGS[rs] ) );
                       }else{
                       NEXT_STATE.REGS[rd] = ( CURRENT_STATE.REGS[rt] >> CURRENT_STATE.REGS[rs] );}
                       break;

               case SRL:
                       NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rt] >> shamt;
                       break;

   	       case SRLV:
                       NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rt] >> CURRENT_STATE.REGS[rs];
                       break;

               case SUB:
                       NEXT_STATE.REGS[rd] = (int32_t)CURRENT_STATE.REGS[rs] - (int32_t)CURRENT_STATE.REGS[rt];
                       break;

               case SUBU:
                       NEXT_STATE.REGS[rd] = (uint32_t)CURRENT_STATE.REGS[rs] - (uint32_t)CURRENT_STATE.REGS[rt];
                       break;

               case XOR:
                       NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] ^ CURRENT_STATE.REGS[rt];
                       break;
	       
	       case SYSCALL:
		       if(CURRENT_STATE.REGS[2]==10){
		      	 RUN_BIT = FALSE;}
		       break;
	       default: 
		       printf("Opcode for R-type is not found");
		       break;
       }
}
void I_type_instruct(uint32_t rs,uint32_t rt,uint32_t immediate ,uint32_t op ){
        uint32_t address;
        if( (op == BLTZ) || (op == BGEZ) || (op == BLTZAL) || (op == BGEZAL) ){
              if(rt == 0x00){ // BLTZ
                 if((int32_t)CURRENT_STATE.REGS[rs]<0)
                   NEXT_STATE.PC = CURRENT_STATE.PC + ((int16_t)immediate << 2);
              }
	      else if(rt == 0x01){ //BGEZ
               if((uint32_t)CURRENT_STATE.REGS[rs]>=0)
                   NEXT_STATE.PC = CURRENT_STATE.PC + ((int16_t)immediate << 2);
              }
	      else if(rt == 0x10){ //BLTZAL
               if((int32_t)CURRENT_STATE.REGS[rs]<0){
                   NEXT_STATE.PC = CURRENT_STATE.PC + ((int16_t)immediate << 2);
	           NEXT_STATE.REGS[31] = CURRENT_STATE.PC + 4;
               }
              }
	      else if(rt == 0x11){ // BGEZAL
               if((int)CURRENT_STATE.REGS[rs]>=0){
                   NEXT_STATE.PC = CURRENT_STATE.PC + ((int16_t)immediate << 2);
                   NEXT_STATE.REGS[31] = CURRENT_STATE.PC + 4;
               }
              }
        }
        else 
           printf("opcode for BLTZ, BGEZ, BLTZAL, BGEZAL is not found \n");
             
	switch(op){

               case ADDI:
                       NEXT_STATE.REGS[rt] = (int32_t)CURRENT_STATE.REGS[rs] +(int16_t)immediate;
                       break;

               case ADDIU:
                       NEXT_STATE.REGS[rt] = (uint32_t)CURRENT_STATE.REGS[rs] + (int16_t)immediate;
                       break;

	       case ANDI:
                       NEXT_STATE.REGS[rt] = CURRENT_STATE.REGS[rs] & immediate;
                       break;

               case ORI:
                       NEXT_STATE.REGS[rt] = CURRENT_STATE.REGS[rs] | immediate;
                       break;

	       case XORI:
                       NEXT_STATE.REGS[rt] = CURRENT_STATE.REGS[rs] ^ immediate;
                       break;

               case SLTI:
                       NEXT_STATE.REGS[rt] = ((int32_t)CURRENT_STATE.REGS[rs] < (int16_t)immediate) ? 1 : 0 ;
                       break;

               case SLTIU:
                       NEXT_STATE.REGS[rt] = ((uint32_t)CURRENT_STATE.REGS[rs] < (uint16_t)immediate) ? 1 : 0 ;
                       break;

               case LB:
                       rs = CURRENT_STATE.REGS[rs];
                       address = ((int16_t)immediate + rs)  ;
                       NEXT_STATE.REGS[rt] = (int8_t)mem_read_32( address ) ;
                       break;
              
	       case LBU:
                       rs = CURRENT_STATE.REGS[rs];
                       address = ((int16_t)immediate + rs)  ;
	               NEXT_STATE.REGS[rt] = (uint8_t)mem_read_32( address ) ;                         
	               break;

               case LH:
                       rs = CURRENT_STATE.REGS[rs];
                       address = ((int16_t)immediate + rs)  ;
                       NEXT_STATE.REGS[rt] = (int16_t)mem_read_32( address ) ;
	               break;

	       case LHU:
	               rs = CURRENT_STATE.REGS[rs];
                       address = ((int16_t)immediate + rs)  ;
                       NEXT_STATE.REGS[rt] = (uint16_t)mem_read_32( address ) ;
 	      	       break;

               case LUI:
                       NEXT_STATE.REGS[rt] = (immediate << 16) & 0xffff0000;
                       break;

               case LW:
                       rs = CURRENT_STATE.REGS[rs];
                       address = ((int16_t)immediate + rs)  ;
                       NEXT_STATE.REGS[rt] =  mem_read_32( address ) ;
                       break;
               case SW:
                       rs = CURRENT_STATE.REGS[rs];
                       address = ((int16_t)immediate + rs) ;         
                       mem_write_32( address , CURRENT_STATE.REGS[rt] ) ;
                       break;

               case SH:
                       rs = CURRENT_STATE.REGS[rs];
                       address = ((int16_t)immediate + rs)  ;
                       mem_write_32(address , (int16_t)CURRENT_STATE.REGS[rt] ) ;
	     	       break;

               case SB:
                       rs = CURRENT_STATE.REGS[rs];
                       address = ((int16_t)immediate + rs)  ;
                       mem_write_32((uint32_t)address ,(int8_t)CURRENT_STATE.REGS[rt] ) ;
                       break;

	       case BEQ:       
		       if(CURRENT_STATE.REGS[rs]==CURRENT_STATE.REGS[rt])
                       NEXT_STATE.PC = CURRENT_STATE.PC + ((int16_t)immediate << 2);
                       break;
                       
	       case BNE:	
		       if(CURRENT_STATE.REGS[rs]!=CURRENT_STATE.REGS[rt])
	               NEXT_STATE.PC = CURRENT_STATE.PC + ((int16_t)immediate << 2);
		       break;

	       case BGTZ:
		       if((uint32_t)CURRENT_STATE.REGS[rs]>0)
               	       NEXT_STATE.PC = CURRENT_STATE.PC + ((int16_t)immediate << 2);
                       break;
                       
               case BLEZ:
		       if((int32_t)CURRENT_STATE.REGS[rs]<=0)
                       NEXT_STATE.PC = CURRENT_STATE.PC + ((int16_t)immediate << 2);
                       break;
            
	       default: 
	               if((op != BLTZ) || (op != BGEZ) || (op != BLTZAL) || (op != BGEZAL)) 
                            printf("opcode for I-type is not found\n");
		       else 
		            printf("regime opcode executed for BLTZ,BGEZ,BLTZAL,BGEZAL\n"); 
                       break;
        } 
}
void J_type_instruct(uint32_t op, uint32_t target){

        switch(op){
                   
              case J:     
	                NEXT_STATE.PC = ( ( CURRENT_STATE.PC  ) & 0Xf0000000) | (target<<2);
                        break;

              case JAL:
                        NEXT_STATE.REGS[31] = CURRENT_STATE.PC + 4;  
                        NEXT_STATE.PC = ( (CURRENT_STATE.PC  ) & 0Xf0000000) | (target<<2);
			break;

	      default:
                        printf("opcode for J- type is not found");
                        break;
        }
}
void process_instruction()
{
   uint32_t instruction = mem_read_32(CURRENT_STATE.PC);
   uint32_t op = instruction >> 26 ;
   uint32_t rs = ( instruction >> 21) & 0x1f  ;
   uint32_t rt = ( instruction >> 16) & 0x1f  ;
   uint32_t rd = ( instruction >> 11) & 0x1f  ;
   uint32_t shamt = ( instruction >> 6) & 0x1f  ;
   uint32_t funct = ( instruction ) & 0x3f;
   uint32_t immediate = (instruction & 0xffff) ;
   uint32_t target = instruction & 0x03ffffff    ;
   NEXT_STATE.PC = CURRENT_STATE.PC+ 4;    
   if(op == 0x00000000) R_type_instruct(rs,rt,rd,shamt,funct);
   else if( op == 0X02  || op == 0x03 ) J_type_instruct(op,target);
   else if( op != 0x00 || op != 0x02|| op != 0x03 || op != 0x10 || op != 0x11 || op != 0x12 ||  op != 0x13 ) I_type_instruct(rs,rt,immediate,op); 
   else printf("neither R OR I OR J TYPE");
}
