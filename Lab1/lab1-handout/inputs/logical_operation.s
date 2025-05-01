		.text
__start:	addiu $v0, $zero, 10
		addiu $t0, $zero, 5
		and $t1, $t0, $v0
		nor $t2, $t0, $v0 
		or $t3, $t0, $v0
                xor $t4, $t0, $v0
                syscall   
