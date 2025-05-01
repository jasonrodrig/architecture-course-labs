.text

main:
   lui $t4, 0x1000 #load upper immediate --> 0x10000000
   addiu $t0,$zero,3
   addi $t1,$zero,100
   addi $t2,$zero,200
   sb $t0 , 10($t4)
   lb $a1,10($t4) #based on this operations are selected

   beq $a1,0,addOperationLabel
   beq $a1,1,subOperationLabel
   beq $a1,2,mulOperationLabel
   beq $a1,3,divOperationLabel

addOperationLabel:
   add $v1,$t1,$t2
   j end

subOperationLabel:
   sub $v1,$t1,$t2
   j end
mulOperationLabel:
   mult $t1,$t2
   j end
divOperationLabel:
   div $t2,$t1
   j end

end:
   addiu $v0,$zero,10
   syscall

