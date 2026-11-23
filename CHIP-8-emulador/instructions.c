#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chip8.h"


void instr_00E0(struct chip8* chip8_pnt) {


}


void instr_00EE(struct chip8* chip8_pnt) {


}

void instr_0NNN(struct chip8* chip8_pnt) {


}

void instr_1NNN(struct chip8* chip8_pnt){


}

void instr_2NNN(struct chip8* chip8_pnt){


}

void instr_3XNN(struct chip8* chip8_pnt){


}

void instr_4XNN(struct chip8* chip8_pnt) {


}

void instr_5XY0(struct chip8* chip8_pnt){


}

void instr_6XNN(struct chip8* chip8_pnt){
	/*6XNN (MOV): VX = NN. Almacena el valor NN en VX.*/
	uint16_t opc = chip8_pnt->opcode;

	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t inm = (opc & 0x00FF);

	uint8_t* v = chip8_pnt->data_registers_v;

	v[x] = inm;

}

void instr_7XNN(struct chip8* chip8_pnt){
	/*7XNN (ADDi): VX = VX + NN. Suma el valor NN a VX*/

	uint16_t opc = chip8_pnt->opcode;

	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t inm = (opc & 0x00FF);

	uint8_t *v = chip8_pnt->data_registers_v;

	uint16_t add = v[x] + inm;

	v[x] = add;

}

void instr_8XY0(struct chip8* chip8_pnt){
	/*8XY0 (MOV): VX = VY. Almacena el valor de VY en VX*/

	uint16_t opc = chip8_pnt->opcode;

	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t y = (opc & 0x00F0) >> 4;

	uint8_t* v = chip8_pnt->data_registers_v;

	v[x] = v[y];

}

void instr_8XY1(struct chip8* chip8_pnt){
	/*8XY1 (OR): VX = VX OR VY*/

	uint16_t opc = chip8_pnt->opcode;

	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t y = (opc & 0x00FF);

	uint8_t* v = chip8_pnt->data_registers_v;

	uint8_t or = v[x] | v[y];

	v[x] = or;

}
void instr_8XY2(struct chip8* chip8_pnt){
	/*8XY2 (AND): VX = VX AND VY*/

	uint16_t opc = chip8_pnt->opcode;

	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t y = (opc & 0x00FF);

	uint8_t* v = chip8_pnt->data_registers_v;

	uint8_t and = v[x] & v[y];

	v[x] = and;

}
void instr_8XY3(struct chip8* chip8_pnt){
	/*8XY3 (XOR): VX = VX XOR VY.*/

	uint16_t opc = chip8_pnt->opcode;

	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t y = (opc & 0x00FF);

	uint8_t* v = chip8_pnt->data_registers_v;

	uint8_t xor = v[x] ^ v[y];

	v[x] = xor;

}

void instr_8XY4(struct chip8* chip8_pnt) {
	/*8XY4 (ADD): Suma VX = VX + VY. VF = 01 si hay acarreo (si el numero resulta
	ser mayor de 8 bits), si no VF = 00*/

	uint16_t opc = chip8_pnt->opcode;
	
	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t y = (opc & 0x00F0) >> 4;

	uint8_t *v = chip8_pnt->data_registers_v;

	uint16_t add=v[x]+v[y];
	v[x]= add & 0xFF;
	 

	if (add > 0xFF) {
		v[0xF] = 0x1;
	}else{
		v[0xF] = 0x0;
	}
}

void instr_8XY5(struct chip8* chip8_pnt){
	/*8XY5(SUB) : Resta VX = VX - VY.VF = 00 si hay pr´estamo, borrow(hay borrow
		si VY > VX).Si no VF = 01. Es decir, hace un NOT al borrow*/
	uint16_t opc = chip8_pnt->opcode;

	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t y = (opc & 0x00F0) >> 4;

	uint8_t *v = chip8_pnt->data_registers_v;

	uint16_t sub = v[x] - v[y];
	v[x] = sub & 0xFF;


	if (v[x] > v[y]) {
		v[0xF] = 0x1;
	}
	else {
		v[0xF] = 0x0;
	}
}


void instr_8XY6(struct chip8* chip8_pnt){
	/*8XY6(SHR) : Almacena en VX el valor de VY desplazado un bit a la derecha.
		VF(el registro F) = bit menos significativo de VY antes del desplazamiento.VY no
		cambia*/
	uint16_t opc = chip8_pnt->opcode;

	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t y = (opc & 0x00F0) >> 4;

	uint8_t* v = chip8_pnt->data_registers_v;

	uint8_t lsb = v[y] & 0x0001;
	v[0xF] = lsb;

	uint8_t shr = v[y] >> 1;
	v[x] = shr;

}

void instr_8XY7(struct chip8* chip8_pnt) {
	/*8XY7(SUB con operandos inversos) : Resta VX = VY - VX.VF = 00 si hay
		pr´estamo(hay borrow si VX > VY), si no VF = 01. Es decir, hace un NOT al
		borrow.*/
	
	uint16_t opc = chip8_pnt->opcode;

	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t y = (opc & 0x00F0) >> 4;

	uint8_t *v = chip8_pnt->data_registers_v;

	uint16_t sub = v[y] - v[x];
	v[x] = sub & 0xFF;


	if (v[x] < v[y]) {
		v[0xF] = 0x1;
	}
	else {
		v[0xF] = 0x0;
	}
}


void instr_8XYE(struct chip8* chip8_pnt){
	/*8XYE (SHL): Almacena en VX el valor de VY desplazado un bit a la izquierda.
	VF = bit m´as significativo de VY antes del desplazamiento. VY no cambia*/
	
	uint16_t opc = chip8_pnt->opcode;

	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t y = (opc & 0x00F0) >> 4;

	uint8_t* v = chip8_pnt->data_registers_v;

	uint8_t msb = (v[y] & 0x80) >> 7;
	v[0xF] = msb;

	uint8_t shl = v[y] << 1;
	v[x] = shl;
}

void instr_9XY0(struct chip8* chip8_pnt); //20 -
void instr_ANNN(struct chip8* chip8_pnt); //21 -
void instr_BNNN(struct chip8* chip8_pnt); //22 -
void instr_CXNN(struct chip8* chip8_pnt){
	/*CXNN (RND): VX = n ´umero aleatorio (entre 0 y 255) AND NN.*/
	
	srand(time(NULL));
	int rnd = rand();

	uint16_t opc = chip8_pnt->opcode;
	
	uint8_t nn= opc & 0xFF;
	
	uint8_t and = rnd & nn;

	uint8_t x = (opc & 0x0F00) >> 8;
	uint8_t* v = chip8_pnt->data_registers_v;

	v[x] = and;

}

void instr_DXYN(struct chip8* chip8_pnt); //24 -
void instr_EX9E(struct chip8* chip8_pnt); //25 -
void instr_EXA1(struct chip8* chip8_pnt); //26 -
void instr_FX07(struct chip8* chip8_pnt); //27 -
void instr_FX0A(struct chip8* chip8_pnt); //28 -
void instr_FX15(struct chip8* chip8_pnt); //29 -
void instr_FX18(struct chip8* chip8_pnt); //30 -
void instr_FX1E(struct chip8* chip8_pnt); //31 -
void instr_FX29(struct chip8* chip8_pnt); //32 -
void instr_FX33(struct chip8* chip8_pnt); //33 -
void instr_FX55(struct chip8* chip8_pnt); //34 -
void instr_FX65(struct chip8* chip8_pnt); //35 -
