# RISC-V RV32I Instruction Decoder

## Project Description

This project is a RISC-V RV32I instruction decoder written in C. It reads 32-bit hexadecimal machine instructions from a text file, decodes them according to the RV32I instruction format, and prints the corresponding assembly instruction.

The project was developed as part of the Module 2 Grand Assignment.

---

## Project Structure

```
riscv-decoder/
│
├── include/
│   ├── common.h
│   ├── decoder.h
│   └── memory.h
│
├── src/
│   ├── main.c
│   ├── decoder.c
│   └── memory.c
│
├── test/
│   └── programs/
│       ├── branch.hex
│       ├── i_type.hex
│       ├── mixed.hex
│       ├── r_type.hex
│       └── sample.hex
│
├── docs/
│   └── DESIGN.md
│
├── Makefile
├── README.md
└── .gitignore
```

---

## Build Instructions

Build the project using the provided Makefile:

```bash
make
```

To remove generated files:

```bash
make clean
```

---

## Usage

Run the decoder by providing a hexadecimal instruction file.

```bash
./decoder test/programs/mixed.hex
```

---

## Sample Output

```
RISC-V Decoder Started
Loaded 9 instructions

0x00000000 00500113 addi x2, x0, 5
0x00000004 00A00193 addi x3, x0, 10
0x00000008 003100B3 add x1, x2, x3
0x0000000C 40310133 sub x2, x2, x3
0x00000010 0020A023 sw x2, 0(x1)
0x00000014 0000A103 lw x2, 0(x1)
0x00000018 FE209CE3 bne x1, x2, -8
0x0000001C 004000EF jal x1, 4
0x00000020 123452B7 lui x5, 0x12345000
```

---

## Supported Instructions

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

## Notes

- The project uses a modular design with separate source and header files.
- Include guards are used in all header files.
- Unknown instructions are reported as `UNKNOWN`.
- Immediate values for I-type, S-type, B-type, and J-type instructions are correctly sign-extended.
- During development on Windows, the project was also compiled manually using:

```bash
gcc src/main.c src/decoder.c src/memory.c -Iinclude -o decoder.exe
```