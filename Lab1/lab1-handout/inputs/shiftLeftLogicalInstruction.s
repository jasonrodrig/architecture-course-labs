.text

main:
   add $t0,$0,-256
   add $t1,$0,5

   sll $t8,$t0,$t1

   j end

end:
   addi $v0, $0, 10
   syscall

