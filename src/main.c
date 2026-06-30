#include <stdio.h>
#include "memory.h"
#include "decoder.h"

int main(int argc, char *argv[])
{
    Instruction instructions[MAX_INSTRUCTIONS];

    printf("RISC-V Decoder Started\n");

    if (argc < 2)
    {
        printf("Usage: decoder <hexfile>\n");
        return 1;
    }

    int count = load_hex_file(argv[1], instructions);

    if (count == -1)
    {
        return 1;
    }

printf("Loaded %d instructions\n", count);

for (int i = 0; i < count; i++)
{
    decode_instruction(instructions[i]);
}

return 0;
}