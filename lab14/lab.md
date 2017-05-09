Lab 14
==============================

> Attack IKE Anonymity for Digital Signature Main Mode.
> 
> IKE using digital signatures is supposed to provide anonymity in main mode.  However, it is only effective against passive attacks, where Trudy just records the details of the attack.
> 
> Pretend that you are Trudy and you want to determine Alice's identity.  Describe your attack. Submit the step-by-step details of the attack.

## Answer

Trudy can MitM the DH process to obtain the identity of Alice, although the process breaks down beyond that.

To do this, simply MitM the first few messages (notably the key exchange). Since the other values, such as IC, RC, nonces, are also intercepted, Trudy can derive the K value and decrypt the message containing Alice's identity. But this is the extent of the attack since the included proof contains the key exchange messages, and is signed by Alice. The proof Trudy sends to Bob will reveal either a forged signature, or a tampered key exchange.

## Reference

| Msg # | Direction    |  Contents                          |
| ----- | ------------ | ---------------------------------- |
| 1     | Alice -> Bob | IC, CP                             |
| 2     | Alice <- Bob | IC, RC, CS                         |
| 3     | Alice -> Bob | IC, RC, **g^a mod p**, Ra          |
| 4     | Alice <- Bob | IC, RC, **g^b mod p**, Rb          |
| 5     | Alice -> Bob | IC, RC, E("Alice", **proofA** , K) |
| 6     | Alice <- Bob | IC, RC, E("Bob", proofB , K)       |

CP = crypto proposed
CS = crypto selected
IC = initiator "cookie"
RC = responder "cookie"
K = h(IC, RC, **g^(ab) mod p**, Ra, Rb)
SKEYID = h(Ra, Rb, g^(ab) mod p)
**proofA** = [h(SKEYID, **g^a mod p**, **g^b mod p**, IC, RC, CP, "Alice")]Alice
