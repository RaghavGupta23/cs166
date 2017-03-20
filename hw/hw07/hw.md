Homework 7
==============================

> Do the following problems from Chapter 7: 5-7, 9, 11, 12, 13, 15, 29, 37.

## 5

> System with 512 (2^9) passwords, 10 chars in length, and hashed. Write pseudocode for attacking when Trudy has 2^20 common passwords.
> A. Hashed without salt
> B. Hashed and salted

### A

```
for pass in commonpasswords
    if len(pass) == 10
        h = hash(pass)
        for hashedpass in passworddb
            if h == hashedpass
                print(hashedpass is pass)
```

### B

```
for entry in passworddb
    hashedsaltedpass = entry['pass']
    salt = entry['salt']
    for pass in commonpasswords
        if len(pass) < 10 and hash(pass + salt) == hashedsaltedpass
            print(hashedsaltedpass is pass with salt)
```

## 6

> Storing passwords in a file
> A. Why hash passwords
> B. Why hash versus encrypt
> C. What is a salt and why salt a password

### A

Whoever or whatever is handling the passwords can't tell what the actual password is, maintaining the owner's confidentiality. The password can still be verified when a user logs in by hashing the input and comparing with the password hash in the file.

### B

Encrypting allows the original password to be retrieved by whoever has the key, meaning the owner of the system could also retrieve the password. Plus, to check if a user's password is valid, the key must be somewhere on the system. Therefore when a breach occurs, the key to decrypt the passwords is potentially leaked too.

### C

A salt is non secret data added to the password when it's hashed, in order to prevent rainbow table attacks. Otherwise, large databases of pre hashed common passwords could be used to crack the passwords. Now an attacker has to recompute the entire password dictionary according to the salt for each password.

## 7

> File with 2^10 password hashes, passwords are 8 chars, 128 choices per char. Trudy has dictionary with 2^30 passwords, 1/4 chance a random password is in her dictionary.
> A. Expected work for Alice's password using dictionary
> B. Again, but assuming passwords are salted
> C. Probability at least one password is in the dictionary

### A

password key space
= 128^8
= 2^7^8
= 2^56

dictionary compute time + brute force time
= 1/4 (2^30 / 2) + 3/4 (2^56 / 2)
= 1/4 (2^29) + 3/4 (2^55)
= **~2.7e16**

### B

It would be the same because Trudy's dictionary is plaintext and has to be hashed anyways. The salt would be added to the potential password and hashed, the rest of the process proceeds as usual.

**~2.7e16**

### C

With 1/4 probability and Trudy having well over 4 passwords, she's guaranteed to have at least one password in her dictionary. More formally:

1 - (1 - 1/4) ^ (2^30)
= **1** probability there exists a password in her dictionary

## 9

> Most people can't accurately associate photos with individuals
> A. Requiring photos on credit cards dramatically reduces fraud. Why the contradiction?
> B. Checking photo brought onto a screen instead of printed onto card

### A

It acts as a deterrence to prevent most cases of fraud form occurring, similar to watermark on currency.

### B

The attendant is slightly more likely to identify fraud, because the picture is on a screen in front of them instead of on a card being flashed by someone. More detail and attention can be made when they check.

A slight benefit would be that, if the card is stolen, the thief would not have a picture associated with the name. Confidentiality for the cardholder's face would not be compromised.

## 11

> Crypto hash algorithm `h`. Password with max 14 chars, 32 choices per char, padded to 14 with null, `P` resulting password. Password hashing schemes:
> i. `P` split in `X` first 7 char and `Y` last 7 char, password stored as `h(X), h(Y)`, no salt
> ii. Password stored as `h(P)`, no salt
> A. How much easier is cracking i vs ii by brute forcing
> B. Why would a 10 char password be less secure than 7 char

### A

It'd be significantly easier since the password is essentially half length, becoming 2 * 7^32 for scheme ii, versus 14^32 with scheme i. That's 2.2e27 versus 4.7e36.

### B

The attacker only has to attack the second half, the hash of the 3 characters, in order to find part of the original password. With common password schemes, this hint can be very revealing, and takes relatively little computational power: 3^32, or 1.8e15 hashes.

## 12

> Passwords with max 16 chars, 128 choices per char, padded/truncated to 16. Then split, hashed, and salted.
> A. How are results used to verify entered password
> B. Expected work for brute forcing one password
> C. What shortcut exists

### A

An entered password would go through the same process of being padded or truncated, split, salted, and hashed. The result is compared with `Y0` and `Y1` to verify the password.

### B

16^128 / 2
= 2^4^128 / 2
= **2^511**

### C

Like with #11, the second half can be brute forced fairly quickly and hint towards the rest of the password.

## 13

> Plain text password returned to you from website
> A. Security concerns
> B. Does the website salt and hash passwords

### A

First, the website stores the password insecurely. If the database is leaked, your password would be immediately available for attackers to use. Second, someone may spoof your identity and have the website send them your password, either online or through some customer support phone number.

### B

Impossible, since hashing is one way and the website wouldn't be able to retrieve the original password. They might be using a salt, but it would do nothing for security.

## 15

> Password generator in picture. Is it secure if...
> A. R is repeated
> B. R is predictable

### A

It would not be secure because `h(K,R)` can be captured and used in a replay attack.

### B

Mostly, since `K` is still secret, but in this case `R` cannot be trusted. Alice will need to verify the identity of Bob without using `R`.

## 29

> For biometrics, define:
> A. Fraud rate
> B. Insult rate
> C. Equal error rate

### A

Fraud rate is how often another person can pose as someone in the system and be misidentified as that someone.

### B

Insult rate is how often someone in the system is not identified as themselves.

### C

Equal error rate is where the fraud and insult rates are equal. Since lower fraud increases insult and vice versa, it's useful for comparing the accuracy of different biometric identification methods.

## 37

> Iris scan with 64 bit iris codes
> 
> | User    | Iris code        |
> | ------- | ---------------- |
> | Alice   | BE439AD598EF5147 |
> | Bob     | 9C8B7A1425369584 |
> | Charlie | 885522336699CCBB |
> | U       | C975A2132E89CEAF |
> | V       | DB9A8675342FEC15 |
> | W       | A6039AD5F8CFD965 |
> | X       | 1DCA7A54273497CC |
> | Y       | AF8B6C7D5E3F0F9A |
> 
> `d(x,y) = different bits / total bits`
> 
> A. Compute the distances d(Alice,Bob), d(Alice,Charlie), d(Bob,Charlie)
> B. Which users are most likely Alice, Bob, and Charlie?

### A

Refer to Python program.

d(Alice, Bob)     = 29
d(Alice, Charlie) = 39
d(Bob, Charlie)   = 34

### B

Refer to Python program.

Assuming ~10 is within acceptable bounds, it seems like:

Alice is W
Bob is X
Charlie is U
