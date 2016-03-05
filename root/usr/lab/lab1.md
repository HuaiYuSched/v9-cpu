#Lab1 doc    
##How to pass the parameter to instruction.    
In v9, the C function pass parameter by stack. That is, we need to load the paramemter from stack to register a, b and c for the instruction.   
For example, the BOUT needs two parameter.  So we use LL load paramemter port from stack to register a, and load paramemter val to register b by instruction LBL.    

```
out(port, val) {asm(LL,8); asm(LBL, 16); asm(BOUT);}
```
##Timer and interrput   
Use Time instruction to set timeout value, then use IVEC instruction to set interrupt handler as alltraps function.      
Alltraps function will push the register a, b and c to stack, then invoke trap function to handle traps, now as empty function. And also because of the lack of user environment support, we do not need to push the user stack pointer to kernel stack. After the return from trap function, use pop instruct to recover the interrupt context.    
##Output
Use BOUT instruction to output character to screen. Look the section one.
