
#include <stdio.h>
#include <stdint.h>

struct chip8 {
	uint16_t memory[4096];
	uint16_t opcode;
	uint8_t data_registers_v[0xF];
	uint16_t adress_register_i;
	uint16_t pc;
	uint16_t sp;
	uint16_t stack[11];
	uint8_t delay_timer;
	uint8_t sound_timer;
	uint16_t display[64*32]
	
	
	//mirar mas adelante si falta algo y completar
};