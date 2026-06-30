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

typedef struct
{
    uint32_t raw;
    uint32_t address;
} Instruction;

#endif