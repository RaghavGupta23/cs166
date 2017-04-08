Lab 13: Attack a Simple Protocol
==============================

> Review the protocol at http://www.cs.sjsu.edu/~austin/cs166-spring17/labs/Protocol.pdf (Links to an external site.).  Determine 2 attacks against this protocol.
> 
> Submit your attacks and a modified version of the protocol that will avoid this attack.
> 
> For bonus fun, trade protocols with another group and try to break their revised protocol.

## Attacks

1. Replay attack: same message sent, no extra entropy.
2. Multiple session attack: Bob encrypts R for you. Send two connection requests, one with R and second with R+1. Bob sends you `E(R+1, K)`, use it to complete the first connection.

## Fix it

- Since K is known beforehand, start off encrypted. Also, Bob can ignore anything that doesn't decrypt.
- Bob's reply should include his own challenge
- Alice sends back Bob's challenge instead
