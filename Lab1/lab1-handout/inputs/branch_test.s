          .text 
main:

addiu $v0 ,$0 ,10 
addi $t0, $0, 2 # argument 0 = 2
addi $t1, $0, 3 # argu
addi $t3 ,$0, 2
bne $t0, $t1, not_equal # y = returned value
add $t2, $t0 ,$t1

not_equal:

add $t4, $t0, $t1 
beq $t0 ,$t3 , equal
sub $t5 ,$t3 , $t1

equal:

mult $t1, $t3
lui $t6, 0xffff
ori $t6, $t6 , 0xffff 
blez $t6, less_than 
sub $t7, $0, -1234

less_than:

sub $t8, $t1 , $t3
bgtz $t1 , greater_than
sub $t9, $0 ,-5678

greater_than:

add $v1, $t6 , $t1
syscall
