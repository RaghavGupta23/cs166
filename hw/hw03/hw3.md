Homework 3
==============================

> Do the following problems from Chapter 3: #3, 12, 25, 31, 36
> 
> For #12, simplify your answer for full credit.
> 
> Implement the TEA algorithm in C using CBC mode.  Starter code is provided in C at http://cs.sjsu.edu/~austin/cs166-spring15/hw3/tea.c.  This code provides an example using ECB mode, which may be helpful.  The changes you need to make:
> 1) Put your name at the top of the file
> 2) implement the encrypt function.
> 3) implement the decrypt function.
> 4) complete the cbc_mode_test function.
> 4) complete the ctr_mode_test function.
> 
> Note that the encryption should happen in place; that is, the original contents of the text array will be mutated.  After you have encrypted and decrypted the text, you should have the same plaintext.
> 
> **DO NOT CHANGE ANY PRINT STATEMENTS IN THIS CODE.**
> 
> **YOU MUST USE THE SPECIFIED INITIALIZATION VALUES FOR CBC MODE AND CTR MODE**
> 
> Note that unint32_t is 32 bits, exactly the size of half of a 64-bit block.  The details of TEA's encryption and decryption algorithm are given in Figure 3.6 and Figure 3.7, respectively.  The XOR operator in C is '^'.
> 
> If you use any external references, document them.  If you use a source other than your textbook and you do not cite it, you will get 0 points for this assignment.
> 
> Upload your code as a separate attachment with a .c extension.

## 3

> Finding key for stream cipher when plaintext is known

a. Determining key stream
Since stream ciphers simply XOR the keystream with the plaintext, the cipher and plaintext can be XORed to obtain the keystream will easily yield the results. i.e. C: 1001 0011, P: 1101 0100, therefore XORing the two produces K: 0100 0111.

b. Replacing with different plaintext
With the key found via part A, and since the encryption is simply XOR, a new message can be encrypted instead. i.e. P': 1010 1010, using previous key, C': 1110 1101.

## 12

> Feistal Cipher with four rounds, what is C = (L4, R4) in terms of L0, R0, and subkey for each round function

a. F(Ri-1, Ki) = 0
L1 = R0
R1 = L0 ^ F(R0, K1) = L0 ^ 0 = 0

L2 = 0
R2 = L1 ^ F(R1, K2) = L1 ^ 0 = 0

L3 = 0
R3 = L2 ^ F(R2, K3) = L2 ^ 0 = 0

L4 = 0
R4 = L3 ^ F(R1, K4) = L3 ^ 0 = 0

C = **(0, 0)**

b. F(Ri-1, Ki) = Ri-1
L1 = R0
R1 = L0 ^ F(R0, K1) = L0 ^ R0

L2 = R1 = L0 ^ R0
R2 = L1 ^ F(R1, K2) = R0 ^ R0 = 0

L3 = R2 = 0
R3 = L0 ^ R0 ^ F(R2, K3) = L0 ^ R0 ^ 0 = L0 ^ R0

L4 = R3 = L0 ^ R0
R4 = 0 ^ F(R3, K4) = 0 ^ L0 ^ R0 = L0 ^ R0

C = **(L0 ^ R0, L0 ^ R0)**

c. F(Ri-1, Ki) = Ki
L1 = R0
R1 = L0 ^ F(R0, K1) = L0 ^ K1

L2 = R1 = L0 ^ K1 
R2 = L1 ^ F(R1, K2) = R0 ^ K2

L3 = R2 = R0 ^ K2
R3 = L2 ^ F(R2, K3) = L0 ^ K1 ^ K3

L4 = R3 = L0 ^ K1 ^ K3
R4 = L3 ^ F(R3, K4) = R0 ^ K2 ^ K4

C = **(L0 ^ K1 ^ K3, R0 ^ K2 ^ K4)**

d. F(Ri-1, Ki) = Ri-1 ^ Ki
L1 = R0
R1 = L0 ^ F(R0, K1) = L0 ^ R0 ^ K1

L2 = R1 = L0 ^ R0 ^ K1
R2 = L1 ^ F(R1, K2) = L1 ^ R1 ^ K2 = L0 ^ K1 ^ K2

L3 = R2 = L0 ^ K1 ^ K2
R3 = L2 ^ F(R2, K3) = L2 ^ R2 ^ K3 = R0 ^ K2

L4 = R3 = R0 ^ K2
R4 = L3 ^ F(R3, K4) = L3 ^ R3 ^ K4 = L0 ^ R0 ^ K1 ^ K4

C = **(R0 ^ K2, L0 ^ R0 ^ K1 ^ K4)**

## 25

> Block cipher

a. decryption rule
P0 = D(IV ^ C0, K), P1 = D(C0 ^ C1, K), P2 = D(C1 ^ C2, K), etc.

b. Security disadvantages versus CBC
The IV and ciphertext being XORed after encryption means that data can be XORed with captured ciphertext, downgrading this pseudo-CBC to EBC, and is vulnerable to the new ciphertext-only attack. Secondly, the ciphertext blocks can be moved around and re-XORed so the message is changed but not corrupted. Although, note that CBC is also vulnerable to an extent.

## 31

> Static IV instead of randomly generated

a. Issues with CBC
If the same message is repeated, the ciphertext would be identical since having the same IV prevents a different ciphertext from being generated. This also means that a MAC, without a nonce, would be the same and the message therefore susceptible to "fun" stuff like replay attacks.

b. Issues with CTR
The same issues with CBC apply. Also, depending on the encryption method used, the key might be retrieved since the IV being encrypted is known. It may potentially be a problem that the encrypted IV is now an alteration to the key, but doesn't add much entropy.

c. Would CBC or CTR be more secure
CBC, because CTR suffers the same drawbacks, and some theoretical/situational ones.

## 36

> Integrity check by decrypting & re-encrypting, and comparing last ciphertext block

a. Does integrity check find if Trudy changes C1 to X, everything else unchanged
Yes, because the upstream change will propagate down during encryption.

b. What if C3 changed to Y
Y' = D(Y, K) ^ C2
Y = E(Y' ^ C2, K)
No, because Bob has nothing to compare Y/C3 with except itself.

c. Is this method secure
No, despite it being similar to MAC, Alice doesn't send a MAC, which results in the issue in part B.
