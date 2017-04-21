Chapter 10
==============================

> From chapter 10, do problems #1, 6, 11, 17, 19, 23, 25, 27, 37, & 43.

## 1

> SSH Protocol
> A. How is Alice authenticated, how is replay prevented
> B. Why isn't key `K` revealed to passive attacker
> C. Show how Trudy actively attacking and impersonating Bob can get key `K`
> D. Why is final message encrypted with `K`

### A

Alice is authenticated in the last message containing the signed `Sa`. The `Rb` she sends back with `Sa` also prevents replay attacks since Bob can verify if it's the nonce he sent in the second message.

### B

The key isn't revealed because it's derived from the Diffie Hellman key exchange process, which maintains secrecy of the end key that two parties arrive at.

### C

Trudy can alter the `g^b mod p` value to `g^t mod p` so she can get her own `K` with alice. However, it doesn't break SSH because the `Sa` value Alice sends back to Bob won't have the correct DH key values. Bob won't allow the SSH connection to proceed, as the protocol is intended to work, so Trudy gets a key `K` that won't actually be used for anything.

### D

Encrypting with `K` ensure that only whoever has the key has access to the contents. The DH exchange means only Alice and Bob has `K`, while signing the DH messages from the exchange process with `Sa` validates that tampering wasn't involved.

## 6

> SSL Protocol
> A. `Ra` and `Rb` removed and `K` becomes `h(S)`, what's the effect?
> B. Message 4 changed to `HMAC(msgs, SRVR, K)`, what's the effect?
> C. Message 3 changed to `{S}Bob, h(msgs, CLNT, K)`, what's the effect?

### A

Since there's no nonces, it's now susceptible to replay attacks and Trudy can act as Alice. Notably, Alice doesn't know the key `K`, nor can she get the premaster secret since she can't decrypt `{S}Bob`. But since she controls what `S` and therefore `K` are, she can save the rest of the conversation encrypted by `K` and replay that back to Bob.

### B

It would pretty much be the same, since `h(data,K)` is basically an HMAC, being the hash of a message and a key. The difference would be that an actual HMAC would conform to the standard as defined by RFC.

### C

It doesn't seem to serve much of a purpose, since `K` is supposed to be secret, so Trudy shouldn't be able to recreate the hash. It can't be replayed in the 4th message, because Bob hashes `SRVR` instead, creating a different hash. Perhaps the creators thought the more encryption the better.

## 11

> SSL and IPSec are designed for security over a network
> A. Primary advantages of SSL over IPSec
> B. Primary advantages of IPSec over SSL

### A

SSL provides more robust security via less complexity, but requires application to implement since it's higher on network stack.

### B

Lives in network layer, so applications can utilize without implementing, and it secures potentially revealing metadata in the transport layer. It also theoretically keeps identities secret.

## 17

> Kerberos
> A. Why can Alice remain anonymous when requesting a ticket to Bob?
> B. Why can Alice not remain anonymous when requesting a TGT from the KDC?
> C. Why can Alice remain anonymous when she sends the “ticket to Bob” to Bob?

### A

Alice's request is encrypted by `Kkdc`, which only the KDC has. The reply contains data encrypted by a key `Sa`, given to Alice earlier, and encrypted with her key.

### B

Kerberos needs to know who sent the request so it can encrypt the TGT with the key of whoever requested it. That means Alice needs to reveal her identity.

### C

The entire message to Bob, including Alice's identity, is encrypted with Bob's key, so only he can read it.

## 19

> Entering voucher number where last 5 hex characters may not be available. Wildcard can substitute characters that aren't readable to inform tellers whether voucher exists.
> A. Without wildcards, how many guesses on average?
> B. With wildcards, how many guesses on average?
> C. How can a dishonest teller exploit wildcards?
> D. What is the risk, how would they be caught?
> E. Modify system to securely and efficiently allow wildcards.

### A

Brute force of 5 hex chars:

Total possibilities: 16^5
Expected work: 16^5 / 2

16^5 / 2
= 1048576 / 2
= **524288 guesses**

### B

Since the teller can remove wildcards one at a time, they can test one hex at a time.

Total possibilities after wildcard: 16 * 5
Expected work: 16 * 5 / 2

16 * 5 / 2
= 8 * 5
= **40 guesses**

### C

The teller can get any valid voucher number, minus last 5 digits, from the database and use the method in part B to quickly find the complete voucher number.

### D

Chances are Dave would get fired if he's discovered, although there doesn't seem to be any security measure to prevent it. He'd only be discovered if someone brings their voucher ands finds it's already been cashed already, coworkers notice receipts don't exist for those vouchers, or Dave submits a lot more receipts than usual.

### E

1. Only a few tellers are allowed to use wildcards, or a manager must authorize it when used.
2. The voucher itself, or a copy of it, must have the customer's signature and be physically saved if it's retrieved with a wildcard.

## 23

> 23. IPSec cookies are also known as anti-clogging tokens.
> a. What is the intended security purpose of IPSec cookies?
> b. Why do IPSec cookies fail to fulfill their intended purpose?
> c. Redesign the IPSec Phase 1 symmetric key signing main mode so that the IPSec cookies do serve their intended purpose.



## 25



## 27



## 37



## 43


