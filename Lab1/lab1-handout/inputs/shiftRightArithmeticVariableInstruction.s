.text

main:
   add $t0, $0 ,240
   add $t1, $0 ,229

   srav $v1,$t0,$t1

   j end

end:
   addi $v0,$0,10
   syscall
~

