.text

main:
   li $t0,0x1001

   xor $t8,$t0,0x0110
   xor $t9,$t0,0x1001

   j end

end:
   addiu $v0,$zero,10
   syscall
~

