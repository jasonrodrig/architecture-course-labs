.text

main:
   addi $a0 ,$zero,0
   addi $a1,$zero,1

   addi $a2,$zero,1000
   addi,$a3,$zero,2000

   bne $a0,$a1,subOperationLabel
   add $t0,$a3,$a2
   j end

subOperationLabel :
    sub $t0,$a2,$a3
    j end


end :  addi $v0,$zero,10
       syscall
~
~

