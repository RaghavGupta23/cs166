Lab 08
==============================

Download `Cracker.java` and `passwords.txt` from http://www.cs.sjsu.edu/~austin/cs265-spring15/lab08 (Links to an external site.).  The file `passwords.txt` provides a list of common passwords.  `Cracker.java` uses this file, parses a file of usernames and hashes, and prints out any username/password combinations it identifies.

Note that `passwords.txt` is a large file.  You may need to provide additional memory for java, like so: `java -Xms512m -Xmx512m Cracker passwords.txt input.txt`

## Part 1)

> Try out this program on `input.txt` to see how it works.  What username/password combinations does it identify?

It finds 8/13 passwords:

```
The password for spaceghost is ben
The password for superman is loislane
The password for hulk is smash
The password for batman is rachel
The password for greenlantern is carrot88
The password for aquaman is fish
The password for ironman is dmg2good
The password for flash is speedy22
```

## Part 2)

> Modify this program to parse `inputSalted.txt`.  This file includes the salt values as well as the usernames and hash values.  The hashes were created by `md5hash(salt+password)`.
> 
> What username/password combinations does your modified program identify?  How much slower did it run?

It finds 9/13 passwords:

```
The password for ghostrider is harley1971
The password for superman is dmlt5203416533
The password for flash is speedy22
The password for ironman is pepperpot
The password for hulk is hulksmash
The password for greenlantern is 897lannister
The password for thor is midgard91!
The password for aquaman is fish
The password for wolverine is wolver1ne
```

It took 33 seconds compared to 7 seconds with part 1, almost 5 times longer.

## Part 3)

> Modify the program to account for a pepper value.  In this case, the **pepper** value is a number **between 1 and 10**.  The hashes were created by `md5hash(salt+pepper+password)`.
> 
> Again, what username/password combinations does your modified program identify?  And how much slower did this version run?  How much slower would it have been if the pepper value had been a random 40 digit hexadecimal number?

It finds 10/13 passwords:

```
Pepper found: 7
The password for silversurfer is wipeout1
The password for superman is wonderwoman4eva
The password for aquaman is fish
The password for wolverine is zoinks
The password for thor is password
The password for spiderman is blackspidey
The password for ironman is zombiefight
The password for hulk is allalone06
The password for ghostrider is cupcake
The password for spaceghost is 22space22
```

It took 47 seconds to run, or about a third longer than just salted passwords in part 2.

What if the pepper was a 40 digit random hex? It took about 20 seconds to find a pepper with a keyspace of 10, and 40 hex digits has 16^40 or 1461501637330902918203684832716283019655932542976 possibilities, so roughly 146150163733090291820368483271628301965593254297 seconds, or 4e40 years. That's not even considering if each user has a _unique_ pepper.