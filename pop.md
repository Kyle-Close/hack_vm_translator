pop local 2 (same for argument, this, and that)

**Load local address into general space (R13 - R15)**
@LCL
D=M (D = 1015)
@2
D=D+A
@R13
M=D (R13 = 1017)

**Pop value @ top of stack in D**
@SP
A=M-1
D=M (Store 19 in D)

**Decrement stack pointer**
@SP
M=M-1

**Load top stack value into local + 2**
@R13
A=M
M=D
---------------------------------------
pop static 3

**Pop value @ top of stack in D**
@SP
A=M-1
D=M

**Decrement stack pointer**
@SP
M=M-1

**Put value from stack into static 3 location**
@vmFileName.3
M=D
--------------------------------
pop temp 4

**Pop value @ top of stack in D**
@SP
A=M-1
D=M

**Decrement stack pointer**
@SP
M=M-1

**Put value from stack into temp 4 location**
@9 (base addr of 5 + 4)
M=D
--------------------------------
pop pointer 0 (THIS)

**Pop value @ top of stack in D**
@SP
A=M-1
D=M

**Decrement stack pointer**
@SP
M=M-1

Put value from stack into pointer 0 (THIS)
@3
M=D
--------------------------------
pop pointer 1 (THAT)

**Pop value @ top of stack in D**
@SP
A=M-1
D=M

**Decrement stack pointer**
@SP
M=M-1

Put value from stack into pointer 1 (THAT)
@4
M=D