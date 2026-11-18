#include <stdio.h>
#include "chip8.h"


void instr_00E0(struct chip8* chip8_pnt); //1 -
void instr_00EE(struct chip8* chip8_pnt); //2 -
void instr_0NNN(struct chip8* chip8_pnt); //3 -
void instr_1NNN(struct chip8* chip8_pnt); //4 -
void instr_2NNN(struct chip8* chip8_pnt); //5 -
void instr_3XNN(struct chip8* chip8_pnt); //6 -
void instr_4XNN(struct chip8* chip8_pnt); //7 -
void instr_5XY0(struct chip8* chip8_pnt); //8 -
void instr_6XNN(struct chip8* chip8_pnt); //9 -
void instr_7XNN(struct chip8* chip8_pnt); //10 -
void instr_8XY0(struct chip8* chip8_pnt); //11 -
void instr_8XY1(struct chip8* chip8_pnt); //12 -
void instr_8XY2(struct chip8* chip8_pnt); //13 -
void instr_8XY3(struct chip8* chip8_pnt); //14 -
void instr_8XY4(struct chip8* chip8_pnt); //15 -
void instr_8XY5(struct chip8* chip8_pnt); //16 -
void instr_8XY6(struct chip8* chip8_pnt); //17 -
void instr_8XY7(struct chip8* chip8_pnt); //18 -
void instr_8XYE(struct chip8* chip8_pnt); //19 -
void instr_9XY0(struct chip8* chip8_pnt); //20 -
void instr_ANNN(struct chip8* chip8_pnt); //21 -
void instr_BNNN(struct chip8* chip8_pnt); //22 -
void instr_CXNN(struct chip8* chip8_pnt); //23 -
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
