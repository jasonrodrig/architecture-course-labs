		.text
__start:	addiu $v0, $zero, 10
		addiu $t0, $zero, 5
		addiu $t1, $t0, 300
		addiu $t2, $zero, 500
		addiu $t3, $t2, 34
		addiu $t3, $t3, 45
                addi $t4, $t2 , 500
                addi $t5, $zero, 300
                addi $v1, $zero, -5
                addi $t6, $t2 , -5
                addi $t7, $v1, -10
                addiu $t8 , $t7, -10
		syscall
