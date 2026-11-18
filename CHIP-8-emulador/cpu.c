#include <stdio.h>
#include <stdint.h>
#include "chip8.h"
#include "instructions.h"

void cpu_step(struct chip8* chip8_pnt){
	fetch();
	decode_execute(chip8_pnt);
}

void decode_execute(struct chip8* chip8_pnt){
	uint16_t opc = chip8_pnt->opcode;
	switch (chip8_pnt->opcode * 0xF000) {

		case 0x0:
			if (opc == 0x00E0){ 
				instr_00E0(chip8_pnt);
			}else if(opc == 0x00EE){
				instr_00EE(chip8_pnt);
			}else{
				instr_0NNN(chip8_pnt);
			}
			break;

		case 0x1:
			instr_1NNN(chip8_pnt);
			break;

		case 0x2:
			instr_2NNN(chip8_pnt);
			break;

		case 0x3:
			instr_3XNN(chip8_pnt);
			break;

		case 0x4:
			instr_4XNN(chip8_pnt);
			break;

		case 0x5:
			instr_5XY0(chip8_pnt);
			break;

		case 0x6:
			instr_6XNN(chip8_pnt);
			break;

		case 0x7:
			instr_7XNN(chip8_pnt);
			break;

		case 0x8:
			switch(opc & 0x000F){
				case 0x0:
					instr_8XY0(chip8_pnt);
					break;

				case 0x1:
					instr_8XY1(chip8_pnt);
					break;

				case 0x2:
					instr_8XY2(chip8_pnt);
					break;

				case 0x3:
					instr_8XY3(chip8_pnt);
					break;

				case 0x4:
					instr_8XY4(chip8_pnt);
					break;

				case 0x5:
					instr_8XY5(chip8_pnt);
					break;

				case 0x6:
					instr_8XY6(chip8_pnt);
					break;

				case 0x7:
					instr_8XY7(chip8_pnt);
					break;

				case 0xE:
					instr_8XYE(chip8_pnt);
					break;	
			
			}
			break;

		case 0x9:
			instr_9XY0(chip8_pnt);
			break;

		case 0xA:
			instr_ANNN(chip8_pnt);
			break;

		case 0xB:
			instr_BNNN(chip8_pnt);
			break;

		case 0xC:
			instr_CXNN(chip8_pnt);
			break;

		case 0xD:
			instr_DXYN(chip8_pnt);
			break;

		case 0xE:
			if (opc & 0x00FF == 0x9E){
				instr_EX9E(chip8_pnt);
				
			}else{
				instr_EXA1(chip8_pnt);
				
			}
			break;

		case 0xF:
			switch (opc & 0x00FF){
				case 0x07:
					instr_FX07(chip8_pnt);

				break;
				case 0xA0:
					instr_FX0A(chip8_pnt);
				break;

				case 0x15:
					instr_FX15(chip8_pnt);
				break;

				case 0x18:
					instr_FX18(chip8_pnt);
				break;

				case 0x1E:
					instr_FX1E(chip8_pnt);
				break;

				case 0x29:
					instr_FX29(chip8_pnt);
				break;

				case 0x33:
					instr_FX33(chip8_pnt);
				break;

				case 0x55:
					instr_FX55(chip8_pnt);
				break;

				case 0x65:
					instr_FX65(chip8_pnt);
				break;
				
				
			
							
			}
			break;

}}