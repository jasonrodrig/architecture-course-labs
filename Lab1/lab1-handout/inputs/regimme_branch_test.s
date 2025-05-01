
.text
main:
    addi $v0, $0, 10
    addi $t0, $0, 0        
    bgez $t0, greater_than_or_equal  
    ori $t1, $0, 0xffff       
    
greater_than_or_equal:
    addi $t2, $0 ,3  
    sub $t3, $t0 ,$t2
    lui $t4, 0xffff
    ori $t4 ,$t4, 0xffff
    bltz $t4 ,less_than
    ori $t5, $t5 , 0x1234
less_than:
    ori $t6 ,$t6, 0x1234
    bltzal $t4 , less_than_zero_and_link
    ori $t7, $t7, 0x5678  
less_than_zero_and_link:
    ori $t8 ,$t8, 0x9999
    bgezal $t0, greater_than_or_equal_and_link
    ori $t9 ,$t9, 0x7777
greater_than_or_equal_and_link:
    ori $v1 ,$v1, 0x1111
    syscall
#end:   
   syscall   
