# Robot Factory — Corewar Assembler

> **Bytecode compiler and assembler for Corewar champions.**

## Overview
Lexes, parses, and encodes champion assembly source code (`.s`) into runnable binary bytecode files (`.cor`):
- Header generation (`magic`, `prog_name`, `comment`, `prog_size`)
- Label resolution and instruction offset computation
- Parameter byte encoding (direct, indirect, register)

## Build & Usage
```bash
make
./asm champion.s
# Generates champion.cor
```

## License
Open-source under MIT License.
