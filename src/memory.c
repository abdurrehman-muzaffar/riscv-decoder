#include <stdio.h>
#include "memory.h"
#include "common.h"

int load_hex_file(const char *filename, Instruction instructions[])
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    char line[LINE_BUFFER_SIZE];
    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        unsigned int instruction_value;

        if (sscanf(line, "%x", &instruction_value) == 1)
        {
            instructions[count].raw = instruction_value;
            instructions[count].address = count * 4;
            count++;
        }
    }

    fclose(file);
    return count;
}