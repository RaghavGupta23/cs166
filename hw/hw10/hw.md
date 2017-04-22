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

> IPSec cookies are also known as anti-clogging tokens.
> a. What is the intended security purpose of IPSec cookies?
> b. Why do IPSec cookies fail to fulfill their intended purpose?
> c. Redesign the IPSec Phase 1 symmetric key signing main mode so that the IPSec cookies do serve their intended purpose.

### A

The cookies `IC` and `RC` are supposed to mitigate DoS attacks. By reducing connection state the server has to keep track of.

### B

Server still has to keep track of all the messages transmitted in order to create `proofB`, including the cookies themselves, so state is still kept.

### C

It could remain exactly the same, except Alice would also send `E(time, Kab)` in the first message. This proves to Bob that he's talking with someone in possession of the key without revealing the key itself. It also prevents replay attacks, so if Trudy copies the first message to flood Bob in a DoS attack, Bob can figure out the timestamp is old and won't continue the connection.

## 25

> As noted in the text, IKE Phase 1 public key encryption aggressive mode allows Alice and Bob to remain anonymous. Since anonymity is usually given as the primary advantage of main mode over aggressive mode, is there any reason to ever use public key encryption main mode?

Main mode is a requirement, so you can assume another system has it implemented, versus aggressive mode which is optional.

## 27

> We say that Trudy is a passive attacker if she can only observe the messages sent between Alice and Bob. If Trudy is also able to insert, delete, or modify messages, we say that Trudy is an active attacker. If, in addition to being an active attacker, Trudy is able to establish a legitimate connection with Alice or Bob, then we say that Trudy is an insider. Consider **IKE Phase 1 digital signature main mode**.
> a. As a passive attacker, can Trudy determine Alice’s identity?
> b. As a passive attacker, can Trudy determine Bob’s identity?
> c. As an active attacker, can Trudy determine Alice’s identity?
> d. As an active attacker, can Trudy determine Bob’s identity?
> e. As an insider, can Trudy determine Alice’s identity?
> f. As an insider, can Trudy determine Bob’s identity?

### A & B

No, since key `K` is derived from DH key exchange. Therefore, passive attackers won't be able to get `g^(ab) mod p`, and won't be able to derive key `K`.

### C

Yes, Alice's identity can be leaked with an active attack. Trudy can MitM the DH exchange, get a valid K value, and decrypt the 5th message with Alice's identity.

### D

No, since following part C, the protocol prevents Trudy from sending Bob a valid response since she can't create a new proof. Bob will find the process has been tampered, and won't proceed.

### E & F

Yes, since Trudy was able to connect to Alice or Bob, Trudy must have been able to derive key `K`. Thus, she can decrypt the 5th and 6th messages, and retrieve Alice and Bob's identities.

## 37

> WEP is supposed to protect data sent over a wireless link. As discussed in the text, WEP has many security flaws, one of which involves its use of initialization vectors, or IVs. WEP **IVs are 24 bits long**. WEP uses a fixed long-term key K. For each packet, WEP sends an IV in the clear along with the encrypted packet, where the packet is encrypted with a stream cipher using the key `KIV = (IV, K)`, that is, the **IV is pre-pended to the long-term key K**. Suppose that a particular WEP connection sends packets containing **1500 bytes over an 11 Mbps link**.
> a. If the IVs are chosen at random, what is the expected amount of time until the first IV repeats? What is the expected amount of time until some IV repeats?
> b. If the IVs are not selected at random but are instead selected in sequence, say, `IVi = i, for i = 0, 1, 2, ..., 224 − 1`, what is the expected amount of time until the first IV repeats? What is the expected amount of time until some IV is repeated?
> c. Why is a repeated IV a security concern?
> d. Why is WEP “unsafe at any key length” [321]? That is, why is WEP no more secure if K is 256 bits than if K is 40 bits? Hint: See [112] for more information.

### A

Seconds for a packet
1500 bytes / 11 Mbps
= (1500 bytes * 8 bits/byte) / (11 Mbps * 1000 Mb/bit)
= 12000 bits / 11000 bits/s
= 12/11 seconds

IV repeated:
2^24 / 2
= 2^23

12/11 * 2^23
= **9151208.7 seconds, or 2542 hours**

Some IV repeated:
sqrt(2^24)
= 2^(24/2)
= 2^12

12/11 * 2^12
= **4468.4 seconds, or 1.24 hours**

### B

224 IVs are used in sequential order. Therefore, time for first IV to repeat is time for some IV to repeat. At one time, IV being used is assumed to be random, and on avg would be half IVs left before looping back.

12/11 * 224/2
= 12/11 * 112
= **112.2 seconds**

### C

A repeated IV means that the key that the exact same key was also used to encrypt the data. That means, similar to the problems with ECB, you could infer about the encrypted contents, such as when the same data is encrypted.

### D

WEP improperly deals with keys in the first place (repeating them stream cipher keys, for one). Thus, any key size is insecure, as key size is irrelevant to the WEP's insecurity.

## 43

> Give a secure one-message protocol that prevents cell phone cloning and establishes a shared encryption key. Mimic the GSM protocol.

The phone sends a single message to the BTS:

`IMSI, E(Kphone, Ki)`

`IMSI`: SIM card's identifier
`Kphone`: random shared key generated by the phone
`Ki`: SIM card's secret

The BTS forwards this to the home network to validate, checking if the IMSI is valid, then decrypting `Kphone` and forwarding it to the BTS. The BTS then uses it to communicate with the phone. Otherwise, connection is dropped.
