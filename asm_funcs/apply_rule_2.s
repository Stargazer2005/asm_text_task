# apply_rule_2.s
.section .text
.global ApplyRule2

ApplyRule2:
    # Input: char* str (passed in %rdi)

    test %rdi, %rdi           # Check if pointer is NULL
    jz .exit                  # If NULL, exit

    movq %rdi, %rcx           # mod_str = str (start position)
    movb $0, %dl              # last_unique = '\0'
.loop:
    movb (%rdi), %al          # Load the current character
    testb %al, %al            # Check if it's the null terminator
    jz .finish                  # If null terminator, exit

    cmpb %dl, %al             # Compare with last_unique
    je .skip                  # If equal, skip

    movb %al, (%rcx)          # Store the unique character
    inc %rcx                  # Move mod_str forward
    movb %al, %dl             # Update last_unique

.skip:
    inc %rdi                  # Move to the next character
    jmp .loop                 # Repeat the loop

.finish:
    movb $0, (%rcx)           # Null terminate the modified string
.exit:
    ret