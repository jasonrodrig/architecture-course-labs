.text

main:
      addi $a0,$zero,1022
      jal firstBranch
      add $6,$v0,1
      j end

firstBranch:
       add $v0,$a0,1022
       add $a1,$a0,2044
       add $24,$zero,$ra #stores pc+4 which is present in ra to register 29
       jal secondBranch
       jr $24

secondBranch:
       add $v1,$a1,1022
       jr $ra

end :
       add $v0,$zero,10
       syscall

