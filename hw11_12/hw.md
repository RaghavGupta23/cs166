Chapter 11 & 12
==============================

> From chapter 11, do problems 15, 18, 22, 29, 36.
> From chapter 12, do problems 2, 17, 26.
> 
> Additionally:
> Q1) Describe 3 defenses against buffer overflow attacks.
> Q2) Describe the difference between a reflected and a stored XSS attack.
> 
> Each problem is worth one point.

## Chapter 11

### 15

> In addition to stack-based buffer overflow attacks (i.e., smashing the stack), heap overflows can also be exploited. Consider the following C code, which illustrates a heap overflow.

```c
int main() {
    int diff, size = 8;
    char *buf1, *buf2;
    buf1 = (char *)malloc(size);
    buf2 = (char *)malloc(size);
    diff = buf2 - buf1;
    memset(buf2, '2', size);
    printf("BEFORE: buf2 = %s\n", buf2);
    memset(buf1, '1', diff+3);
    printf("AFTER: buf2 = %s\n", buf2);
    return 0;
}
```

> a. Compile and execute this program. What is printed?
> b. Explain the results you obtained in part a.
> c. Explain how a heap overflow might be exploited by Trudy.

#### A

It prints out the following:

```
BEFORE: buf2 = 22222222
AFTER: buf2 = 11122222
```

#### B

when `memset(buf1, '1', diff+3);` is called, `buf1` is overwritten to the start of `buf2` plus 3 characters. Therefore, the first 3 characters of `buf2` have 1 written over it.

#### C

Trudy can overwrite and tamper application data, instead of just changing the execution flow in the case of stack smashing.

### 18

> Consider the following protocol for adding money to a debit card.
> (i) User inserts debit card into debit card machine.
> (ii) Debit card machine determines current value of card (in dollars), which is stored in variable x.
> (iii) User inserts dollars into debit card machine and the value of the inserted dollars is stored in variable y.
> (iv) User presses enter button on debit card machine.
> (v) Debit card machine writes value of x + y dollars to debit card and ejects card.
> Recall the discussion of race conditions in the text. This particular protocol has a race condition.
> a. What is the race condition in this protocol?
> b. Describe a possible attack that exploits the race condition.
> c. How could you change the protocol to eliminate the race condition, or at least make it more difficult to exploit?

#### A

Values `X` and `Y` are are stored after reading them, and written after user presses the button. The `X` or `Y` values can change.

#### B

Assuming the ATM is secure and variables can't be changed directly, Trudy can try removing the card after reading and replace with a lower value card. Or, if she has a duplicate debit card (legitimate or not), she can withdraw funds in another ATM while the original one hasn't updated it.

#### C

Read the `X` value, money in the account, only when user presses enter to commit the transaction.

### 22

> Virus writers use encryption, polymorphism, and metamorphism to evade signature detection.
> a. What are the significant differences between encrypted worms and polymorphic worms?
> b. What are the significant differences between polymorphic worms and metamorphic worms?

#### A

Encrypted worms simply have an encrypted payload, and unencrypted portion that decrypts the payload. Polymorphic worms are essentially encrypted worms, but the decrypting portion is obfuscated with equivalent but convoluted code, dead code, jumps, and the like which make it harder for reverse engineering and signature detection to work against it.

#### B

Polymorphic worms are metamorphic worms that can change their own code before infecting a new system.

### 29

> In contrast to a flash worm, a slow worm is designed to slowly spread its infection while remaining undetected. Then, at a preset time, all of the slow worms could emerge and do something malicious. The net effect would be similar to that of a flash worm.
> a. Discuss one weakness (from Trudy's perspective) of a slow worm as compared with a flash worm.
> b. Discuss one weakness (also from Trudy's perspective) of a flash worm compared with a slow worm.

#### A

The slow worm takes no other measures to stay undetected, other than slow propagation. However, that might not be the determining factor in Trudy's worm being discovered or not.

#### B

The worm's speed might be so extreme that it noticeably affects system resources (similar to SQL Slammer), leading to it being discovered.

### 36

> Consider the code in Table 11.5, which is susceptible to a linearization attack. Suppose that we modify the program as follows:

```c
int main(int argc, const char *argv[]) {
    int i;
    bool flag = true;
    char serial[9] = "S123N456\n";
    if(strlen(argv[1]) < 8) {
        printf("\nError try again.\n\n");
        exit(0);
    }
    for(i = 0; i < 8; ++i) {
        if(argv[1][i] != serial[i]) flag = false;
    }
    if(flag) {
        printf("\nSerial number is correct!\n\n");
    }
}
```

> Note that we never break out of the for loop early, yet we can still determine whether the correct serial number was entered. Explain why this modified version of the program is still susceptible to a linearization attack.

There are two faults. An attacker can figure out the serial length from the first `if` statement since it directly checks length and exits on error. Also, each wrong character sets `flag` to false, which takes longer than skipping it.

## Chapter 12

### 2

> For the SRE example in Section 12.2.2, we patched the code by changing a test instruction to xor.
> a. Give at least two ways—other than changing test to xor -that Trudy could patch the code so that any serial number will work.
> b. Changing the `jz` instruction that appears at address 0×401032 in Figure 12.4 to jnz is not a correct solution to part a. Why not?

#### A

Trudy can subtract the `ax` register by itself. Since destination can't be immediate, `sub 1, 1` won't work, but `sub ax, ax` is an alternative. Additionally, the subsequent `jz` instruction can be unconditional jump `jmp`.

#### B

With `jnz`, incorrect serials will work, but the correct serial number will be interpreted as incorrect. Therefore, not any serial number will work.

### 17

> Consider a DRM system implemented in software on a PC.
> a. Define persistent protection.
> b. Why is encryption necessary, but not sufficient, to provide persistent protection?

#### A

Persistent protection is the whole idea beyond DRM: maintaining control over the product after it's been distributed to the customer. In this case, the software controls the user's access to the product.

#### B

Encryption fulfills persistent protection to some degree by requiring the customer to have the key to decrypt the software/product. But therefore it's insufficient because Trudy can obtain the key and remove the DRM restrictions.

### 26

> Suppose that a particular system has 1,000,000 bugs, each with MTBF of 10,000,000 hours. The good guys work for 10,000 hours and find 1,000 bugs.
> a. If Trudy works for 10 hours and finds 1 bug, what is the probability that Trudy's bug was not found by the good guys?
> b. If Trudy works for 30 hours and finds 3 bugs, what is the probability that at least one of her bugs was not found by the good guys?

#### A

10^6 total bugs
10^7 MTBF
10^4 testing time
10^3 bugs found

bugs found / total bugs = % bugs found
= 10^3 / 10^6
= 1 / 10^3
= 0.1%

1 - 0.1%
= **99.9%**

#### B

99.9% ^ 3
= **99.7%**

## Additional Problems

### 1

> Describe 3 defenses against buffer overflow attacks.

Developers can use safe functions that limit the amount of data that can be written, i.e. functions like `snprintf`. Stack can also be marked non executable to prevent data on stack from being interpreted as code. Canaries can also be used to detect data being overwritten and safely exit.

### 2

> Describe the difference between a reflected and a stored XSS attack.

Reflected XSS has the malicious script in the request itself, and is runs on the resulting web page that's served back to the user. For stored XSS, the script is stored onto the server itself, which is then sent to users.
