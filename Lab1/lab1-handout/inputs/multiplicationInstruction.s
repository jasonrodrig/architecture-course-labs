.text

main:
  lui $t0,  0xb104
  ori $t0 ,$t0, 0xeff1
  lui $t1 , 0xb4c0
  ori $t1, $t1, 0xfffb

  mult $t0,$t1
  j end

end : addiu $v0,$zero,10
      syscall

