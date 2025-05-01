.text

main:
   li $t0,100 #pseudo instruction used to load data into general purpose register ($t0)
   li $t1,6

   div $t0,$t1

   mflo $t8
   mfhi $t9
   j end

end:
    addiu $v0 , $zero , 10
    syscall


