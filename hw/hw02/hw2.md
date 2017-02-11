Homework 2
==============================

> **Due February 10, 2017**
> 
> Chapter 2 problems [1 pt each]:
> Do numbers 1, 5, 6, 8, 10, 12, 14, 19, 22, & 26.
> 
> For problem 12, you may provide your code in Java or C.
> Note that problem 12 will help you with problem 10.
> 
> The ciphertext for problem 10 is:
> `MXDXBVTZWVMXNSPBQXLIMSCCSGXSCJXBOVQXCJZMOJZCVCTVWJCZAAXZBCSSCJXBQCJZCOJZCNSPOXBXSBTVWJCJZDXGXXMOZQMSCSCJXBOVQXCJZMOJZCNSPJZHGXXMOSPLHJZDXZAAXZBXHCSCJXTCSGXSCJXBOVQX`
> 
> The first word of the plaintext is 'never'.

## 1

Kerckhoff's Principle

a. Define in context of cryptography
The security of a crypto algorithm does not depend on its secrecy. The way it works can be revealed without compromising it's security.

b. Real world example of Kerckhoff Principle being violated
This probably comes up anytime someone rolls their own crypto, because they likely rely on its secrecy for security, while the crypto system they implemented might be full of holes.

c. Example of Kerckhoff Principle applied broadly beyond crypto
The idea that security through obscurity is bad probably originates from Kerckhoff's Principle

## 5

Computer that can test 2^40 keys per second

(1 yr = 31536000 seconds)

a. Years to find key with 2^88 keyspace?
Assuming we can expect to find within first half:
2^(88-1) / 2^40
=> 2^(87-40) 
=> 2^47 
=> ~1.4*10^14 seconds / 31536000
=> ~4462756.5 years

b. Years to find key with 2^112 keyspace?
Formula: Years = 2^(keyspace - 1 - 40) / 31536000
=> 2^(112-41) / 31536000
=> 2^71 / 31536000
=> ~7.5*10^13 years

c. Years to find key with 2^256 keyspace?
=> 2^(256-41) / 31536000 years
=> 2^215 / 31536000 years
=> ~1.7*10^57 years

## 8

Confusion and diffusion

a. Define each in terms of crypto
Confusion is making the ciphertext look different from plaintext, while diffusion is distributing the plaintext throughout the resulting ciphertext.

b. Cipher that only uses confusion
Substitution ciphers and one-time pads would solely use confusion.

c. Cipher that only uses diffusion
Transposition ciphers rely only on diffusion.

d. Cipher that uses both
Cipher used in the Election of 1876 involved transposition and a codebook, or confusion and diffusion.

## 10

Crack the ciphertext (substitution):

```
MXDXBVTZWVMXNSPBQXLIMSCCSGXSCJXBOVQXCJZMOJZCVC
TVWJCZAAXZBCSSCJXBqCJZCQJZCNSPOXBXSBTVWJC
JZDXGXXMOZQMSCSCJXBOVQXCJZMOJZCNSPJZHGXXMOSPLH
JZDXZAAXZBXHCSCJXTCSGXSCJXBOVQX
```

NEVERIMAGINEYOURSELFNOTTOBEOTHERWISETHANWHATIT
MIGHTAPPEARTOOTHERSTHATSHATYOUWEREORMIGHT
HAVEBEENWASNOTOTHERWISETHANWHATYOUHADBEENWOULD
HAVEAPPEAREDTOTHEMTOBEOTHERWISE

## 12

Program for substitution

Refer to `10.c`.

## 14

Encrypt `we are all together` with double transposition cipher, 4x4 matrix, row 1234->2413, column 1234->3124

leagetwtaheolrre

## 19

Using table 2.1, ciphertext `KITLKE` encrypted with one-time pad. What is key when:

a. plaintext is thrill
lkistl

b. plaintext is tiller
lekekr

Also refer to `19.py`

## 22

Codebook with excerpt:

> 123 once
> 199 or
> 202 maybe
> 221 twice
> 233 time
> 332 upon
> 451 a

Decrypt
> 242 554 650 464 532 749 567

assuming additive sequence:
> 119 222 199 231 333 547 346

once up a time or maybe twice

## 26

Forward search attack

a. How to conduct
Encrypted message probably in small set of possibilities, all possibilities are encrypted to see if they match the encrypted message. This works in public key crypto since public keys are known to all.

b. How to prevent
Sufficiently large keyspace for message that the message itself cannot be guessed.

c. Why can't it be used on symmetric ciphers
Encryption/decryption relies on same key which is kept secret. Malicious user is thus unable to try encrypting and comparing resulting cipher text.
