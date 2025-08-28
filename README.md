# 🖥️ MIPS Instruction Set Simulator (C)

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Architecture](https://img.shields.io/badge/Architecture-MIPS-green.svg)](https://en.wikipedia.org/wiki/MIPS_architecture)

---

## 📌 Overview
This project is a **MIPS Instruction Set Simulator** implemented in **C**.  
It supports **R-type, I-type, and J-type instructions**, simulating instruction fetch, decode, execute, and update phases.  

---

## 🚀 Features
- ✅ Full support for **R-type** instructions (`ADD, SUB, MULT, DIV, AND, OR, XOR, SLT, shifts, etc.`)  
- ✅ Handles **I-type** instructions (`ADDI, LW, SW, BEQ, BNE, SLTI, LUI, etc.`)  
- ✅ Supports **J-type** instructions (`J, JAL`)  
- ✅ Special registers: **HI & LO** for multiplication/division results  
- ✅ Implements **syscall exit** to terminate simulation  
- ✅ Modular functions for **instruction decoding & execution**  

---

## 🏗️ Architecture
### 🔹 R-type
- Arithmetic: `ADD, SUB, MULT, DIV`  
- Logical: `AND, OR, NOR, XOR`  
- Shift: `SLL, SRL, SRA`  
- Control: `JR, JALR, SYSCALL`  

### 🔹 I-type
- Arithmetic Immediate: `ADDI, SLTI, ANDI, ORI`  
- Memory Access: `LW, SW, LB, LBU, LH, LHU, SB, SH`  
- Branch: `BEQ, BNE, BGTZ, BLEZ, BLTZ, BGEZ`  

### 🔹 J-type
- `J` → Jump  
- `JAL` → Jump and Link  

### 🔹 Special Features
- Syscall Exit: Ends simulation when $v0 == 10
- HI/LO Registers: Correct handling for multiplication/division results
- PC Update Logic: Default PC increments by 4 unless overwritten by branch/jump

---
## 🧪 Workflow
- **Write Assembly & Convert to Machine Code** :
  Assembly programs are written using MIPS instructions (e.g., ADD, ADDI, LW, BEQ).
  These are assembled into 32-bit machine code and loaded into memory.
- **Fetch**  : Read 32-bit instruction from memory at CURRENT_STATE.PC.
- **Decode** : Extract opcode and fields.
- **Execute**: Perform operation based on instruction type.
- **Update** : Write results to NEXT_STATE, memory, or special registers.
- **Commit** : Copy NEXT_STATE → CURRENT_STATE.

### 🧪 Flowchart for the MIPS Instruction Set Simulator
 <img width="500" height="400" alt="image" src="https://github.com/user-attachments/assets/2ca3af57-1a36-413c-b236-37052d8d84db" />

---

## 📊 Results
The simulator correctly updates registers, memory, and the program counter (PC) based on the executed MIPS instructions.

---

## 👨‍💻 Author
**Jason Linus Rodrigues**


---
