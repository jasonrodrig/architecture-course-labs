
.text

main:
   li $t0,101

   ori $t8,$t0,100

   j end

end:
   addiu $v0,$zero,10
   syscall

