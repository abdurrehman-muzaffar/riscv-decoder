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
    int32_t s_imm = (((inst.raw >> 25) & 0x7F) << 5) |
                ((inst.raw >> 7) & 0x1F);
    if (s_imm & (1 << 11))
{
    s_imm |= ~0xFFF;
}
    int32_t b_imm =
    (((inst.raw >> 31) & 0x1) << 12) |
    (((inst.raw >> 7) & 0x1) << 11) |
    (((inst.raw >> 25) & 0x3F) << 5) |
    (((inst.raw >> 8) & 0xF) << 1);
    if (b_imm & (1 << 12))
{
    b_imm |= ~0x1FFF;
}
    uint32_t u_imm = inst.raw & 0xFFFFF000;
    int32_t j_imm =
    (((inst.raw >> 31) & 0x1) << 20) |
    (((inst.raw >> 12) & 0xFF) << 12) |
    (((inst.raw >> 20) & 0x1) << 11) |
    (((inst.raw >> 21) & 0x3FF) << 1);
    if (j_imm & (1 << 20))
{
    j_imm |= ~0x1FFFFF;
}

if (opcode == OP_I_TYPE)
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
        printf("0x%08X %08X UNKNOWN\n",
        inst.address,
        inst.raw);
    }
}
else if (opcode == OP_LOAD)
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
        printf("0x%08X %08X UNKNOWN\n",
       inst.address,
       inst.raw);
    }
}
else if (opcode == OP_R_TYPE)
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
        printf("0x%08X %08X UNKNOWN\n",
       inst.address,
       inst.raw);
    }
}
else if (opcode == OP_STORE)
{
    if (funct3 == 2)
    {
        printf("0x%08X %08X sw x%d, %d(x%d)\n",
               inst.address,
               inst.raw,
               rs2,
               s_imm,
               rs1);
    }
    else
    {
        printf("0x%08X %08X UNKNOWN\n",
       inst.address,
       inst.raw);
    }
}
else if (opcode == OP_BRANCH)
{
    if (funct3 == 0)
    {
        printf("0x%08X %08X beq x%d, x%d, %d\n",
               inst.address,
               inst.raw,
               rs1,
               rs2,
               b_imm);
    }
    else if (funct3 == 1)
    {
        printf("0x%08X %08X bne x%d, x%d, %d\n",
               inst.address,
               inst.raw,
               rs1,
               rs2,
               b_imm);
    }
    else
    {
        printf("0x%08X %08X UNKNOWN\n",
       inst.address,
       inst.raw);
    }
}
else if (opcode == OP_LUI)
{
    printf("0x%08X %08X lui x%d, 0x%X\n",
           inst.address,
           inst.raw,
           rd,
           u_imm);
}
else if (opcode == OP_JAL)
{
    printf("0x%08X %08X jal x%d, %d\n",
           inst.address,
           inst.raw,
           rd,
           j_imm);
}
    else
    {
        printf("0x%08X %08X UNKNOWN\n",
       inst.address,
       inst.raw);
    }
}