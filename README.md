# 🏭 Robot Factory — Corewar Champion Assembler in C

[![Language: C](https://img.shields.io/badge/Language-C-00599C.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Build: Make](https://img.shields.io/badge/Build-Makefile-orange.svg)](Makefile)
[![Module: B-CPE-200](https://img.shields.io/badge/Epitech-B--CPE--200-blue.svg)](https://www.epitech.eu/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Epitech: Tek1](https://img.shields.io/badge/Epitech-Tek1-005696.svg)](https://www.epitech.eu/)

> **Robot Factory is the assembler companion tool for Corewar.** It compiles human-readable assembly source files (`.s`) into executable machine bytecode binaries (`.cor`).

---

## 🎯 Architecture & Two-Pass Compiler

To handle forward label references (e.g., jumping to a label defined further down the file), `asm` employs a **Two-Pass Lexing and Parsing Architecture**:

```text
Assembly File (.s)
       │
       ▼
[Pass 1: Tokenize & Symbol Table] ──► Validates mnemonics, records label offsets & sizes
       │
       ▼
[Pass 2: Bytecode Emission]       ──► Computes relative jumps, packs instructions & args
       │
       ▼
Champion Binary (.cor)            ──► Encodes big-endian header + bytecode instructions
```

### Binary Output Format (`.cor`)
1. **Magic Header:** 4-byte signature `0xea83f3` (`COREWAR_EXEC_MAGIC`).
2. **Prog Name:** 128-byte null-padded string (`PROG_NAME_LENGTH`).
3. **Prog Size:** 4-byte big-endian integer representing code payload size in bytes.
4. **Comment:** 2048-byte null-padded comment string (`COMMENT_LENGTH`).
5. **Instruction Payload:** Consecutive encoded opcode instructions, parameter coding bytes (CB/OCP), and argument values.

---

## 🛠️ Build & Usage

```bash
make
./asm champions/fluttershy.s
# Generates champions/fluttershy.cor
```

---

## 📜 License

Licensed under the **MIT License with attribution** to Lucas Lhomme (Crabe).
