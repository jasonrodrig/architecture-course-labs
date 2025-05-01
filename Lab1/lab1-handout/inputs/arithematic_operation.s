		.text
__start:	addiu $v0, $zero, 10
		addiu $t0, $zero, 5
		addiu $t1, $zero, 10
		add $t2, $t0, $t1 
		addu $t3, $t0, $t2
		sub $t4, $t3, $t2
                subu $t5, $t2, $t1
              
                sub $t2, $t4, $t2
                subu $t3, $t4, $t2     
               addiu $t0, $zero, 32760
               addiu $t1, $zero, 32760
               
               mult $t0, $t1 
               mfhi $t8
               mflo $t9
             
               mthi $t8
               mtlo $t9
               
              # multu $t0, $t1
              # div $t0, $t1
              # divu $t0, $t1
	       syscall
