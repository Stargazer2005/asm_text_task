# check_property.s
.section .text
.global CheckProperty

CheckProperty:
    # Input: const char* str (passed in %rdi)
    test %rdi, %rdi           # Check if pointer is valid
    jz .false                 # If str is NULL, return false

.loop:
    movb (%rdi), %al          # Load the current character
    inc %rdi                  # Move to the next character
    testb %al, %al            # Check if it's the null terminator
    jz .true                  # If null terminator, return true

    # Check if character is a digit
    cmpb $'0', %al
    jb .check_alpha           # If less than '0', check if it's an alpha
    cmpb $'9', %al
    jbe .loop                 # If between '0' and '9', continue

.check_alpha:
    # Check if character is an alpha
    cmpb $'A', %al
    jb .false                 # If less than 'A', return false
    cmpb $'z', %al
    ja .false                 # If greater than 'z', return false
    cmpb $'Z', %al
    jbe .loop                 # If between 'A' and 'Z', continue
    cmpb $'a', %al
    jb .false                 # If less than 'a', return false

    jmp .loop                 # Continue checking

.true:
    movl $1, %eax             # Return true (1)
    ret

.false:
    xor %eax, %eax            # Return false (0)
    ret