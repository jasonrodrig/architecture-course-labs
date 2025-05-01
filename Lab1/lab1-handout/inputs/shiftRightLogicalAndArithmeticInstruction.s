.text

main:
   add $t0, $0,-256
   add $t1,$0,5

   sra $t8,$t0,5
   srl $t9,$t0,5

   j end

end:
   addi $v0,$0,10
   syscall

