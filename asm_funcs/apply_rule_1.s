# apply_rule_1.s
.section .text
.global ApplyRule1

ApplyRule1:
    # Input: char* str (passed in %rdi)
    test %rdi, %rdi           # Check if pointer is valid
    jz .exit                  # If str is NULL, exit

.loop:
    movb (%rdi), %al          # Load the current character
    testb %al, %al            # Check if it's the null terminator
    jz .exit                  # If null terminator, exit

    cmpb $'1', %al            # Check if it's a digit
    jb .next                  # If less than '1', go to next
    cmpb $'9', %al
    ja .next                  # If greater than '9', go to next
    subb $'1', %al            # Convert character to integer (1-9)
    addb $'a', %al            # Convert to corresponding lowercase letter
    movb %al, (%rdi)          # Store the converted character

.next:
    inc %rdi                  # Move to the next character
    jmp .loop                 # Repeat the loop

.exit:
    ret