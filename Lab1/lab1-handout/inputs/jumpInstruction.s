
.text

main:
      addi $4,$zero,1024
      addi $5,$zero,2045
      j second_expression

second_expression:
      addi $6,$zero,777
      addi $7,$zero,16
      j update

update:
      add $8,$4,$5
      add $9,$6,$7
      j end

end :
      addi $v0 , $zero,10
      syscall

