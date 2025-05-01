		.text
__start:	addiu $v0, $zero, 10
		addiu $t0, $zero, 204
		#addiu $t1, $zero, 170
		andi $t2, $t0, 240
		ori $t3, $t0, 15
	        xori $t4, $t0, 170
                slti $t5, $t0 , 200
                sltiu $t6:w, $t1, 200
		syscall
