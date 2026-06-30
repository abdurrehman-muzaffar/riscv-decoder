# Decoder Design

## Overview

The project is divided into multiple source files to improve readability, modularity, and maintainability.

Each module performs one specific task.

---

## Project Architecture

```
                 +----------------+
                 |   main.c       |
                 +--------+-------+
                          |
                          v
                 +----------------+
                 | memory.c       |
                 | Load HEX file  |
                 +--------+-------+
                          |
                          v
                 +----------------+
                 | decoder.c      |
                 | Decode RV32I   |
                 +--------+-------+
                          |
                          v
                 +----------------+
                 | Console Output |
                 +----------------+
```

---

## Module Responsibilities

### main.c

- Program entry point.
- Reads command-line arguments.
- Calls the memory loader.
- Calls the decoder for each instruction.

---

### memory.c

Responsible for reading hexadecimal instructions from a text file.

For each instruction it:

- Reads one line.
- Converts hexadecimal text into a 32-bit integer.
- Stores the instruction.
- Assigns its instruction address.

---

### decoder.c

Responsible for decoding every instruction.

The decoder:

- Extracts opcode.
- Extracts register fields.
- Extracts immediate values.
- Identifies the instruction format.
- Prints the decoded assembly instruction.

---

## Instruction Formats

The decoder supports:

### R-Type

- add
- sub
- and
- or

### I-Type

- addi
- andi
- ori
- lw

### S-Type

- sw

### B-Type

- beq
- bne

### U-Type

- lui

### J-Type

- jal

---

## Design Decisions

Several design decisions were made during implementation.

### Multi-file Organization

Instead of placing everything in one file, the project separates loading, decoding, and shared definitions into different modules.

This improves readability and maintenance.

---

### Header Files

Header files expose only the required functions and data structures.

Include guards prevent multiple inclusion errors.

---

### Opcode Enumeration

Opcode values are stored in an enumeration instead of using magic numbers.

This makes the decoder easier to understand and modify.

---

### Immediate Handling

Immediate values are reconstructed according to the RV32I instruction format.

Branch, Store, and Jump immediates are sign-extended before printing to correctly represent negative offsets.

---

## Testing

The decoder was tested using multiple hexadecimal instruction files.

The test suite includes:

- r_type.hex
- i_type.hex
- branch.hex
- mixed.hex

These test files verify decoding across multiple RV32I instruction formats.