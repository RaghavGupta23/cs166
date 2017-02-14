Lab 05
==============================

## Part 1

### 1

> Are 8 and 9 relatively prime, why or why not?

**8 is relatively prime to 9** because 8 and 9 do not share any factors. However, 9 is not relatively prime to 8 because 9 is greater.

### 2

> What is the multiplicative inverse of 4 mod 13

**10**

### 3

> What is totient(15)

Factors of 15: 1 3 5 15
1, 2, 4, 7, 8, 10, 11, 13, 14
**totient is 9**

## Part 2

### 1

> Private key SIK = (3, 4, 9, 21, 45, 96, 199, 402), m = 32, n = 1215, calculate public key

```python
m = 32
n = 1215
sik = [3, 4, 9, 21, 45, 96, 199, 402]
gk = []
for num in sik:
    gk.append((m * num) % n)
```

GK, or public key, is **(96, 128, 288, 672, 225, 642, 293, 714), n = 1215**

### 2

> Encrypt `00101110`

0 + 0 + 288 + 0 + 225 + 642 + 293 = **1448**

### 3

> Decrypt answer above

m^-1 mod n = 32^-1 mod 1215 = 38

1448*38 mod 1215 = 349 mod 1215

Solving SIK with 349:
3, 4, 9, 21, 45, 96, 199, 402
      X       X   X    X
**00101110**

## Part 3

### 1

> p = 107, q = 293, e = 3, what is the public key?

PubKey = (N, e)
N = p * q = 107 * 293 = 31351
**(31351, 3)**

### 2

> Find private key d, where e * d = 1 mod (p-1)(q-1)

3 * d = 1 mod 106 * 293
= 1 mod 30952

```python
p = 107
q = 293
e = 3

pq = (p-1) * (q-1)
for x in range(0, 100):
    formula = pq * x + 1
    if formula % e == 0:
        print("x: {}, d: {}".format(x, formula / e))
        break
```

3 * 20635 = 61905, 61905 mod 30952 = 1
d = **20635**

### 3

> Encrypt message M = 42

C = M^e mod N
= 42^3 mod 31351
= 74088 mod 31351
= **11386**

### 4

> Decrypt ciphertext C

M = C^d mod N
= 11386^20635 mod 31351
= (very big number) mod 31351
= **42**

### 5

> If Trudy knows p, what other details can she determine?

Knowing p and having access to the public key, Trudy can derive q and can recreate the private key. She can basically determine anything at that point.
