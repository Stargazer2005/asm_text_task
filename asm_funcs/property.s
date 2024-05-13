  .globl CheckProperty
CheckProperty:
  movb    $0,         %al
  testq   %rdi,       %rdi    # str ?= nullptr
  je      .Ret                # if (str == nullptr) return false;

  pushq   %rdi                # push str on stack
  movb    (%rdi),     %dil    # get char

.Action:
  call    isdigit
  testl   %eax,       %eax    # ? !isdigit(*str)
  jne     .Iteration          # if (isdigit(*str)) ++str;

  call    isalpha
  testl   %eax,       %eax    # ? !isalpha(*str)
  jne     .Iteration          # if (isalpha(*str)) ++str;

  popq    %rdi                # pop str from stack
  movb    $0,         %al     # if ((!isdigit(*str))&&(!isalpha(*str))) return false;
  jmp     .Ret

.Iteration:
  popq    %rdi                # pop str from stack
  incq    %rdi                # next char
  pushq   %rdi                # push str on stack

  movb    (%rdi),     %dil    # get char
  testb   %dil,       %dil    # *str ?= '\0'
  jne     .Action             # if (*str != '\0') repeat .Action

  popq    %rdi                # pop str from stack
  movb    $1,         %al     # if (*str != '\0') return true;

.Ret:
  ret     