
.text

main:
    addi $t1 , $zero , 168
    addi $t3 , $zero,235
    sltiu $t2 , $t1 , 235
    beq $t2 , 1 , subOperationLabel
    j addOperationLabel

subOperationLabel :
   sub $t4,$t3,$t1
   j end

addOperationLabel :
   add $t4,$t3,$t1
   j end

end:
   addiu $v0,$zero,10
   syscall

