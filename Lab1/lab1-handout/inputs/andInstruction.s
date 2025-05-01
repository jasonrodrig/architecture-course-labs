.text


main:
   addiu $t0,$zero,0x1872
   addiu $t1,$zero,0x1060

   and $t8,$t0,$t1
   j end

end:
   addiu $v0,$zero,10
   syscall

