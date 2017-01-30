Do the following problems from Chapter 3: #3, 12, 25, 31, 36

For #12, simplify your answer for full credit.

Implement the TEA algorithm in C using CBC mode.  Starter code is provided in C at http://cs.sjsu.edu/~austin/cs166-spring15/hw3/tea.c.  This code provides an example using ECB mode, which may be helpful.  The changes you need to make:
1) Put your name at the top of the file
2) implement the encrypt function.
3) implement the decrypt function.
4) complete the cbc_mode_test function.
4) complete the ctr_mode_test function.

Note that the encryption should happen in place; that is, the original contents of the text array will be mutated.  After you have encrypted and decrypted the text, you should have the same plaintext.

**DO NOT CHANGE ANY PRINT STATEMENTS IN THIS CODE.**

**YOU MUST USE THE SPECIFIED INITIALIZATION VALUES FOR CBC MODE AND CTR MODE**

Note that unint32_t is 32 bits, exactly the size of half of a 64-bit block.  The details of TEA's encryption and decryption algorithm are given in Figure 3.6 and Figure 3.7, respectively.  The XOR operator in C is '^'.

If you use any external references, document them.  If you use a source other than your textbook and you do not cite it, you will get 0 points for this assignment.

Upload your code as a separate attachment with a .c extension.

