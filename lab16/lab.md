Lab 16
==============================

Today's lab explores the mining process used for the Bitcoin protocol.

Download `Miner.java` from the course website and implement the `findProof` method.  The method should

1. Add one extra coin to the miner's account in the ledger
2. Convert the new ledger to a String (`ledgeStr`)
3. Search for a "proof" where the result of `hash(ledgerStr + proof)` has `NUM_ZEROES` leading zeroes, similar to the hashcash protocol used for spam reduction in Chapter 5 of your textbook.

Submit your revised java code.
