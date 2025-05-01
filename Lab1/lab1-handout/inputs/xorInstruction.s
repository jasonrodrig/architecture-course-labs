.text

main:
   li $t0,0x1001
   li $t1,0x0110
   li $t2,0x1001

   xor $t8,$t0,$t1
   xor $t9,$t0,$t2

   j end

end:
   addiu $v0,$zero,10
   syscall
~

