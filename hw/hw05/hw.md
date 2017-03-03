Homework 05
==============================

> Problems from Chapter 5: [1 pt each]: 3, 4, 16, 17, 18, 20, 24, 27, 33, 49

## 3

> hash function that produces values n bits long, how would brute force be implemented, and expected work factor

A brute force would be done by generating all messages within the "key space" and feeding each message to the hashing algorithm. A collision is guaranteed after hashing all possible sequences n bits long, although due to the birthday problem, a collision is expected in half the "key space", or n/2. The expected workload is thus 2^(n/2) hashes to compute.

## 4

> Expected # of collisions in the following cases

a. hash function with 12 bit output, and hashes of 1024 random messages
1024 = 2^10
Due to the birthday problem, collisions are expected within 2^(12/2) messages. Since 1024 (2^10) is 2^4 times more, the expectation is  `2^4 = 16` collisions.

b. hash function with n bit output, and hashes of m random messages
You'd expect to find a collision in 2^(n/2) messages due to the birthday problem, so it should be roughly `a - (n/2)` collisions, where `m = 2^a`.

## 16

> HMAC outputs X with key K and message M. Can M' be found with HMAC also X when K is known and M is unknown?  If so give an algorithm. If not, why?

The only way to end with the same HMAC result X would be to find an M' that results in a collision, or find the original M. Thus, it's possible, but the algorithm would only be a simple brute force.

## 17

> Online bidding example

a. property(s) of hash that it utilizes
One-way for confidentiality with the bid amounts, and weak collision resistance for assurance that the bid amount is unambiguous and can't be another amount.

b. attack that finds bids between $10-20k using their hash
Since only 10,000 values have to be hashed, simply create a lookup table of all values prehashed. It can be done in just over 10 seconds and takes up less than a megabyte: `time for i in {10000..20000}; do echo -n $i | sha256sum >> sum; done`

c. Is part b a practical security concern
In this case yes because the entropy is fairly small and attacks would be easy to do.

d. Preventing part b
The message can be lengthened. A "salt" can be used by having the username in the hash, or including a nonce (ex: >32 bit random number) that the site stores, so that the bid's hash becomes `hash(username + bid amount + nonce)`. The workload for an attacker would skyrocket and discourage would-be attackers.

## 18

> Spam reduction example

a. property(s) of hash that it uses
One-way since you can't specify a desired output and then find the message that would create it.

b. hash message is now recipient email address, how to send spam without large amount of work
Since M is only the recipient address, the content of the email can be changed and different spammers can share message, R value, and time for sending spam to one specific recipient. It might also be possible to send spam to a dummy recipient controlled by the spammer and put the actual spam recipient as the cc email.

## 20



## 24

> Emulate coin flip over a network using given protocol

a. how to cheat
In this protocol, you're trusting K is genuinely random, but there's no proof to back that up. Alice can find a different K where X is the opposite value. R is simply irrelevant random bits that are ignored.

b. prevent cheating by modifying protocol to include hash
In the message to encrypt, include a hash of R, and Bob validates R produces the same hash on his own end.

## 27

> Email from someone claiming to be Alice with digital certificate

a. verify signature
hash the message, use CA's public key to decrypt included hash, compare the hashes.

b. why bother verifying
Anyone can change the signature and you can't trust it's valid until you verify it.

c. Why, if you trust the CA, then Alice must hold the private key unless it's compromised
By trusting the CA, you trust that they only give priv key of a certificate to the owner named on the certificate, and no one else has a copy. So by trusting the CA, you extend that trust to Alice's ownership of the priv key.

d. By trusting the CA and verifying the signature, what do you know about the sender's identity
Nothing, because all they gave you is the public cert.

## 33

> 2 out of 3 sharing scheme

a. Secrets (4, 10/3), (6, 2), (5, 8/3), what is secret S and equation of line?
slope = (8/3 - 10/3) / (5 - 4)
= (-2/3) / 1
= -2/3

y = -2x/3 + b
2 = -2(6)/3 + b
2 = -4 + b
b = 6

Line: y = -2x/3 + 6, or 2x/3 + y = 6
Secret: 6

b. equation of line ax + by = c (mod 13), with points (2, 2), (4, 9) (6, 3), what is secret S and equation of line mod 13?

slope = (9-2) / (4-2)
= 7/2

y intercept = 2 - 2 * (7/2)
= 2 - 7
= -5 = 8 mod 13

Line: y = 7x/2 + 8 or -7x/2 + y = 8
Secret: 8

## 49

> Random numbers in crypto must be unpredictable

a. Why is statistically random insufficient?
Because the next numbers from these RNGs can be predicted. If you can reasonably narrow down a random number in crypto, the entropy has decreased immensely and allows more precise brute forcing or other attacks that will break the encrypted data.

b. If keystream bits can be determined from keystream bit length, is this a security concern?
Yes it's a concern, because it's not guaranteed that the keystream's bit length is kept confidential.
