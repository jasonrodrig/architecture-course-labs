 
.text
 
main: 		addi $v0 , $zero, 10
      		addi $a0 , $zero, 5
      		addi $a1 , $zero, 5
     		jal sum_function
      		addi $s0, $v1, 0
      		addi $a0, $s0, 0
      		syscall
sum_function:
       		add $v1,$a0,$a1
       		jr $ra
