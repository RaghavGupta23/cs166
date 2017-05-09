Chapter 9
==============================

> Chp 9 problems: #1, 6, 7, 10, 16, 21, 22, 29, 30, 36, 38.
> 
> Each problem is worth 1 point.  Note that there are 11 problems, so you can earn one point of extra credit.

## 1

> Add hashing to protocol and remove symmetric key

Assuming that some secret K still exists between Alice and Bob, otherwise the messages can be fabricated:

```
Alice                       Bob
---- "I'm Alice", Ra        --->
<--- Rb, hash("Bob", K, Ra) ----
---- hash("Alice", K, Rb)   --->
```

## 6

> Timestamps as nonces
> A. Advantages
> B. Disadvantages

### A

**Makes protocol more simple and efficient** by reducing messages needed. Other party just needs to verify timestamp within acceptable timeframe.

### B

Increases attack space and complexity elsewhere, since acceptable timeframe used has to allow for inaccurate clocks, network delays, processing, etc. while not allowing enough time for attackers to exploit and send malicious messages. All parties involved have to have synchronized time, typically requiring Internet access for NTP.

## 7

> Protocol with constant `CLNT`, `SRVR`, session key `K = h(S, Ra, Rb)`
> A. Does Alice authenticate Bob?
> B. Bob authenticate Alice?

Assuming the certificate isn't validated by a third party, then **neither side authenticates**. Trudy can MitM and negotiate her own `R` values with Alice and Bob, and create her own cert to interact with Alice. Trudy would then have `S` and `R` values for the session key of both sides.

Alice's identity is proven with the `Ra` that she sends, which is used for session key `K`. Unfortunately this is sent in the clear and spoofable by anyone.

Bob's identity is proved by the certificate he sends, but Alice is trusting that it actually came from Bob, and isn't validating it with a TTP.

## 10

> Random challenge `R` sent in clear and secret symmetric key `K`. Are the following secure session keys?

If a secure session key means forward secrecy is maintained, then **none of them are secure** because a leaked `K` will allow an attacker to arrive at the same session key.

If a secure session key simply means it isn't revealed by `R`:

### A

Not secure, someone can XOR it with `R` to find `K`, and now has the secret `K`, and can XOR both together to get session key.

### B

Secure, need access to `K` to encrypt `R` into session key.

### C

Not secure, it can be decrypted by `R` to reveal `K`, and reencrypted to get the session key.

### D and E

Secure, hashing is one way and `K` needed to produce the same hash.

## 16

> For this protocol where Kab is a shared symmetric key, show Trudy can convince Bob that she's Alice. Modify to prevent this attack.

Trudy can use a **multiple session attack**. Send an initial connection request with `Ra`, and use the received `Rb` to open a second connection. Bob sends an encrypted `Rb`, which can be used to complete the initial connection request.

The `Ra` that Alice sends should be encrypted, and Bob includes `Rb` in the encrypted response sent.

## 21

> Consider mutual auth and key protocol provided. Trudy acts as Bob, and can guess `T` to within 5 minutes.
> A. Probability of sending correct response
> B. Modify protocol to mitigate attack

### A

That would depend on what window the protocol considers acceptable to account for time skew. The probability where `W` is the window in minutes is then `W/5`.

### B

First, the window can be shortened to reduce Trudy's chances. Second, Bob can sign as well as encrypt his response, so the second message is `{[T+1]Bob}Alice`.

## 22

> Consider the protocol, with session key `K = g^ab mod p`.
> A. Show how Trudy can let Alice and Bob authenticate while also knowing Alice's session key
> B. Is this attack of any use to Trudy

### A

Trudy would MitM the messages, allowing everything to pass through, but altering the DH exchange.

In message 2, receiving `{g^b mod p}Alice` from Bob, Trudy would open a new connection and send that as the `Rb` to Alice who would decrypt it for Trudy, and be used later. In the original connection, Trudy sends her own `{g^t mod p}Alice` to Alice.

In message 3, Trudy receives `{g^a mod p}Bob` from Alice. Trudy sends this as `Ra` in a new connection to Bob, who decrypts it for her. Trudy proceeds to send her own `{g^t mod p}Bob` to Bob.

Both Alice and Bob have authenticated, with Trudy masquerading as the opposite party. Trudy also knows the session key with each party.

### B

Yes, because Trudy can decrypt/encrypt messages being sent either way.

## 29

> Protocol with shared PIN, and `Kpin = h(PIN, Ra, Rb)`
> A. Trudy observes one iteration, can she determine the PIN number
> B. Would a 256 bit symmetric key secure the protocol?

### A

Yes, but only after brute forcing, although note the keyspace for a PIN number is very small. Trudy would generate `h(PIN, Ra, Rb)` for all possible PIN values and see if it decrypts any of the encrypted messages. If Alice or Bob show up in the result, Trudy knows the PIN was correct.

### B

Yes, because it addresses the issue in part A and prevents brute forcing.

## 30

> Protocol with shared PIN, and `Kpin = h(PIN)`. Trudy observes one iteration, can she determine the PIN number?

No, because `R` is encrypted with `Kpin`. Since Trudy doesn't know the `R` values, she won't know when her brute force succeeds.

## 36

> Fiat-Shamir with `N = 63` and `v = 43`.
> A. First iteration, Alice sends `x = 37`, Bob sends `e = 1`, Alice sends `y = 4`. Does Bob accept?
> B. Second iteration, Alice sends `x = 37`, Bob sends `e = 0`, Alice sends `y = 10`. Does Bob accept?
> C. Find Alice's secret S.

### A

N = 63
v = 43 = S^2 mod N

-- 37 = x = r^2 mod 63 ->
<- 1 = e               --
-- 4 = y = rS^1 mod 63 ->

Bob:
y^2 = xv^e mod N
4^2 = 37 * 43 mod 63
16 = 1591 mod 63
16 = 16

**Yes**, Bob accepts this iteration.

### B

-- 37 = x = r^2 mod 63  ->
<- 0 = e                --
-- 10 = y = rS^0 mod 63 ->

Bob:
y^2 = xv^e mod N
10^2 = 37 * 43^0 mod 63
100 = 37 mod 63
100 != 37

**No**, Bob doesn't accept this iteration.

### C

43 = S^2 mod 63
4 = rS^1 mod 63
y^2 = xv^e mod 63
37 = r^2 mod 63

```python
possibleS = []
possibler = []
for x in range(1,100):
    if (x**2 % 63) == 43:
        possibleS.append(x)

for x in range(1,100):
    if (x**2 % 63) == 37 and x % 63 == 10:
        possibler.append(x)

for S in possibleS:
    for r in possibler:
        if r*S % 63 == 4:
            print("S: {}, r: {}".format(S, r))
```

Without `r` you can get a few possible `S` values.

S: 13, r: 10
S: 13, r: 73
S: 76, r: 10
S: 76, r: 73

It seems likely to be 13.

## 38

> Fiat Shamir with `N = 55` and `S = 9`
> A. What is v?
> B. If `r = 10`, what's Alice's first message?
> C. Bob sends `e = 0`, what's Alice's reply?
> D. `e = 1` in message 2, what's Alice's reply?

### A

9^2 mod 55 = **26**

### B

r^2 mod N = **45**

### C

r mod N = **10**

### D

rS mod N = **35**
