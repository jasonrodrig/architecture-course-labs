.data

array:      .byte  0x12, 0x34, 0x56, 0x78  # Byte array
half_array: .half  0x1234, 0x5678          # Halfword array
word_value:  .word  0xDEADBEEF              # Word value
float_value: .float 3.14                     # Floating-point value

.text
.globl main

main:
    # Load byte (signed)
    lb $t0, array          # Load byte at array[0] (0x12)

    # Load byte (unsigned)
    lbu $t1, array + 1    # Load byte at array[1] (0x34)

    # Load halfword (signed)
    lh $t2, half_array     # Load halfword at half_array[0] (0x1234)

    # Load halfword (unsigned)
    lhu $t3, half_array    # Load halfword at half_array[0] (0x1234)

    # Load upper immediate
    lui $t4, 0xDEAD        # Load upper immediate (0xDEAD0000)

    # Load word
    lw $t5, word_value      # Load word (0xDEADBEEF)

    # Load word to coprocessor 1 (floating-point)
    lwc1 $f0, float_value    # Load floating-point value (3.14)

    # Exit program
    addiu $v0, $zero, 10

                             # syscall for exit
    syscall
