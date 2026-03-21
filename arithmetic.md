add (sub, and, and or are the same template, just swap the operator on line 10. watch for order of op on sub)

**Load top stack value into D**
@SP
A=M-1
D=M

**Decrement stack pointer**
@SP
M=M-1

**Add up the top 2 values of stack & store in D**
A=M-1
D=D+M

**Add result to stack**
M=D
---------------------------------------------------------
neg (not is the same just with "!M")

@SP
A=M-1
M=-M
---------------------------------------------------------
eq (gt and lt are the same, just change the condition on line 42. watch for order of op on sub for gt & lt)

**Load top stack value into D**
@SP
A=M-1
D=M

**Decrement stack pointer**
@SP
M=M-1

**Subtract the top 2 values of stack & store in D**
A=M-1
D=D-M

**Generate unique label(s) to handle the branching**
@EQ_TRUE_0
D;JEQ
M=0
@END_0
JMP

(EQ_TRUE_0)
M=-1

(END_0)