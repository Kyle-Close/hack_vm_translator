pop local 2 (same for argument, this, and that)

**Load local address into general space (R13 - R15)**
@LCL
D=M (D = 1015)
@2
D=D+A
@R13
M=D (R13 = 1017)

**Store value @ top of stack in D**
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