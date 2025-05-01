.text

main:
  li $t0,101000000
  addiu $t1,$zero,32000

  div $t0,$t1
  j end

end : addiu $v0,$zero,10
      syscall
~

