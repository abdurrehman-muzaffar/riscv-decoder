#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

#define MAX_INSTRUCTIONS 1024
#define LINE_BUFFER_SIZE 100

typedef enum
{
    INST_UNKNOWN,
    INST_R,
    INST_I,
    INST_S,
    INST_B,
    INST_U,
    INST_J
} InstructionType;

typedef enum
{
    OP_LOAD   = 0x03,
    OP_I_TYPE = 0x13,
    OP_STORE  = 0x23,
    OP_R_TYPE = 0x33,
    OP_LUI    = 0x37,
    OP_BRANCH = 0x63,
    OP_JAL    = 0x6F
} Opcode;

typedef struct
{
    uint32_t raw;
    uint32_t address;
} Instruction;

#endif