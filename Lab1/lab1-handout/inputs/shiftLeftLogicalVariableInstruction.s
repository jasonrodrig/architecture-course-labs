.text

main:
   add $t0, $0,-256
   add $t1, $0 ,197

   sllv $t8,$t0,$t1

   j end

end:
   addi $v0, $0 ,10
   syscall

