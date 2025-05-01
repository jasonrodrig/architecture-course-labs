.text

main:
   li $t0,101
   li $t1,110

   or $t8,$t0,$t1

   j end

end:
   addiu $v0,$zero,10
   syscall

