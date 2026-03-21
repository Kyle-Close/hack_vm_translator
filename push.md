push constant 17

@17
D=A

@SP -> RAM[0] (M=258)
A=M
M=D

@SP
M=M+1
--------------------------------
push argument 1 (same template for argument, local, this, and that)

@ARG
D=M
@1
A=D+A
D=M

@SP
A=M
M=D

@SP
M=M+1
--------------------------------
push local 5

@LCL
D=M
@5
A=D+A
D=M

@SP
A=M
M=D

@SP
M=M+1
--------------------------------
push static 3 (static RAM is from 16-255 - remember variables in asm start here)
3 -> vmFileName.3

@vmFileName.3 -> RAM[16]
D=M (D = whatever was in RAM[16])

@SP
A=M
M=D

@SP
M=M+1
--------------------------------
push temp 4

@9 (5 base addr + 4)
D=M

@SP
A=M
M=D

@SP
M=M+1
--------------------------------
push pointer 0 (THIS)

@3
D=M (base addr of THIS)

@SP
A=M
M=D

@SP
M=M+1
--------------------------------
push pointer 1 (THAT)
@4
D=M (base addr of THAT)

@SP
A=M
M=D

@SP
M=M+1
