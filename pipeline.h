#include <stdint.h>

typedef enum Signal
{
    LOW,
    HIGH
} Signal;

typedef struct IFID_PIPELINE_REG
{
    uint32_t IR; // the instruction
    uint32_t PCPLUS4; // PC + 4
} IFID_PIPELINE_REG;

extern IFID_PIPELINE_REG IFID_REG;

typedef struct IDEX_PILELINE_REG
{
    uint32_t OP;
    uint32_t RSDATA;
    uint32_t RS;
    uint32_t RTDATA;
    uint32_t RT;
    uint32_t SA;
    uint32_t RD;
    uint32_t TARGET;
    uint32_t EXTENDEDIMM;
    uint32_t FUNCT;
    uint32_t PCPLUS4; // PC + 4
    uint32_t HI;
    uint32_t LO;
    uint32_t JUMPADDRESS;
    enum Signal RegDst;
    enum Signal Jump;
    enum Signal Branch;
    enum Signal MemRead;
    enum Signal MemToReg;
    enum Signal ALUOp;
    enum Signal MemWrite;
    enum Signal ALUSrc;
    enum Signal RegWrite;
    enum Signal SpecialRegHi;
    enum Signal SpecialRegLo;
    enum Signal Syscall;
} IDEX_PILELINE_REG;

extern IDEX_PILELINE_REG IDEX_REG;

typedef struct EXMEM_PIPELINE_REG
{
    // no extendImm, RSDATA/RTDATA, FUNCT
    uint32_t ALURESULT;
    uint32_t ALURESULT2;
    uint32_t JUMPADDRESS;
    uint32_t EXTENDEDIMM;
    uint32_t RSDATA;
    uint32_t RTDATA;
    uint32_t OP;
    uint32_t RD;
    uint32_t RS;
    uint32_t RT;
    // no ALUOp & ALUSrc
    enum Signal RegDst;
    enum Signal Jump;
    enum Signal BranchGate;
    enum Signal MemRead;
    enum Signal MemToReg;
    enum Signal MemWrite;
    enum Signal RegWrite;
    enum Signal SpecialRegHi;
    enum Signal SpecialRegLo;
    enum Signal Syscall;
} EXMEM_PIPELINE_REG;

extern EXMEM_PIPELINE_REG EXMEM_REG;

typedef struct MEMWB_PIPELINE_REG
{
    // no extendImm, RSDATA/RTDATA, FUNCT
    uint32_t ALURESULT;
    uint32_t ALURESULT2;
    uint32_t JUMPADDRESS;
    uint32_t RD;
    // no ALUOp & ALUSrc & MemRead/Write
    enum Signal RegDst;
    enum Signal Jump;
    enum Signal BranchGate;
    enum Signal MemToReg;
    enum Signal RegWrite;
    enum Signal SpecialRegHi;
    enum Signal SpecialRegLo;
    enum Signal Syscall;
} MEMWB_PIPELINE_REG;

extern MEMWB_PIPELINE_REG MEMWB_REG;

typedef struct CONTROL_UNIT
{
    enum Signal RegDst;
    enum Signal Jump;
    enum Signal Branch;
    enum Signal MemRead;
    enum Signal MemToReg;
    enum Signal ALUOp;
    enum Signal MemWrite;
    enum Signal ALUSrc;
    enum Signal RegWrite;
} CONTROL_UNIT;

extern CONTROL_UNIT CONTROL;

typedef struct HAZARD_UNIT
{
    int MAIN[34];
    int IDEX[34];
    int EXMEM[34];
    int MEMWB[34];
} HAZARD_UNIT;

extern HAZARD_UNIT HAZARD;

typedef struct STALL_CYCLE
{
    int Fetch;
    int Decode;
} STALL_CYCLE;
