#include <stdio.h>
#include "decoder.h"

void decode_instruction(Instruction inst)
{
    uint32_t opcode = inst.raw & 0x7F;
    uint32_t rd = (inst.raw >> 7) & 0x1F;
    uint32_t funct3 = (inst.raw >> 12) & 0x7;
    uint32_t rs1 = (inst.raw >> 15) & 0x1F;
    uint32_t rs2 = (inst.raw >> 20) & 0x1F;
    uint32_t funct7 = (inst.raw >> 25) & 0x7F;
    int32_t imm = (int32_t)inst.raw >> 20;

if (opcode == 0x13)
{
    if (funct3 == 0)
    {
        printf("0x%08X %08X addi x%d, x%d, %d\n",
               inst.address, inst.raw, rd, rs1, imm);
    }
    else if (funct3 == 7)
    {
        printf("0x%08X %08X andi x%d, x%d, %d\n",
               inst.address, inst.raw, rd, rs1, imm);
    }
    else if (funct3 == 6)
    {
        printf("0x%08X %08X ori x%d, x%d, %d\n",
               inst.address, inst.raw, rd, rs1, imm);
    }
    else
    {
        printf("Unknown I-type instruction\n");
    }
}
else if (opcode == 0x03)
{
    if (funct3 == 2)
    {
        printf("0x%08X %08X lw x%d, %d(x%d)\n",
               inst.address,
               inst.raw,
               rd,
               imm,
               rs1);
    }
    else
    {
        printf("Unknown load instruction\n");
    }
}
else if (opcode == 0x33)
{
    if (funct3 == 0 && funct7 == 0)
    {
        printf("0x%08X %08X add x%d, x%d, x%d\n",
               inst.address, inst.raw, rd, rs1, rs2);
    }
    else if (funct3 == 0 && funct7 == 32)
    {
        printf("0x%08X %08X sub x%d, x%d, x%d\n",
               inst.address, inst.raw, rd, rs1, rs2);
    }
    else if (funct3 == 7 && funct7 == 0)
    {
        printf("0x%08X %08X and x%d, x%d, x%d\n",
               inst.address, inst.raw, rd, rs1, rs2);
    }
    else if (funct3 == 6 && funct7 == 0)
    {
        printf("0x%08X %08X or x%d, x%d, x%d\n",
               inst.address, inst.raw, rd, rs1, rs2);
    }
    else
    {
        printf("Unknown R-type instruction\n");
    }
}
    else
    {
        printf("Unknown opcode: 0x%X\n", opcode);
    }
}