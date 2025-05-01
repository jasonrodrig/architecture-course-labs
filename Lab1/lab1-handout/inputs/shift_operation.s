		.text
__start:	addiu $v0, $zero, 10
		addiu $t0, $zero, 5
                addiu $t1, $zero, 1
		sll $t2, $t0, 1
		sllv $t3, $t0, $t1 
                slt $t4, $t0, $v0
                sltu $t5, $t0, $v0
                srl $t6, $t0, 1
                srlv $t7, $t0, $t1
                addiu $v1, $zero,-5  
                sra $t8, $v1, 1
                srav $t9, $v1, $t1

	                          
        #	addu $t3, $t0, $t2
	#	sub $t4, $t3, $t2
         #       subcdu $t5, $t2, $t1
                syscall 
