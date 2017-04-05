Lab 13: Attack a Simple Protocol
==============================

> Review the protocol at http://www.cs.sjsu.edu/~austin/cs166-spring17/labs/Protocol.pdf (Links to an external site.).  Determine 2 attacks against this protocol.
> 
> Submit your attacks and a modified version of the protocol that will avoid this attack.
> 
> For bonus fun, trade protocols with another group and try to break their revised protocol.

## Attacks

Note, R is nonce

1. Replay attack
2. Bob encrypts R for you. Send two connection requests, one with R and second with R+1. Bob sends you `E(R+1, K)`, used to complete the first connection.

## Fix it

- Start off encrypted, Bob can ignore anything that doesn't decrypt
- Bob sends his own challenge, along with Alice's nonce to prove his own identity
- Alice verifies her nonce is intact, encrypt and reply with Bob's challenge
