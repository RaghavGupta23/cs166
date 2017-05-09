> Suppose we use encrypt using the following formula:
> 
> `Ci = Pi xor E(K, IV+i)  where i is the block number`
> 
> Is this secure? Why or why not?
> 
> If so, how does this relate to CTR mode?
> 
> If not, what type of attacks would be a concern?

Yes, it is secure, since this formula is the same as CTR assuming the order of parameters is irrelevant.

However, it would be vulnerable to frequency analysis within each ciphertext block. Or, if some plaintext is known, E(K, IV+i) can be found, and since IV is known, that will hint towards what K is.
