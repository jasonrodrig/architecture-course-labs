.text

main:
   li $t0 , 2000
   li $t1 , 3000

   mtlo $t0
   mthi $t1

   j end

end :
      addiu $v0 , $zero , 10
      syscall
~

