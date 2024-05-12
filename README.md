# asm_text_task
Assignment on the course Computer Architecture 1st year of DAFE/RSE MIPT

Interaction of C/C++ and assembly language.

A text (a sequence of characters) containing not more than 100 elements is given. The character with the code '\0' is considered to be a sign of the end of the text.

Required:

    - to enter the text from the keyboard and write it into the computer memory;
    
    - determine whether this text has the given property specified in your variant of the task;
    
    - convert the text according to rule 1 of your assignment, if it has the given property, and according to rule 2 otherwise;
    
    - display the source and transformed texts, as well as the number and wording of the applied rule.

Program Requirements:

    1. Input and output, memory allocation, test snap-in, and action selection logic are implemented in C/C++.
    
    2. Actions: property checking, application of rule #1 and rule #2 of text conversion, -- are realized in assembly language for Intel x86_64 architecture in AT&T syntax. Each action should be placed in a separate module (file). The implementation of an action may consist of several functions (procedures). The wording of the text property and its transformation rules for your variant should be placed in the comments of the corresponding modules (at the beginning of the file).
    
    3. Output of the source text should be performed immediately after input, before analysis and transformation.
    
    4. The output of the converted text should be executed only after the conversion is complete.
    
    5. The program should remain functional with any input data.
    
    6. A “test snap-in” should be developed to perform automatic testing.
    
Text property:

    Text contains no characters other than numbers and Latin letters.

Rule 1:

    Replace each non-zero digit with its corresponding sequentially numbered lowercase Latin letter (1->a, 2->b, etc.).

Rule 2:

    Leave only one character in each group of consecutive identical characters.
