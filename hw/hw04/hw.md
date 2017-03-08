Homework 4
==============================

> Problems for Chapter 4 [1 pt each]: #2, 6, 14, 15, 19, 20, 21, 25, 37, 38

## 2

> Bob receives Alice's cert from someone

a. What does Bob know about sender's identity
Bob doesn't know anything about the sender, since the cert is supposed to be public and anyone can obtain it (or create their own).

b. How to verify cert signature
The cert's own public key can be used to retrieve the signature's original message, which itself contains the public key and some basic cert details like the owner. Bob can use the result to compare with the plaintext information contained by the cert

c. After verifying signature, what does Bob know about sender's identity
Assuming the CA is trustworthy, Bob knows the public key is Alice's, and she has a private key, but not necessarily that the person he's talking to is actually Alice (they didn't use their private key yet).

## 6

> Alice RSA pub key is (33, 3), priv key is 7

a. Bob encrypts message 19, what is ciphertext, and decrypt back to plaintext
C = M^e mod N
= 19^3 mod 33
= 6859 mod 33
= **28**

M = C^e mod N
= 28^7 mod 33
= 13492928512 mod 33
= **19**

## 14

> Alice and Bob establish shared symmetric key by encrypting key with PIN number and sending it to each other. PINs are easily brute forced, find a more secure method.

Alice and Bob can first use Diffie-Hellman to establish a shared secret S. Bob then sends the message encrypted with the much longer key PIN + S. Note that this is vulnerable to MitM, and it will continue being a problem without pub/priv keys because Trudy can simply brute force anything hashed or encrypted.

## 15

> Digital signature and MAC provide data integrity. Why signatures also provide non-repudiation?

Signatures are directly related to the original message, and involve pub/priv keys. They show that the sender actually sent the message, and therefore the sender can't deny the message was legitimate. MACs on the other hand only the message hasn't changed after being sent.

## 19

> Given some protocol for Alice and Bob to send messages, Trudy can send nonsense messages and Bob recognizes them as real messages.

a. Is this a concern or annoyance
Only an annoyance because without Alice's private key, Trudy can't control the message that's produced, and can only send garbage.

b. Protocol changed so signature involves some function F. What conditions for F to prevent annoying attack in part a?
F needs to involve data that isn't publicly known, so Trudy can't simply generate it or take some public information to masquerade as legitimate.

## 20

> Knapsack priv key (3, 5, 10, 23), m^-1 = 6, modulus n = 47

a. plaintext when ciphertext is 20
(20 * 6) mod 47
= 120 mod 47
= 26
**1001**

b. plaintext when ciphertext is 29
(29 * 6) mod 47
= 174 mod 47
= 33
**0011**

c. what is m and public key
6 = m^-1 mod 47
**m = 8**

(SIK[n] * m) mod n
**public key: (24, 40, 33, 43)**

## 21

> SIK = (3, 5, 12, 23), n = 47, m = 6

a. find pub/priv keys
m^-1 mod n
= 6^-1 mod 47
= 8

**priv key: (3, 5, 12, 23), 8**

**public key: (18, 30, 25, 44)**

b. encrypt M = 1110
18 + 30 + 25 + 0
= **73**

## 25

> DH MitM where Trudy establishes key that everyone shares. Is this possible?

Yes, assuming that Trudy gets Alice and Bob to send first, Trudy can then calculate each value including her t, and send that to the opposite party. The mod math would also work.

> it would actually not work because Trudy would be actually be calculating g^(abt) mod p. The mod math wouuld **not** work.

## 37

> Digital signature or MAC can be used for integrity checking

a. Which would you recommend for cryptographic integrity checking
If they're using pub/priv keys I'd recommend signing since it also offers non repudiation. If they're working on a lower level, or if restricted to symmetric crypto, I'd recommend.

b. Which would you recommend if non repudiation also required
Digital signature would be the only option if non repudiation is a requirement.

## 38

> Get MAC and digitally sign afterwards

a. Does it provide integrity
The MAC will provide integrity as part of its definition, but the digital signature will tell you nothing except whether the MAC has been altered. Unless the malicious actor knows the private key and can change the encrypted MAC without corrupting it, this is probably an unnecessary measure.

b. Does it provide non repudiation
No, because the message itself isn't being signed. Therefore, there's no proof that the message definitely came from Alice or Bob. The MAC itself only tells message integrity, not the message itself.

c. Is this a good idea
As covered in part a, the chance of MAC integrity being compromised while not raising alarm of data being corrupted is very low.
