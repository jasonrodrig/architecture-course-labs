.text
__start:        addiu $v1,$zero,-10 #1 $v1 = 0 - 10
                addiu $v1,$v1,-3 #2 $v1 = -10 - 3 = -13
                addi $a0,$v1,180 #3 $a0 = -13 + 180 = 167
                addi $a1,$zero,-13 #4 $a1 = 0 - 13 = -13
                beq $a1,$v1,pass1 #5 true, goes to pass1 -13 == -13
pass2:
                addi $a2,$v1,13 #7 $a2 = -13 + 13 = 0
                blez $a2,pass3  #8 true goes to pass3 0 <= 0
pass1:
                bgtz $a0, pass2 #6 true goes to pass2 167>0
pass3:
                bltzal $v1, pass4 #9 true goes to pass4 & over writes ra -13 < 0
                slti $t6,$a1,150 #20 -13 < 150 => $t6 = 0x00000001
                sltiu $t7,$a1,150 #21 0xfffffff3 < 150 => $t7 = 0x00000000
                andi  $s0,$v1,2 #22 $s0 = 0xfffffff3 & 0x00000002 = 0x00000002
                xori  $s1,$a2,160 #23 $s1 = 160 ^ 0 = 0x000000a0
                bne $v1,$a1,pass5 #24 False goes next step bgez
                bgez $a0,pass5 #25 True goes to pass 5
pass6:
                lui $t0, 543 #27 0x21f00000
                ori $t0, 48 #28 $t0 = 0x21f00030
                lb $t1, -1($a3) #29 $t1 = sign extended 0xff = 0xffffffff
                lh $t2, 0($a3) #30 $t2 = sign extended 0x6967 = 0x00006967
                lw $t3, 4($a3) #31 $t3 = 0x0000000a
                lbu $t4, -1($a3) #32 $t4 = 0xff = 0x000000ff
                lhu $t5, 0($a3) #33 $t5 = 0x6967 = 0x00006967
                bltz $a0,pass6 #34 FALSE goes to jr
                jr $ra #35 goes back after pass5
pass4:
                lui $a3,4096 #10 
                ori $a3,4 #11 $a3 = 0 + initial address of data mem(0x10000000) + 4 = 0x10000004
                addiu $s4,$zero,-1 #12 $s4 = 0 - 1 = 0xffffffff
                lui $s5,38760 #13 
                ori $s5,26983 #14 $s5 = 0x97686967
                sb $s4, -1($a3) #15 stores 0xff in 0x10000003
                sh $s5, 0($a3) #16 stores 0x6967 in 0x10000004 - 0x10000005
                addiu $s3,$zero,10 #17 $s3 = 0x0000000a
                sw $s3, 4($a3) #18 stores 0x0000000a in 0x10000008 - 0x1000000b
                jr $ra #19 goes back to after pass 3
pass5:
                bgezal $a0,pass6 #26 TRUE goes to pass 6
                addiu $v0,$zero,10 #35 $v0 = 0x0000000a
                syscall #36 END
