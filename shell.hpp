/***************************************************************/
/*                                                             */
/*   MIPS-32 Instruction Level Simulator                       */
/*                                                             */
/*   For TGGS Computer Architecture                            */
/*                                                             */
/*   Credit: ECE 447                                           */
/*   Carnegie Mellon University                                */
/*                                                             */
/***************************************************************/

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/*          DO NOT MODIFY THIS FILE!                            */
/*          You should only change sim.c!                       */
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

#ifndef _SIM_SHELL_H_
#define _SIM_SHELL_H_

#include "pipeline.hpp"
#include <stdint.h>
#include <iostream>
#include <vector>

#define FALSE 0
#define TRUE  1

#define MIPS_REGS 32

typedef struct CPU_State_Struct {

  uint32_t PC;		/* program counter */
  uint32_t REGS[MIPS_REGS]; /* register file. */
  uint32_t HI, LO;          /* special regs for mult/div. */
} CPU_State;


struct Cycle_Instance {
  CPU_State_Struct CPU_State;
  IFID_PIPELINE_REG IFID_Reg;
  IDEX_PILELINE_REG IDEX_Reg;
  EXMEM_PIPELINE_REG EXMEM_Reg;
  MEMWB_PIPELINE_REG MEMWB_Reg;
  WROTE_BACK WROTE_Reg;
  CONTROL_UNIT Control_Unit;
  HAZARD_UNIT Hazard_Unit;
  STALL_CYCLE Stall_Unit;
};

/* Data Structure for Latch */

extern CPU_State CURRENT_STATE, NEXT_STATE;

extern int RUN_BIT;	/* run bit */

extern bool DATA_FORWARD;

extern std::string OUTPUT;

extern std::vector<Cycle_Instance> Cycle_Instances;

uint32_t mem_read_32(uint32_t address);
void     mem_write_32(uint32_t address, uint32_t value);
void     run_shell(std::string instrs);
void     run(int num_cycles);

/* YOU IMPLEMENT THIS FUNCTION */
void process_instruction();

#endif
